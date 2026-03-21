#ifndef SRC_INCLUDE_APP_ENDPOINT_CFG_H_
#define SRC_INCLUDE_APP_ENDPOINT_CFG_H_

enum {
    APP_ENDPOINT1  = 0x01,
    APP_ENDPOINT2,
    APP_ENDPOINT3,
    APP_ENDPOINT4,
    APP_ENDPOINT5,
    APP_ENDPOINT6,
    APP_ENDPOINT7,
    APP_ENDPOINT8,
    APP_ENDPOINT9,
    APP_ENDPOINT10,
    APP_ENDPOINT11,
    APP_ENDPOINT12,
    APP_ENDPOINT13,
    APP_ENDPOINT14,
    APP_ENDPOINT15,
    APP_ENDPOINT16,
    APP_ENDPOINT17,
    APP_ENDPOINT18,
    APP_ENDPOINT19,
    APP_ENDPOINT20,
};

/**
 *  @brief Defined for basic cluster attributes
 */
typedef struct{
    uint8_t  zclVersion;
    uint8_t  appVersion;
    uint8_t  stackVersion;
    uint8_t  hwVersion;
    uint8_t  manuName[ZCL_BASIC_MAX_LENGTH];
    uint8_t  modelId[ZCL_BASIC_MAX_LENGTH];
    uint8_t  dateCode[ZCL_BASIC_MAX_LENGTH];
    uint8_t  productLabel[ZCL_BASIC_MAX_LENGTH];
    uint8_t  powerSource;
    uint8_t  genDevClass;                        //attr 8
    uint8_t  genDevType;                         //attr 9
    uint8_t  deviceEnable;
    uint8_t  swBuildId[ZCL_BASIC_MAX_LENGTH];    //attr 4000
} zcl_basicAttr_t;

/**
 *  @brief Defined for identify cluster attributes
 */
typedef struct{
    uint16_t identifyTime;
}zcl_identifyAttr_t;

/**
 *  @brief Defined for group cluster attributes
 */
typedef struct{
    uint8_t  nameSupport;
}zcl_groupAttr_t;

/**
 *  @brief Defined for scene cluster attributes
 */
typedef struct{
    uint8_t  sceneCount;
    uint8_t  currentScene;
    uint8_t  nameSupport;
    bool     sceneValid;
    uint16_t currentGroup;
    uint8_t  customScene;
    uint16_t customGroup;
}zcl_sceneAttr_t;

/**
 *  @brief Defined for power configuration cluster attributes
 */
typedef struct{
    uint8_t  batteryPercentage;   //0x21
}zcl_powerAttr_t;

typedef struct {
    uint8_t switchType;
    uint8_t switchActions;
    uint8_t custom_swtichType; // custom RW
    uint8_t device_model;
} zcl_onOffCfgAttr_t;

/**
 *  @brief Defined for multistate input clusters attributes
 */
typedef struct {
    uint8_t     out_of_service;
    uint16_t    value;
    uint16_t    num;
    uint8_t     status_flag;
} zcl_msInputAttr_t;

/**
 *  @brief Defined for level cluster attributes
 */
typedef struct {
    uint8_t     currentLevel;
    uint8_t     minLevel;
    uint8_t     maxLevel;
    uint8_t     options;
    uint8_t     defaultMoveRate;
} zcl_levelAttr_t;


