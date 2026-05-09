#include "app_main.h"

#ifndef ZCL_BASIC_MFG_NAME
#define ZCL_BASIC_MFG_NAME          {6,'T','E','L','I','N','K'}
#endif
#ifndef ZCL_BASIC_MODEL_ID
#define ZCL_BASIC_MODEL_ID          {8,'T','L','S','R','8','2','x','x'}
#endif
#ifndef ZCL_BASIC_SW_BUILD_ID
#define ZCL_BASIC_SW_BUILD_ID       {10,'0','1','2','2','0','5','2','0','1','7'}
#endif

#define R               ACCESS_CONTROL_READ
#define RW              ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE
#define RR              ACCESS_CONTROL_READ | ACCESS_CONTROL_REPORTABLE
#define RWR             ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE | ACCESS_CONTROL_REPORTABLE

#define ZCL_UINT8       ZCL_DATA_TYPE_UINT8
#define ZCL_INT8        ZCL_DATA_TYPE_INT8
#define ZCL_UINT16      ZCL_DATA_TYPE_UINT16
#define ZCL_INT16       ZCL_DATA_TYPE_INT16
#define ZCL_UINT32      ZCL_DATA_TYPE_UINT32
#define ZCL_ENUM8       ZCL_DATA_TYPE_ENUM8
#define ZCL_ENUM16		ZCL_DATA_TYPE_ENUM16
#define ZCL_BOOLEAN     ZCL_DATA_TYPE_BOOLEAN
#define ZCL_BITMAP8     ZCL_DATA_TYPE_BITMAP8
#define ZCL_BITMAP16    ZCL_DATA_TYPE_BITMAP16
#define ZCL_CHAR_STR    ZCL_DATA_TYPE_CHAR_STR
#define ZCL_UTC         ZCL_DATA_TYPE_UTC
//#define ZCL_SINGLE      ZCL_DATA_TYPE_SINGLE_PREC
#define ZCL_IEEE_ADDR   ZCL_DATA_TYPE_IEEE_ADDR

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep1_inClusterList[] =
{
    ZCL_CLUSTER_GEN_BASIC,
    ZCL_CLUSTER_GEN_IDENTIFY,
    ZCL_CLUSTER_GEN_POWER_CFG,
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep1_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_OTA,
#ifdef ZCL_ZLL_COMMISSIONING
    ZCL_CLUSTER_TOUCHLINK_COMMISSIONING,
#endif
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep2_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep2_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep3_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep3_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep4_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep4_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep5_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep5_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep6_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep6_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep7_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep7_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep8_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep8_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep9_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep9_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep10_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep10_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep11_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep11_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep12_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep12_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep13_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep13_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep14_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep14_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep15_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep15_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep16_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep16_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep17_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep17_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep18_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep18_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep19_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep19_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const uint16_t app_ep20_inClusterList[] =
{
    ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,
    ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const uint16_t app_ep20_outClusterList[] =
{
    ZCL_CLUSTER_GEN_GROUPS,
    ZCL_CLUSTER_GEN_SCENES,
    ZCL_CLUSTER_GEN_ON_OFF,
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
};

/**
 *  @brief Definition for Server cluster number and Client cluster number
 */
#define APP_EP1_IN_CLUSTER_NUM   (sizeof(app_ep1_inClusterList)/sizeof(app_ep1_inClusterList[0]))
#define APP_EP1_OUT_CLUSTER_NUM  (sizeof(app_ep1_outClusterList)/sizeof(app_ep1_outClusterList[0]))
#define APP_EP2_IN_CLUSTER_NUM   (sizeof(app_ep2_inClusterList)/sizeof(app_ep2_inClusterList[0]))
#define APP_EP2_OUT_CLUSTER_NUM  (sizeof(app_ep2_outClusterList)/sizeof(app_ep2_outClusterList[0]))
#define APP_EP3_IN_CLUSTER_NUM   (sizeof(app_ep3_inClusterList)/sizeof(app_ep3_inClusterList[0]))
#define APP_EP3_OUT_CLUSTER_NUM  (sizeof(app_ep3_outClusterList)/sizeof(app_ep3_outClusterList[0]))
#define APP_EP4_IN_CLUSTER_NUM   (sizeof(app_ep4_inClusterList)/sizeof(app_ep4_inClusterList[0]))
#define APP_EP4_OUT_CLUSTER_NUM  (sizeof(app_ep4_outClusterList)/sizeof(app_ep4_outClusterList[0]))
#define APP_EP5_IN_CLUSTER_NUM   (sizeof(app_ep5_inClusterList)/sizeof(app_ep5_inClusterList[0]))
#define APP_EP5_OUT_CLUSTER_NUM  (sizeof(app_ep5_outClusterList)/sizeof(app_ep5_outClusterList[0]))
#define APP_EP6_IN_CLUSTER_NUM   (sizeof(app_ep6_inClusterList)/sizeof(app_ep6_inClusterList[0]))
#define APP_EP6_OUT_CLUSTER_NUM  (sizeof(app_ep6_outClusterList)/sizeof(app_ep6_outClusterList[0]))
#define APP_EP7_IN_CLUSTER_NUM   (sizeof(app_ep7_inClusterList)/sizeof(app_ep7_inClusterList[0]))
#define APP_EP7_OUT_CLUSTER_NUM  (sizeof(app_ep7_outClusterList)/sizeof(app_ep7_outClusterList[0]))
#define APP_EP8_IN_CLUSTER_NUM   (sizeof(app_ep8_inClusterList)/sizeof(app_ep8_inClusterList[0]))
#define APP_EP8_OUT_CLUSTER_NUM  (sizeof(app_ep8_outClusterList)/sizeof(app_ep8_outClusterList[0]))
#define APP_EP9_IN_CLUSTER_NUM   (sizeof(app_ep9_inClusterList)/sizeof(app_ep9_inClusterList[0]))
#define APP_EP9_OUT_CLUSTER_NUM  (sizeof(app_ep9_outClusterList)/sizeof(app_ep9_outClusterList[0]))
#define APP_EP10_IN_CLUSTER_NUM   (sizeof(app_ep10_inClusterList)/sizeof(app_ep10_inClusterList[0]))
#define APP_EP10_OUT_CLUSTER_NUM  (sizeof(app_ep10_outClusterList)/sizeof(app_ep10_outClusterList[0]))
#define APP_EP11_IN_CLUSTER_NUM   (sizeof(app_ep11_inClusterList)/sizeof(app_ep11_inClusterList[0]))
#define APP_EP11_OUT_CLUSTER_NUM  (sizeof(app_ep11_outClusterList)/sizeof(app_ep11_outClusterList[0]))
#define APP_EP12_IN_CLUSTER_NUM   (sizeof(app_ep12_inClusterList)/sizeof(app_ep12_inClusterList[0]))
#define APP_EP12_OUT_CLUSTER_NUM  (sizeof(app_ep12_outClusterList)/sizeof(app_ep12_outClusterList[0]))
#define APP_EP13_IN_CLUSTER_NUM   (sizeof(app_ep13_inClusterList)/sizeof(app_ep13_inClusterList[0]))
#define APP_EP13_OUT_CLUSTER_NUM  (sizeof(app_ep13_outClusterList)/sizeof(app_ep13_outClusterList[0]))
#define APP_EP14_IN_CLUSTER_NUM   (sizeof(app_ep14_inClusterList)/sizeof(app_ep14_inClusterList[0]))
#define APP_EP14_OUT_CLUSTER_NUM  (sizeof(app_ep14_outClusterList)/sizeof(app_ep14_outClusterList[0]))
#define APP_EP15_IN_CLUSTER_NUM   (sizeof(app_ep15_inClusterList)/sizeof(app_ep15_inClusterList[0]))
#define APP_EP15_OUT_CLUSTER_NUM  (sizeof(app_ep15_outClusterList)/sizeof(app_ep15_outClusterList[0]))
#define APP_EP16_IN_CLUSTER_NUM   (sizeof(app_ep16_inClusterList)/sizeof(app_ep16_inClusterList[0]))
#define APP_EP16_OUT_CLUSTER_NUM  (sizeof(app_ep16_outClusterList)/sizeof(app_ep16_outClusterList[0]))
#define APP_EP17_IN_CLUSTER_NUM   (sizeof(app_ep17_inClusterList)/sizeof(app_ep17_inClusterList[0]))
#define APP_EP17_OUT_CLUSTER_NUM  (sizeof(app_ep17_outClusterList)/sizeof(app_ep17_outClusterList[0]))
#define APP_EP18_IN_CLUSTER_NUM   (sizeof(app_ep18_inClusterList)/sizeof(app_ep18_inClusterList[0]))
#define APP_EP18_OUT_CLUSTER_NUM  (sizeof(app_ep18_outClusterList)/sizeof(app_ep18_outClusterList[0]))
#define APP_EP19_IN_CLUSTER_NUM   (sizeof(app_ep19_inClusterList)/sizeof(app_ep19_inClusterList[0]))
#define APP_EP19_OUT_CLUSTER_NUM  (sizeof(app_ep19_outClusterList)/sizeof(app_ep19_outClusterList[0]))
#define APP_EP20_IN_CLUSTER_NUM   (sizeof(app_ep20_inClusterList)/sizeof(app_ep20_inClusterList[0]))
#define APP_EP20_OUT_CLUSTER_NUM  (sizeof(app_ep20_outClusterList)/sizeof(app_ep20_outClusterList[0]))

/**
 *  @brief Definition for simple description for HA profile
 */
const af_simple_descriptor_t app_ep1Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT1,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP1_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP1_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep1_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep1_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep2Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT2,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP2_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP2_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep2_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep2_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep3Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT3,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP3_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP3_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep3_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep3_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep4Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT4,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP4_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP4_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep4_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep4_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep5Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT5,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP5_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP5_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep5_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep5_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep6Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT6,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP6_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP6_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep6_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep6_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep7Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT7,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP7_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP7_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep7_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep7_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep8Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT8,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP8_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP8_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep8_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep8_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep9Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT9,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP9_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP9_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep9_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep9_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep10Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT10,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP10_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP10_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep10_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep10_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep11Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT11,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP11_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP11_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep11_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep11_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep12Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT12,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP12_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP12_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep12_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep12_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep13Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT13,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP13_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP13_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep13_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep13_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep14Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT14,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP14_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP14_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep14_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep14_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep15Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT15,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP15_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP15_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep15_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep15_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep16Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT16,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP16_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP16_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep16_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep16_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep17Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT17,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP17_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP17_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep17_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep17_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep18Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT18,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP18_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP18_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep18_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep18_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep19Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT19,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP19_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP19_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep19_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep19_outClusterList,     /* Application output cluster list */
};

const af_simple_descriptor_t app_ep20Desc = {
    HA_PROFILE_ID,                          /* Application profile identifier */
    HA_DEV_REMOTE_CTRL,                     /* Application device identifier */
    APP_ENDPOINT20,                          /* Endpoint */
    2,                                      /* Application device version */
    0,                                      /* Reserved */
    APP_EP20_IN_CLUSTER_NUM,                 /* Application input cluster count */
    APP_EP20_OUT_CLUSTER_NUM,                /* Application output cluster count */
    (uint16_t *)app_ep20_inClusterList,      /* Application input cluster list */
    (uint16_t *)app_ep20_outClusterList,     /* Application output cluster list */
};


/* Basic */
zcl_basicAttr_t g_zcl_basicAttrs =
{
    .zclVersion     = 0x03,
    .appVersion     = APP_RELEASE,
    .stackVersion   = (STACK_RELEASE|STACK_BUILD),
    .hwVersion      = HW_VERSION,
    .manuName       = ZCL_BASIC_MFG_NAME,
    .modelId        = ZCL_BASIC_MODEL_ID,
    .dateCode       = ZCL_BASIC_DATE_CODE,
    .powerSource    = POWER_SOURCE_BATTERY,
    .swBuildId      = ZCL_BASIC_SW_BUILD_ID,
    .deviceEnable   = TRUE,
};

const zclAttrInfo_t basic_attrTbl[] =
{
    { ZCL_ATTRID_BASIC_ZCL_VER,             ZCL_UINT8,    R,  (uint8_t*)&g_zcl_basicAttrs.zclVersion},
    { ZCL_ATTRID_BASIC_APP_VER,             ZCL_UINT8,    R,  (uint8_t*)&g_zcl_basicAttrs.appVersion},
    { ZCL_ATTRID_BASIC_STACK_VER,           ZCL_UINT8,    R,  (uint8_t*)&g_zcl_basicAttrs.stackVersion},
    { ZCL_ATTRID_BASIC_HW_VER,              ZCL_UINT8,    R,  (uint8_t*)&g_zcl_basicAttrs.hwVersion},
    { ZCL_ATTRID_BASIC_MFR_NAME,            ZCL_CHAR_STR, R,  (uint8_t*)g_zcl_basicAttrs.manuName},
    { ZCL_ATTRID_BASIC_MODEL_ID,            ZCL_CHAR_STR, R,  (uint8_t*)g_zcl_basicAttrs.modelId},
    { ZCL_ATTRID_BASIC_DATE_CODE,           ZCL_CHAR_STR, R,  (uint8_t*)g_zcl_basicAttrs.dateCode},
    { ZCL_ATTRID_BASIC_POWER_SOURCE,        ZCL_ENUM8,    R,  (uint8_t*)&g_zcl_basicAttrs.powerSource},
    { ZCL_ATTRID_BASIC_DEV_ENABLED,         ZCL_BOOLEAN,  RW, (uint8_t*)&g_zcl_basicAttrs.deviceEnable},
    { ZCL_ATTRID_BASIC_SW_BUILD_ID,         ZCL_CHAR_STR, R,  (uint8_t*)&g_zcl_basicAttrs.swBuildId},

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},

};

