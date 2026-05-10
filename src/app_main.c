#include "tl_common.h"
#include "zcl_include.h"
#include "ota.h"

#include "app_main.h"

static bool boot_announce_sent = false;

app_ctx_t g_appCtx = {
        .bdbFBTimerEvt = NULL,
        .timerForcedReportEvt = NULL,
        .timerCheckSleepEvt = NULL,
        .timerSetPollRateEvt = NULL,
        .timerOnOffRepeatEvt = NULL,
        .oriSta = false,
        .net_steer_start = false,
        .not_sleep = true,
        .ota = false,
        .battery_read = 0,
        .led_ota = 0,
};

//uint32_t count_restart = 0;

#ifdef ZCL_OTA
extern ota_callBack_t app_otaCb;

//running code firmware information
ota_preamble_t app_otaInfo = {
    .fileVer            = FILE_VERSION,
    .imageType          = IMAGE_TYPE,
    .manufacturerCode   = MANUFACTURER_CODE_TELINK,
};
#endif


//Must declare the application call back function which used by ZDO layer
const zdo_appIndCb_t appCbLst = {
    bdb_zdoStartDevCnf,//start device cnf cb
    NULL,//reset cnf cb
    NULL,//device announce indication cb
    app_leaveIndHandler,//leave ind cb
    app_leaveCnfHandler,//leave cnf cb
    NULL,//nwk update ind cb
    NULL,//permit join ind cb
    NULL,//nlme sync cnf cb
    NULL,//tc join ind cb
    NULL,//tc detects that the frame counter is near limit
};


/**
 *  @brief Definition for BDB finding and binding cluster
 */
uint16_t bdb_findBindClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF,
};

/**
 *  @brief Definition for BDB finding and binding cluster number
 */
#define FIND_AND_BIND_CLUSTER_NUM       (sizeof(bdb_findBindClusterList)/sizeof(bdb_findBindClusterList[0]))

/**
 *  @brief Definition for bdb commissioning setting
 */
bdb_commissionSetting_t g_bdbCommissionSetting = {
    .linkKey.tcLinkKey.keyType = SS_GLOBAL_LINK_KEY,
    .linkKey.tcLinkKey.key = (uint8_t *)tcLinkKeyCentralDefault,             //can use unique link key stored in NV

    .linkKey.distributeLinkKey.keyType = MASTER_KEY,
    .linkKey.distributeLinkKey.key = (uint8_t *)linkKeyDistributedMaster,    //use linkKeyDistributedCertification before testing

    .linkKey.touchLinkKey.keyType = MASTER_KEY,
    .linkKey.touchLinkKey.key = (uint8_t *)touchLinkKeyMaster,               //use touchLinkKeyCertification before testing

#if TOUCHLINK_SUPPORT
    .touchlinkEnable = 1,                                               /* enable touch-link */
#else
    .touchlinkEnable = 0,                                               /* disable touch-link */
#endif
    .touchlinkChannel = DEFAULT_CHANNEL,                                /* touch-link default operation channel for target */
    .touchlinkLqiThreshold = 0xA0,                                      /* threshold for touch-link scan req/resp command */
};

/**********************************************************************
 * LOCAL VARIABLES
 */


/**********************************************************************
 * FUNCTIONS
 */