extern const zcl_specClusterInfo_t g_appEp1ClusterList[];
extern const zcl_specClusterInfo_t g_appEp2ClusterList[];
extern const zcl_specClusterInfo_t g_appEp3ClusterList[];
extern const zcl_specClusterInfo_t g_appEp4ClusterList[];
extern const zcl_specClusterInfo_t g_appEp5ClusterList[];
extern const zcl_specClusterInfo_t g_appEp6ClusterList[];
extern const zcl_specClusterInfo_t g_appEp7ClusterList[];
extern const zcl_specClusterInfo_t g_appEp8ClusterList[];
extern const zcl_specClusterInfo_t g_appEp9ClusterList[];
extern const zcl_specClusterInfo_t g_appEp10ClusterList[];
extern const zcl_specClusterInfo_t g_appEp11ClusterList[];
extern const zcl_specClusterInfo_t g_appEp12ClusterList[];
extern const zcl_specClusterInfo_t g_appEp13ClusterList[];
extern const zcl_specClusterInfo_t g_appEp14ClusterList[];
extern const zcl_specClusterInfo_t g_appEp15ClusterList[];
extern const zcl_specClusterInfo_t g_appEp16ClusterList[];
extern const zcl_specClusterInfo_t g_appEp17ClusterList[];
extern const zcl_specClusterInfo_t g_appEp18ClusterList[];
extern const zcl_specClusterInfo_t g_appEp19ClusterList[];
extern const zcl_specClusterInfo_t g_appEp20ClusterList[];
extern const af_simple_descriptor_t app_ep1Desc;
extern const af_simple_descriptor_t app_ep2Desc;
extern const af_simple_descriptor_t app_ep3Desc;
extern const af_simple_descriptor_t app_ep4Desc;
extern const af_simple_descriptor_t app_ep5Desc;
extern const af_simple_descriptor_t app_ep6Desc;
extern const af_simple_descriptor_t app_ep7Desc;
extern const af_simple_descriptor_t app_ep8Desc;
extern const af_simple_descriptor_t app_ep9Desc;
extern const af_simple_descriptor_t app_ep10Desc;
extern const af_simple_descriptor_t app_ep11Desc;
extern const af_simple_descriptor_t app_ep12Desc;
extern const af_simple_descriptor_t app_ep13Desc;
extern const af_simple_descriptor_t app_ep14Desc;
extern const af_simple_descriptor_t app_ep15Desc;
extern const af_simple_descriptor_t app_ep16Desc;
extern const af_simple_descriptor_t app_ep17Desc;
extern const af_simple_descriptor_t app_ep18Desc;
extern const af_simple_descriptor_t app_ep19Desc;
extern const af_simple_descriptor_t app_ep20Desc;

extern uint8_t APP_EP1_CB_CLUSTER_NUM;
extern uint8_t APP_EP2_CB_CLUSTER_NUM;
extern uint8_t APP_EP3_CB_CLUSTER_NUM;
extern uint8_t APP_EP4_CB_CLUSTER_NUM;
extern uint8_t APP_EP5_CB_CLUSTER_NUM;
extern uint8_t APP_EP6_CB_CLUSTER_NUM;
extern uint8_t APP_EP7_CB_CLUSTER_NUM;
extern uint8_t APP_EP8_CB_CLUSTER_NUM;
extern uint8_t APP_EP9_CB_CLUSTER_NUM;
extern uint8_t APP_EP10_CB_CLUSTER_NUM;
extern uint8_t APP_EP11_CB_CLUSTER_NUM;
extern uint8_t APP_EP12_CB_CLUSTER_NUM;
extern uint8_t APP_EP13_CB_CLUSTER_NUM;
extern uint8_t APP_EP14_CB_CLUSTER_NUM;
extern uint8_t APP_EP15_CB_CLUSTER_NUM;
extern uint8_t APP_EP16_CB_CLUSTER_NUM;
extern uint8_t APP_EP17_CB_CLUSTER_NUM;
extern uint8_t APP_EP18_CB_CLUSTER_NUM;
extern uint8_t APP_EP19_CB_CLUSTER_NUM;
extern uint8_t APP_EP20_CB_CLUSTER_NUM;

/* Attributes */
extern zcl_basicAttr_t              g_zcl_basicAttrs;
extern zcl_identifyAttr_t           g_zcl_identifyAttrs;
extern zcl_groupAttr_t              g_zcl_groupAttrs[];
extern zcl_sceneAttr_t              g_zcl_sceneAttrs[];
extern zcl_onOffCfgAttr_t           g_zcl_onOffCfgAttrs[];
extern zcl_msInputAttr_t            g_zcl_msInputAttrs[];
extern zcl_levelAttr_t              g_zcl_levelAttrs[];

#define zcl_groupAttrsGet()         g_zcl_groupAttrs
#define zcl_sceneAttrGet()          g_zcl_sceneAttrs
#define zcl_onOffCfgAttrsGet()      g_zcl_onOffCfgAttrs;
#define zcl_msInputAttrsGet()       g_zcl_msInputAttrs;
#define zcl_levelAttrsGet()         g_zcl_levelAttrs;

#endif /* SRC_INCLUDE_APP_ENDPOINT_CFG_H_ */