#define ZCL_BASIC_ATTR_NUM       sizeof(basic_attrTbl) / sizeof(zclAttrInfo_t)


/* Identify */
zcl_identifyAttr_t g_zcl_identifyAttrs =
{
    .identifyTime   = 0x0000,
};

const zclAttrInfo_t identify_attrTbl[] =
{
    { ZCL_ATTRID_IDENTIFY_TIME,             ZCL_UINT16,   RW,   (uint8_t*)&g_zcl_identifyAttrs.identifyTime },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,    (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_IDENTIFY_ATTR_NUM           sizeof(identify_attrTbl) / sizeof(zclAttrInfo_t)

/* power */
zcl_powerAttr_t g_zcl_powerAttrs =
{
    .batteryPercentage = 0x64, //in 0,5% units, 0xff - unknown
};

const zclAttrInfo_t powerCfg_attrTbl[] =
{
    { ZCL_ATTRID_BATTERY_PERCENTAGE_REMAINING,  ZCL_UINT8,  RR, (uint8_t*)&g_zcl_powerAttrs.batteryPercentage},

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,       ZCL_UINT16, R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_POWER_CFG_ATTR_NUM       sizeof(powerCfg_attrTbl) / sizeof(zclAttrInfo_t)

zcl_msInputAttr_t g_zcl_msInputAttrs[MAX_BUTTON_NUM] = {
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
    {
        .value = ACTION_EMPTY,
        .num = 8,
        .out_of_service = 0,
        .status_flag = 0,
    },
};

const zclAttrInfo_t msInput1_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[0].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[0].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[0].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[0].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT1_ATTR_NUM   sizeof(msInput1_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput2_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[1].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[1].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[1].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[1].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT2_ATTR_NUM   sizeof(msInput2_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput3_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[2].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[2].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[2].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[2].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT3_ATTR_NUM   sizeof(msInput3_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput4_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[3].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[3].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[3].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[3].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT4_ATTR_NUM   sizeof(msInput4_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput5_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[4].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[4].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[4].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[4].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT5_ATTR_NUM   sizeof(msInput5_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput6_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[5].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[5].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[5].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[5].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT6_ATTR_NUM   sizeof(msInput6_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput7_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[6].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[6].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[6].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[6].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT7_ATTR_NUM   sizeof(msInput7_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput8_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[7].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[7].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[7].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[7].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT8_ATTR_NUM   sizeof(msInput8_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput9_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[8].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[8].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[8].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[8].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT9_ATTR_NUM   sizeof(msInput9_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput10_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[9].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[9].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[9].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[9].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT10_ATTR_NUM   sizeof(msInput10_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput11_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[10].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[10].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[10].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[10].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT11_ATTR_NUM   sizeof(msInput11_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput12_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[11].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[11].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[11].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[11].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT12_ATTR_NUM   sizeof(msInput12_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput13_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[12].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[12].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[12].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[12].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT13_ATTR_NUM   sizeof(msInput13_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput14_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[13].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[13].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[13].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[13].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT14_ATTR_NUM   sizeof(msInput14_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput15_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[14].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[14].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[14].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[14].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT15_ATTR_NUM   sizeof(msInput15_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput16_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[15].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[15].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[15].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[15].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT16_ATTR_NUM   sizeof(msInput16_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput17_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[16].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[16].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[16].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[16].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT17_ATTR_NUM   sizeof(msInput17_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput18_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[17].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[17].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[17].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[17].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT18_ATTR_NUM   sizeof(msInput18_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput19_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[18].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[18].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[18].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[18].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT19_ATTR_NUM   sizeof(msInput19_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t msInput20_attrTbl[] = {
        { ZCL_MULTISTATE_INPUT_ATTRID_OUT_OF_SERVICE,   ZCL_BOOLEAN,    RW,     (uint8_t*)&g_zcl_msInputAttrs[19].out_of_service },
        { ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE,    ZCL_UINT16,     RWR,    (uint8_t*)&g_zcl_msInputAttrs[19].value          },
        { ZCL_MULTISTATE_INPUT_ATTRID_STATUS_FLAGS,     ZCL_BITMAP8,    RR,     (uint8_t*)&g_zcl_msInputAttrs[19].status_flag    },
        { ZCL_MULTISTATE_INPUT_ATTRID_NUM_OF_STATES,    ZCL_UINT16,     R,      (uint8_t*)&g_zcl_msInputAttrs[19].num            },

        { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,           ZCL_UINT16,     R,      (uint8_t*)&zcl_attr_global_clusterRevision      },

};

#define ZCL_MSINPUT20_ATTR_NUM   sizeof(msInput20_attrTbl) / sizeof(zclAttrInfo_t)

#ifdef ZCL_GROUP
/* Group */
zcl_groupAttr_t g_zcl_groupAttrs[MAX_BUTTON_NUM] =
{
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
    {.nameSupport = 0},
};

const zclAttrInfo_t group1_attrTbl[] =
{
    { ZCL_ATTRID_GROUP_NAME_SUPPORT,        ZCL_BITMAP8,    R,  (uint8_t*)&g_zcl_groupAttrs[0].nameSupport     },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (uint8_t*)&zcl_attr_global_clusterRevision  },
};

#define ZCL_GROUP1_ATTR_NUM    sizeof(group1_attrTbl) / sizeof(zclAttrInfo_t)

#endif

//#ifdef ZCL_SCENE
/* Scene */
zcl_sceneAttr_t g_zcl_sceneAttrs[MAX_BUTTON_NUM] = {
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
};
//{
//    {
//        .sceneCount     = 0,
//        .currentScene   = 0,
//        .currentGroup   = 0x0000,
//        .sceneValid     = FALSE,
//        .nameSupport    = 0,
//        .customScene    = 0,
//        .customGroup    = 0,
//    },
//};

const zclAttrInfo_t scene1_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[0].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[0].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[0].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[0].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[0].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[0].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[0].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE1_ATTR_NUM   sizeof(scene1_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene2_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[1].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[1].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[1].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[1].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[1].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[1].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[1].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE2_ATTR_NUM   sizeof(scene2_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene3_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[2].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[2].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[2].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[2].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[2].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[2].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[2].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE3_ATTR_NUM   sizeof(scene3_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene4_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[3].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[3].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[3].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[3].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[3].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[3].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[3].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE4_ATTR_NUM   sizeof(scene4_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene5_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[4].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[4].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[4].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[4].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[4].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[4].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[4].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE5_ATTR_NUM   sizeof(scene5_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene6_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[5].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[5].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[5].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[5].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[5].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[5].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[5].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE6_ATTR_NUM   sizeof(scene6_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene7_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[6].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[6].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[6].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[6].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[6].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[6].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[6].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE7_ATTR_NUM   sizeof(scene7_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene8_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[7].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[7].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[7].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[7].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[7].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[7].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[7].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE8_ATTR_NUM   sizeof(scene8_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene9_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[8].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[8].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[8].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[8].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[8].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[8].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[8].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE9_ATTR_NUM   sizeof(scene9_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene10_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[9].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[9].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[9].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[9].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[9].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[9].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[9].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE10_ATTR_NUM   sizeof(scene10_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene11_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[10].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[10].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[10].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[10].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[10].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[10].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[10].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE11_ATTR_NUM   sizeof(scene11_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene12_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[11].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[11].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[11].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[11].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[11].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[11].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[11].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE12_ATTR_NUM   sizeof(scene12_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene13_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[12].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[12].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[12].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[12].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[12].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[12].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[12].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE13_ATTR_NUM   sizeof(scene13_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene14_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[13].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[13].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[13].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[13].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[13].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[13].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[13].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE14_ATTR_NUM   sizeof(scene14_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene15_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[14].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[14].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[14].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[14].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[14].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[14].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[14].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE15_ATTR_NUM   sizeof(scene15_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene16_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[15].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[15].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[15].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[15].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[15].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[15].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[15].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE16_ATTR_NUM   sizeof(scene16_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene17_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[16].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[16].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[16].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[16].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[16].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[16].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[16].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE17_ATTR_NUM   sizeof(scene17_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene18_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[17].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[17].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[17].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[17].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[17].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[17].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[17].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE18_ATTR_NUM   sizeof(scene18_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene19_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[18].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[18].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[18].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[18].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[18].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[18].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[18].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE19_ATTR_NUM   sizeof(scene19_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t scene20_attrTbl[] = {
    { ZCL_ATTRID_SCENE_SCENE_COUNT,         ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[19].sceneCount     },
    { ZCL_ATTRID_SCENE_CURRENT_SCENE,       ZCL_UINT8,    R,  (uint8_t*)&g_zcl_sceneAttrs[19].currentScene   },
    { ZCL_ATTRID_SCENE_CURRENT_GROUP,       ZCL_UINT16,   R,  (uint8_t*)&g_zcl_sceneAttrs[19].currentGroup   },
    { ZCL_ATTRID_SCENE_SCENE_VALID,         ZCL_BOOLEAN,  R,  (uint8_t*)&g_zcl_sceneAttrs[19].sceneValid     },
    { ZCL_ATTRID_SCENE_NAME_SUPPORT,        ZCL_BITMAP8,  R,  (uint8_t*)&g_zcl_sceneAttrs[19].nameSupport    },
    { ZCL_CUSTOM_ATTRID_SCENE_SCENE_ID,     ZCL_UINT8,    RW, (uint8_t*)&g_zcl_sceneAttrs[19].customScene    },
    { ZCL_CUSTOM_ATTRID_SCENE_GROUP_ID,     ZCL_UINT16,   RW, (uint8_t*)&g_zcl_sceneAttrs[19].customGroup    },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (uint8_t*)&zcl_attr_global_clusterRevision},
};

#define ZCL_SCENE20_ATTR_NUM   sizeof(scene20_attrTbl) / sizeof(zclAttrInfo_t)

//#endif

//#ifdef ZCL_ON_OFF_SWITCH_CFG
/* On/Off Config */

zcl_onOffCfgAttr_t g_zcl_onOffCfgAttrs[MAX_BUTTON_NUM] = {
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
        .device_model      = DEVICE_BUTTON_8,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
    {
        .switchType        = ZCL_SWITCH_TYPE_MULTIFUNCTION,
        .switchActions     = ZCL_SWITCH_ACTION_OFF_ON,
        .custom_swtichType = ZCL_SWITCH_TYPE_TOGGLE,
    },
};

const zclAttrInfo_t onOffCfg1_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[0].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[0].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[0].custom_swtichType  },
    { ZCL_CUSTOM_ATTRID_DEVICE_MODEL,       ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[0].device_model       },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG1_ATTR_NUM    sizeof(onOffCfg1_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg2_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[1].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[1].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[1].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG2_ATTR_NUM    sizeof(onOffCfg2_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg3_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[2].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[2].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[2].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG3_ATTR_NUM    sizeof(onOffCfg3_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg4_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[3].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[3].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[3].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG4_ATTR_NUM    sizeof(onOffCfg4_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg5_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[4].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[4].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[4].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG5_ATTR_NUM    sizeof(onOffCfg5_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg6_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[5].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[5].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[5].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG6_ATTR_NUM    sizeof(onOffCfg6_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg7_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[6].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[6].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[6].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG7_ATTR_NUM    sizeof(onOffCfg7_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg8_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[7].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[7].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[7].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG8_ATTR_NUM    sizeof(onOffCfg8_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg9_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[8].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[8].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[8].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG9_ATTR_NUM    sizeof(onOffCfg9_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg10_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[9].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[9].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[9].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG10_ATTR_NUM    sizeof(onOffCfg10_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg11_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[10].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[10].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[10].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG11_ATTR_NUM    sizeof(onOffCfg11_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg12_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[11].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[11].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[11].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG12_ATTR_NUM    sizeof(onOffCfg12_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg13_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[12].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[12].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[12].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG13_ATTR_NUM    sizeof(onOffCfg13_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg14_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[13].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[13].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[13].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG14_ATTR_NUM    sizeof(onOffCfg14_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg15_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[14].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[14].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[14].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG15_ATTR_NUM    sizeof(onOffCfg15_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg16_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[15].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[15].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[15].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG16_ATTR_NUM    sizeof(onOffCfg16_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg17_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[16].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[16].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[16].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG17_ATTR_NUM    sizeof(onOffCfg17_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg18_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[17].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[17].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[17].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG18_ATTR_NUM    sizeof(onOffCfg18_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg19_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[18].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[18].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[18].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG19_ATTR_NUM    sizeof(onOffCfg19_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t onOffCfg20_attrTbl[] =
{
    { ZCL_ATTRID_SWITCH_TYPE,               ZCL_ENUM8,    R,  (u8*)&g_zcl_onOffCfgAttrs[19].switchType         },
    { ZCL_ATTRID_SWITCH_ACTION,             ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[19].switchActions      },
    { ZCL_CUSTOM_ATTRID_SWITCH_TYPE,        ZCL_ENUM8,    RW, (u8*)&g_zcl_onOffCfgAttrs[19].custom_swtichType  },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,   R,  (u8*)&zcl_attr_global_clusterRevision           },
};

#define ZCL_ON_OFF_CFG20_ATTR_NUM    sizeof(onOffCfg20_attrTbl) / sizeof(zclAttrInfo_t)

//#endif // ZCL_ON_OFF_SWITCH_CFG

//#ifdef ZCL_LEVEL_CTRL
/* Level */
zcl_levelAttr_t g_zcl_levelAttrs[MAX_BUTTON_NUM] = {
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .transitionTime = LEVEL_TRANSITION_TIME,
        .defaultMoveRate = 100,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
    {
        .currentLevel = 10,
        .minLevel = ZCL_LEVEL_ATTR_MIN_LEVEL,
        .maxLevel = ZCL_LEVEL_ATTR_MAX_LEVEL,
        .options  = 0,
        .defaultMoveRate = 100,
        .transitionTime = LEVEL_TRANSITION_TIME,
    },
};

const zclAttrInfo_t level1_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[0].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[0].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[0].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[0].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[0].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[0].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL1_ATTR_NUM   sizeof(level1_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level2_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[1].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[1].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[1].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[1].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[1].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[1].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL2_ATTR_NUM   sizeof(level2_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level3_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[2].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[2].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[2].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[2].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[2].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[2].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL3_ATTR_NUM   sizeof(level3_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level4_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[3].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[3].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[3].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[3].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[3].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[3].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL4_ATTR_NUM   sizeof(level4_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level5_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[4].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[4].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[4].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[4].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[4].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[4].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL5_ATTR_NUM   sizeof(level5_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level6_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[5].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[5].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[5].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[5].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[5].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[5].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL6_ATTR_NUM   sizeof(level6_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level7_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[6].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[6].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[6].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[6].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[6].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[6].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL7_ATTR_NUM   sizeof(level7_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level8_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[7].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[7].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[7].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[7].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[7].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[7].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL8_ATTR_NUM   sizeof(level8_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level9_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[8].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[8].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[8].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[8].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[8].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[8].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL9_ATTR_NUM   sizeof(level9_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level10_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[9].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[9].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[9].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[9].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[9].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[9].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL10_ATTR_NUM   sizeof(level10_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level11_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[10].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[10].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[10].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[10].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[10].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[10].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL11_ATTR_NUM   sizeof(level11_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level12_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[11].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[11].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[11].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[11].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[11].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[11].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL12_ATTR_NUM   sizeof(level12_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level13_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[12].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[12].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[12].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[12].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[12].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[12].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL13_ATTR_NUM   sizeof(level13_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level14_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[13].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[13].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[13].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[13].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[13].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[13].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL14_ATTR_NUM   sizeof(level14_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level15_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[14].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[14].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[14].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[14].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[14].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[14].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL15_ATTR_NUM   sizeof(level15_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level16_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[15].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[15].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[15].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[15].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[15].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[15].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL16_ATTR_NUM   sizeof(level16_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level17_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[16].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[16].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[16].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[16].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[16].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[16].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL17_ATTR_NUM   sizeof(level17_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level18_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[17].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[17].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[17].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[17].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[17].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[17].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL18_ATTR_NUM   sizeof(level18_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level19_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[18].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[18].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[18].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[18].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[18].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[18].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL19_ATTR_NUM   sizeof(level19_attrTbl) / sizeof(zclAttrInfo_t)

const zclAttrInfo_t level20_attrTbl[] =
{
    { ZCL_ATTRID_LEVEL_CURRENT_LEVEL,       ZCL_UINT8,      RR, (uint8_t*)&g_zcl_levelAttrs[19].currentLevel },
    { ZCL_ATTRID_LEVEL_MIN_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[19].minLevel     },
    { ZCL_ATTRID_LEVEL_MAX_LEVEL,           ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[19].maxLevel     },
    { ZCL_ATTRID_LEVEL_OPTIONS,             ZCL_BITMAP8,    RW, (uint8_t*)&g_zcl_levelAttrs[19].options      },
    { ZCL_ATTRID_LEVEL_DEFAULT_MOVE_RATE,   ZCL_UINT8,      RW, (uint8_t*)&g_zcl_levelAttrs[19].defaultMoveRate     },
    { ZCL_ATTRID_LEVEL_ON_OFF_TRANSITION_TIME, ZCL_UINT16,  RW, (uint8_t*)&g_zcl_levelAttrs[19].transitionTime   },

    { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,   ZCL_UINT16,     R,  (u8*)&zcl_attr_global_clusterRevision       },
};

#define ZCL_LEVEL20_ATTR_NUM   sizeof(level20_attrTbl) / sizeof(zclAttrInfo_t)

//#endif // ZCL_LEVEL_CTRL

/**
 *  @brief Definition for simple switch ZCL specific cluster
 */
const zcl_specClusterInfo_t g_appEp1ClusterList[] = {
    {ZCL_CLUSTER_GEN_BASIC,                 MANUFACTURER_CODE_NONE, ZCL_BASIC_ATTR_NUM,         basic_attrTbl,      zcl_basic_register,             app_basicCb     },
    {ZCL_CLUSTER_GEN_IDENTIFY,              MANUFACTURER_CODE_NONE, ZCL_IDENTIFY_ATTR_NUM,      identify_attrTbl,   zcl_identify_register,          app_identifyCb  },
    {ZCL_CLUSTER_GEN_POWER_CFG,             MANUFACTURER_CODE_NONE, ZCL_POWER_CFG_ATTR_NUM,     powerCfg_attrTbl,   zcl_powerCfg_register,          app_powerCfgCb  },
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                          NULL,               zcl_group_register,             app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE1_ATTR_NUM,        scene1_attrTbl,     zcl_scene_register,             app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG1_ATTR_NUM,   onOffCfg1_attrTbl,  zcl_onOffSwitchCfg_register,    NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT1_ATTR_NUM,      msInput1_attrTbl,   zcl_multistate_input_register,  app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL1_ATTR_NUM,        level1_attrTbl,     zcl_level_register,             app_levelCb     },
};

uint8_t APP_EP1_CB_CLUSTER_NUM = (sizeof(g_appEp1ClusterList)/sizeof(g_appEp1ClusterList[0]));

const zcl_specClusterInfo_t g_appEp2ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE2_ATTR_NUM,      scene2_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG2_ATTR_NUM, onOffCfg2_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT2_ATTR_NUM,    msInput2_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL2_ATTR_NUM,      level2_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP2_CB_CLUSTER_NUM = (sizeof(g_appEp2ClusterList)/sizeof(g_appEp2ClusterList[0]));

const zcl_specClusterInfo_t g_appEp3ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE3_ATTR_NUM,      scene3_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG3_ATTR_NUM, onOffCfg3_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT3_ATTR_NUM,    msInput3_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL3_ATTR_NUM,      level3_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP3_CB_CLUSTER_NUM = (sizeof(g_appEp3ClusterList)/sizeof(g_appEp3ClusterList[0]));

const zcl_specClusterInfo_t g_appEp4ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE4_ATTR_NUM,      scene4_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG4_ATTR_NUM, onOffCfg4_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT4_ATTR_NUM,    msInput4_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL4_ATTR_NUM,      level4_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP4_CB_CLUSTER_NUM = (sizeof(g_appEp4ClusterList)/sizeof(g_appEp4ClusterList[0]));

const zcl_specClusterInfo_t g_appEp5ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,             app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE5_ATTR_NUM,      scene5_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG5_ATTR_NUM, onOffCfg5_attrTbl, zcl_onOffSwitchCfg_register,    NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT5_ATTR_NUM,    msInput5_attrTbl,  zcl_multistate_input_register,  app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL5_ATTR_NUM,      level5_attrTbl,    zcl_level_register,             app_levelCb     },
};

uint8_t APP_EP5_CB_CLUSTER_NUM = (sizeof(g_appEp5ClusterList)/sizeof(g_appEp5ClusterList[0]));

const zcl_specClusterInfo_t g_appEp6ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE6_ATTR_NUM,      scene6_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG6_ATTR_NUM, onOffCfg6_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT6_ATTR_NUM,    msInput6_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL6_ATTR_NUM,      level6_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP6_CB_CLUSTER_NUM = (sizeof(g_appEp6ClusterList)/sizeof(g_appEp6ClusterList[0]));

const zcl_specClusterInfo_t g_appEp7ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE7_ATTR_NUM,      scene7_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG7_ATTR_NUM, onOffCfg7_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT7_ATTR_NUM,    msInput7_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL7_ATTR_NUM,      level7_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP7_CB_CLUSTER_NUM = (sizeof(g_appEp7ClusterList)/sizeof(g_appEp7ClusterList[0]));

const zcl_specClusterInfo_t g_appEp8ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE8_ATTR_NUM,      scene8_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG8_ATTR_NUM, onOffCfg8_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT8_ATTR_NUM,    msInput8_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL8_ATTR_NUM,      level8_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP8_CB_CLUSTER_NUM = (sizeof(g_appEp8ClusterList)/sizeof(g_appEp8ClusterList[0]));

const zcl_specClusterInfo_t g_appEp9ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE9_ATTR_NUM,      scene9_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG9_ATTR_NUM, onOffCfg9_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT9_ATTR_NUM,    msInput9_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL9_ATTR_NUM,      level9_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP9_CB_CLUSTER_NUM = (sizeof(g_appEp9ClusterList)/sizeof(g_appEp9ClusterList[0]));

const zcl_specClusterInfo_t g_appEp10ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE10_ATTR_NUM,      scene10_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG10_ATTR_NUM, onOffCfg10_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT10_ATTR_NUM,    msInput10_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL10_ATTR_NUM,      level10_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP10_CB_CLUSTER_NUM = (sizeof(g_appEp10ClusterList)/sizeof(g_appEp10ClusterList[0]));

const zcl_specClusterInfo_t g_appEp11ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE11_ATTR_NUM,      scene11_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG11_ATTR_NUM, onOffCfg11_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT11_ATTR_NUM,    msInput11_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL1_ATTR_NUM,      level11_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP11_CB_CLUSTER_NUM = (sizeof(g_appEp11ClusterList)/sizeof(g_appEp11ClusterList[0]));

const zcl_specClusterInfo_t g_appEp12ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE12_ATTR_NUM,      scene12_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG12_ATTR_NUM, onOffCfg12_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT12_ATTR_NUM,    msInput12_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL12_ATTR_NUM,      level12_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP12_CB_CLUSTER_NUM = (sizeof(g_appEp12ClusterList)/sizeof(g_appEp12ClusterList[0]));

const zcl_specClusterInfo_t g_appEp13ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE13_ATTR_NUM,      scene13_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG13_ATTR_NUM, onOffCfg13_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT13_ATTR_NUM,    msInput13_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL13_ATTR_NUM,      level13_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP13_CB_CLUSTER_NUM = (sizeof(g_appEp13ClusterList)/sizeof(g_appEp13ClusterList[0]));

const zcl_specClusterInfo_t g_appEp14ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE14_ATTR_NUM,      scene14_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG14_ATTR_NUM, onOffCfg14_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT14_ATTR_NUM,    msInput14_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL14_ATTR_NUM,      level14_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP14_CB_CLUSTER_NUM = (sizeof(g_appEp14ClusterList)/sizeof(g_appEp14ClusterList[0]));

const zcl_specClusterInfo_t g_appEp15ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE15_ATTR_NUM,      scene15_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG15_ATTR_NUM, onOffCfg15_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT15_ATTR_NUM,    msInput15_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL15_ATTR_NUM,      level15_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP15_CB_CLUSTER_NUM = (sizeof(g_appEp15ClusterList)/sizeof(g_appEp15ClusterList[0]));

const zcl_specClusterInfo_t g_appEp16ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE16_ATTR_NUM,      scene16_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG16_ATTR_NUM, onOffCfg16_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT16_ATTR_NUM,    msInput16_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL16_ATTR_NUM,      level16_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP16_CB_CLUSTER_NUM = (sizeof(g_appEp16ClusterList)/sizeof(g_appEp16ClusterList[0]));

const zcl_specClusterInfo_t g_appEp17ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE17_ATTR_NUM,      scene17_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG17_ATTR_NUM, onOffCfg17_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT17_ATTR_NUM,    msInput17_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL17_ATTR_NUM,      level17_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP17_CB_CLUSTER_NUM = (sizeof(g_appEp17ClusterList)/sizeof(g_appEp17ClusterList[0]));

const zcl_specClusterInfo_t g_appEp18ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                         NULL,               zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE18_ATTR_NUM,      scene18_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG18_ATTR_NUM, onOffCfg18_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT18_ATTR_NUM,    msInput18_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL18_ATTR_NUM,      level18_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP18_CB_CLUSTER_NUM = (sizeof(g_appEp18ClusterList)/sizeof(g_appEp18ClusterList[0]));

const zcl_specClusterInfo_t g_appEp19ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE19_ATTR_NUM,      scene19_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG19_ATTR_NUM, onOffCfg19_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT19_ATTR_NUM,    msInput19_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL19_ATTR_NUM,      level19_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP19_CB_CLUSTER_NUM = (sizeof(g_appEp19ClusterList)/sizeof(g_appEp19ClusterList[0]));

const zcl_specClusterInfo_t g_appEp20ClusterList[] = {
    {ZCL_CLUSTER_GEN_GROUPS,                MANUFACTURER_CODE_NONE, 0,                        NULL,              zcl_group_register,            app_groupCb     },
    {ZCL_CLUSTER_GEN_SCENES,                MANUFACTURER_CODE_NONE, ZCL_SCENE20_ATTR_NUM,      scene20_attrTbl,    zcl_scene_register,            app_sceneCb     },
    {ZCL_CLUSTER_GEN_ON_OFF_SWITCH_CONFIG,  MANUFACTURER_CODE_NONE, ZCL_ON_OFF_CFG20_ATTR_NUM, onOffCfg20_attrTbl, zcl_onOffSwitchCfg_register,   NULL            },
    {ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC,MANUFACTURER_CODE_NONE, ZCL_MSINPUT20_ATTR_NUM,    msInput20_attrTbl,  zcl_multistate_input_register, app_msInputCb   },
    {ZCL_CLUSTER_GEN_LEVEL_CONTROL,         MANUFACTURER_CODE_NONE, ZCL_LEVEL20_ATTR_NUM,      level20_attrTbl,    zcl_level_register,            app_levelCb     },
};

uint8_t APP_EP20_CB_CLUSTER_NUM = (sizeof(g_appEp20ClusterList)/sizeof(g_appEp20ClusterList[0]));