static void afApsAckCb(void *args) {

    apsdeDataConf_t *pApsDataCnf = (apsdeDataConf_t *)args;
    repeat_cmd_t *r_cmd = app_find_repeat_cmd(pApsDataCnf->clusterId,
                                              pApsDataCnf->srcEndpoint,
                                              pApsDataCnf->dstEndpoint,
                                              pApsDataCnf->dstAddrMode,
                                              (tl_zb_addr_t*)&pApsDataCnf->dstAddr);
#if UART_PRINTF_MODE
    APP_DEBUG(DEBUG_REPEAT_EN, "afApsAckCb() - status: 0x%02x, clId: 0x%04x, src_ep: %d, dst_ep: %d, ",
            pApsDataCnf->status, pApsDataCnf->clusterId, pApsDataCnf->srcEndpoint, pApsDataCnf->dstEndpoint);
    if (pApsDataCnf->dstAddrMode == APS_SHORT_GROUPADDR_NOEP) {
        APP_DEBUG(DEBUG_REPEAT_EN, "short_addr: 0x%04x, ", pApsDataCnf->dstAddr.addr_short);
    } else {
        APP_DEBUG(DEBUG_REPEAT_EN, "ieee: 0x%02x%02x%02x%02x%02x%02x%02x%02x, ",
                pApsDataCnf->dstAddr.addr_long[0], pApsDataCnf->dstAddr.addr_long[1],
                pApsDataCnf->dstAddr.addr_long[2], pApsDataCnf->dstAddr.addr_long[3],
                pApsDataCnf->dstAddr.addr_long[4], pApsDataCnf->dstAddr.addr_long[5],
                pApsDataCnf->dstAddr.addr_long[6], pApsDataCnf->dstAddr.addr_long[7]);
    }
    APP_DEBUG(DEBUG_REPEAT_EN, "r_cmd: %s\r\n", r_cmd?"true":"false");
#endif

    if (r_cmd) {
        if (pApsDataCnf->status != APS_STATUS_SUCCESS) {
            if (pApsDataCnf->dstAddrMode != APS_SHORT_GROUPADDR_NOEP) {
                switch(pApsDataCnf->clusterId) {
                    case ZCL_CLUSTER_GEN_ON_OFF:
                        app_repeatCmdOnOff(r_cmd);
//                        TL_ZB_TIMER_SCHEDULE(app_repeatCmdOnOff, r_cmd, TIMEOUT_250MS);
                        break;
                    case ZCL_CLUSTER_GEN_LEVEL_CONTROL:
                        app_repeatCmdLevel(r_cmd);
//                        TL_ZB_TIMER_SCHEDULE(app_repeatCmdLevel, r_cmd, TIMEOUT_250MS);
                        break;
                    case ZCL_CLUSTER_GEN_SCENES:
                        app_repeatCmdScene(r_cmd);
//                        TL_ZB_TIMER_SCHEDULE(app_repeatCmdScene, r_cmd, TIMEOUT_250MS);
                        break;
                    case ZCL_CLUSTER_LIGHTING_COLOR_CONTROL:
                        app_repeatCmdColorCtrl(r_cmd);
//                        TL_ZB_TIMER_SCHEDULE(app_repeatCmdColorCtrl, r_cmd, TIMEOUT_250MS);
                        break;
                    default:
                        break;
                }
            }
        }
        r_cmd->used = false;
        if (repeat_cmd_num > 0) repeat_cmd_num--;
//    } else {
//        if (pApsDataCnf->status == APS_STATUS_SUCCESS && app_getTimeoutPollRate() < TIMEOUT_30SEC) app_setPollRate(TIMEOUT_30SEC, 1);
    }
    if (repeat_cmd_num == 0) clearButtonSleepTimer();
}

/*********************************************************************
 * @fn      stack_init
 *
 * @brief   This function initialize the ZigBee stack and related profile. If HA/ZLL profile is
 *          enabled in this application, related cluster should be registered here.
 *
 * @param   None
 *
 * @return  None
 */
void stack_init(void)
{
    /* Initialize ZB stack */
    zb_init();

    /* Register stack CB */
    zb_zdoCbRegister((zdo_appIndCb_t *)&appCbLst);
}

/*********************************************************************
 * @fn      user_app_init
 *
 * @brief   This function initialize the application(Endpoint) information for this node.
 *
 * @param   None
 *
 * @return  None
 */
