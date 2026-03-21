#ifndef SRC_INCLUDE_APP_DEVICE_H_
#define SRC_INCLUDE_APP_DEVICE_H_

#ifndef DEVICE_MODEL
#define DEVICE_MODEL    DEVICE_BUTTON_8
#endif

typedef enum {
    DEVICE_BUTTON_8 = 0,    /* 2x4 - 8 keys  */
    DEVICE_BUTTON_12,       /* 3x4 - 12 keys */
    DEVICE_BUTTON_20,       /* 4x5 - 20 keys */
    DEVICE_BUTTON_MAX
} device_model_t;

typedef struct __attribute__((packed)) {
    /*
     * custom switchType
     * 0x00 - toggle
     * 0x01 - momentary
     * 0x02 - multifunction
     * 0x03 - level up
     * 0x04 - level down
     * 0x05 - scene
     */
    uint8_t switchType[MAX_BUTTON_NUM];
    uint8_t switchActions[MAX_BUTTON_NUM];
    uint8_t defaultMoveRate[MAX_BUTTON_NUM];
    app_scene_t scene[MAX_BUTTON_NUM];
    uint8_t crc;
} device_settings_t;

extern device_model_t device_model;
extern device_settings_t device_settings;

void device_model_restore();
void device_model_save(uint8_t model);
void device_init();
nv_sts_t device_settings_restore();
nv_sts_t device_settings_save();
nv_sts_t device_settings_default();

#endif /* SRC_INCLUDE_APP_DEVICE_H_ */