void user_app_init(void)
{

#if ZCL_POLL_CTRL_SUPPORT
    af_powerDescPowerModeUpdate(POWER_MODE_RECEIVER_COMES_PERIODICALLY);
#else
    af_powerDescPowerModeUpdate(POWER_MODE_RECEIVER_COMES_WHEN_STIMULATED);
#endif

    /* Initialize ZCL layer */
    /* Register Incoming ZCL Foundation command/response messages */
    zcl_init(app_zclProcessIncomingMsg);

    /* register endPoint */
    af_endpointRegister(APP_ENDPOINT1, (af_simple_descriptor_t *)&app_ep1Desc, zcl_rx_handler, afApsAckCb);
    af_endpointRegister(APP_ENDPOINT2, (af_simple_descriptor_t *)&app_ep2Desc, zcl_rx_handler, afApsAckCb);
    af_endpointRegister(APP_ENDPOINT3, (af_simple_descriptor_t *)&app_ep3Desc, zcl_rx_handler, afApsAckCb);
    af_endpointRegister(APP_ENDPOINT4, (af_simple_descriptor_t *)&app_ep4Desc, zcl_rx_handler, afApsAckCb);
    af_endpointRegister(APP_ENDPOINT5, (af_simple_descriptor_t *)&app_ep5Desc, zcl_rx_handler, afApsAckCb);
    af_endpointRegister(APP_ENDPOINT6, (af_simple_descriptor_t *)&app_ep6Desc, zcl_rx_handler, afApsAckCb);
    af_endpointRegister(APP_ENDPOINT7, (af_simple_descriptor_t *)&app_ep7Desc, zcl_rx_handler, afApsAckCb);
    af_endpointRegister(APP_ENDPOINT8, (af_simple_descriptor_t *)&app_ep8Desc, zcl_rx_handler, afApsAckCb);
    if (device_model == DEVICE_BUTTON_12 || device_model == DEVICE_BUTTON_20) {
        af_endpointRegister(APP_ENDPOINT9, (af_simple_descriptor_t *)&app_ep9Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT10, (af_simple_descriptor_t *)&app_ep10Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT11, (af_simple_descriptor_t *)&app_ep11Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT12, (af_simple_descriptor_t *)&app_ep12Desc, zcl_rx_handler, afApsAckCb);
    }
    if (device_model == DEVICE_BUTTON_20) {
        af_endpointRegister(APP_ENDPOINT13, (af_simple_descriptor_t *)&app_ep13Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT14, (af_simple_descriptor_t *)&app_ep14Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT15, (af_simple_descriptor_t *)&app_ep15Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT16, (af_simple_descriptor_t *)&app_ep16Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT17, (af_simple_descriptor_t *)&app_ep17Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT18, (af_simple_descriptor_t *)&app_ep18Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT19, (af_simple_descriptor_t *)&app_ep19Desc, zcl_rx_handler, afApsAckCb);
        af_endpointRegister(APP_ENDPOINT20, (af_simple_descriptor_t *)&app_ep20Desc, zcl_rx_handler, afApsAckCb);
    }

    zcl_reportingTabInit();
    device_settings_restore();

    /* Register ZCL specific cluster information */
    zcl_register(APP_ENDPOINT1, APP_EP1_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp1ClusterList);
    zcl_register(APP_ENDPOINT2, APP_EP2_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp2ClusterList);
    zcl_register(APP_ENDPOINT3, APP_EP3_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp3ClusterList);
    zcl_register(APP_ENDPOINT4, APP_EP4_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp4ClusterList);
    zcl_register(APP_ENDPOINT5, APP_EP5_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp5ClusterList);
    zcl_register(APP_ENDPOINT6, APP_EP6_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp6ClusterList);
    zcl_register(APP_ENDPOINT7, APP_EP7_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp7ClusterList);
    zcl_register(APP_ENDPOINT8, APP_EP8_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp8ClusterList);
    if (device_model == DEVICE_BUTTON_12 || device_model == DEVICE_BUTTON_20) {
        zcl_register(APP_ENDPOINT9, APP_EP9_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp9ClusterList);
        zcl_register(APP_ENDPOINT10, APP_EP10_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp10ClusterList);
        zcl_register(APP_ENDPOINT11, APP_EP11_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp11ClusterList);
        zcl_register(APP_ENDPOINT12, APP_EP12_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp12ClusterList);
    }
    if (device_model == DEVICE_BUTTON_20) {
        zcl_register(APP_ENDPOINT13, APP_EP13_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp13ClusterList);
        zcl_register(APP_ENDPOINT14, APP_EP14_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp14ClusterList);
        zcl_register(APP_ENDPOINT15, APP_EP15_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp15ClusterList);
        zcl_register(APP_ENDPOINT16, APP_EP16_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp16ClusterList);
        zcl_register(APP_ENDPOINT17, APP_EP17_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp17ClusterList);
        zcl_register(APP_ENDPOINT18, APP_EP18_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp18ClusterList);
        zcl_register(APP_ENDPOINT19, APP_EP19_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp19ClusterList);
        zcl_register(APP_ENDPOINT20, APP_EP20_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appEp20ClusterList);
    }

#if ZCL_OTA_SUPPORT
    ota_init(OTA_TYPE_CLIENT, (af_simple_descriptor_t *)&app_ep1Desc, &app_otaInfo, &app_otaCb);
#endif

    batteryCb(NULL);

#if DEBUG_BATTERY_EN
    g_appCtx.timerBatteryEvt = TL_ZB_TIMER_SCHEDULE(batteryCb, NULL, TIMEOUT_1MIN);
#else
    g_appCtx.timerBatteryEvt = TL_ZB_TIMER_SCHEDULE(batteryCb, NULL, BATTERY_TIMER_INTERVAL);
#endif

}

void app_task(void) {

    if (!boot_announce_sent && zb_isDeviceJoinedNwk()) {
        zb_zdoSendDevAnnance();
        boot_announce_sent = true;
    }

    button_handler();

    if(bdb_isIdle()) {
//        report_handler();
#if PM_ENABLE
        button_handler();
        if(!button_idle() && !factory_reset) {
//            printf("test\r\n");
            app_lowPowerEnter();
        }
#endif
    }
}

extern volatile uint16_t T_evtExcept[4];

static void appSysException(void) {

    APP_DEBUG(UART_PRINTF_MODE, "app_sysException, line: %d, event: 0x%02x, reset\r\n", T_evtExcept[0], T_evtExcept[1]);

#if 1
    SYSTEM_RESET();
#else
    led_on(LED_STATUS);
    while(1);
#endif
}

/*********************************************************************
 * @fn      user_init
 *
 * @brief   User level initialization code.
 *
 * @param   isRetention - if it is waking up with ram retention.
 *
 * @return  None
 */
void user_init(bool isRetention) {

    /* Initialize LEDs*/
    light_init();

#if PA_ENABLE
    rf_paInit(PA_TX, PA_RX);
#endif

#if ZBHCI_EN
    zbhciInit();
#endif

#if PM_ENABLE
    app_wakeupPinConfig();
#endif

    if(!isRetention) {

        device_model_restore();

        start_message();

        /* Initialize Stack */
        stack_init();

        /* Initialize user application */
        user_app_init();

        /* Register except handler for test */
        sys_exceptHandlerRegister(appSysException);

        /* User's Task */
#if ZBHCI_EN
        ev_on_poll(EV_POLL_HCI, zbhciTask);
#endif
        ev_on_poll(EV_POLL_IDLE, app_task);

        /* Load the pre-install code from flash */
        if(bdb_preInstallCodeLoad(&g_appCtx.tcLinkKey.keyType, g_appCtx.tcLinkKey.key) == RET_OK){
            g_bdbCommissionSetting.linkKey.tcLinkKey.keyType = g_appCtx.tcLinkKey.keyType;
            g_bdbCommissionSetting.linkKey.tcLinkKey.key = g_appCtx.tcLinkKey.key;
        }

        bdb_findBindMatchClusterSet(FIND_AND_BIND_CLUSTER_NUM, bdb_findBindClusterList);

        /* Set default reporting configuration */
        uint8_t reportableChange = 0x00;
        bdb_defaultReportingCfg(APP_ENDPOINT1, HA_PROFILE_ID, ZCL_CLUSTER_GEN_POWER_CFG,
                                ZCL_ATTRID_BATTERY_PERCENTAGE_REMAINING, REPORTING_BATTERY_MIN,
                                REPORTING_BATTERY_MAX, (uint8_t *)&reportableChange);

        /* Initialize BDB */
        uint8_t repower = drv_pm_deepSleep_flag_get() ? 0 : 1;
        bdb_init((af_simple_descriptor_t *)&app_ep1Desc, &g_bdbCommissionSetting, &g_zbBdbCb, repower);


    }else{
        /* Re-config phy when system recovery from deep sleep with retention */
        mac_phyReconfig();
    }

    ZB_RADIO_TX_POWER_SET(ZB_APP_TX_POWER_IDX);
}

