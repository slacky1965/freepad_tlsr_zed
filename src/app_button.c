#include "app_main.h"

#ifndef DEBOUNCE_BUTTON
#define DEBOUNCE_BUTTON     128     /* number of polls for debounce                 */
#endif
#define FR_COUNTER_MAX      5       /* number for factory reset                     */
#define BATTERY_COUNTER     4

typedef struct {
    uint8_t     hold;
    uint8_t     counter;
    uint8_t     debounce;
    uint32_t    pressed_time;
    uint32_t    released_time;
    uint32_t    hold_time;
    uint32_t    row_gpio;
    uint32_t    line_gpio;
} button_t;

typedef struct {
    uint32_t    released;           /* bit mask for 20 buttons */
    uint32_t    pressed;            /* bit mask for 20 buttons */
    uint32_t    counter;            /* bit mask for 20 buttons */
    uint32_t    debounce;           /* bit mask for 20 buttons */
    uint8_t     key_num;
    button_t    button[MAX_BUTTON_NUM];
} app_button_t;

enum {
    HOLD_NOT_PRESENT = 0,
    HOLD_PRESENT,
    HOLD_FIX
};

static ev_timer_event_t *timerClearSleepEvt = NULL;
static ev_timer_event_t *timerFactoryResetEvt = NULL;
bool factory_reset = false;
app_button_t app_button;

static int32_t clearSleepCb(void *args) {

    APP_DEBUG(DEBUG_PM_EN, "clearSleepCb\r\n");

    if (!g_appCtx.timerSetPollRateEvt && !g_appCtx.ota) {
        g_appCtx.not_sleep = false;
    }

    timerClearSleepEvt = NULL;
    return -1;
}

static void clearSleepTimer() {
    if (timerClearSleepEvt) {
        TL_ZB_TIMER_CANCEL(&timerClearSleepEvt);
    }
    timerClearSleepEvt = TL_ZB_TIMER_SCHEDULE(clearSleepCb, NULL, TIMEOUT_100MS);
}

static void button_factory_reset_start() {

    APP_DEBUG(DEBUG_BUTTON_EN, "button_factory_reset_start\r\n");

    factory_reset = false;

    zb_factoryReset();

    g_appCtx.net_steer_start = true;
    TL_ZB_TIMER_SCHEDULE(net_steer_start_offCb, NULL, TIMEOUT_1MIN30SEC);
    light_blink_stop();
    light_blink_start(90, 100, 1000);
    app_setPollRate(TIMEOUT_2MIN);
}

static int32_t factoryResetCb(void *args) {

    APP_DEBUG(DEBUG_BUTTON_EN, "factoryResetCb\r\n");

    if (!g_appCtx.ota) g_appCtx.not_sleep = false;

    factory_reset = false;

    timerFactoryResetEvt = NULL;
    return -1;
}

static void read_button_level(uint8_t i) {
    uint8_t up_down = 0xFF;
    uint8_t cmdOnOff = 0xFF;
    button_t *button = &app_button.button[i];
    app_button_t *key = &app_button;
    zcl_levelAttr_t *levelAttr = zcl_levelAttrsGet();
    levelAttr += i;

    switch(device_settings.switchType[i]) {
        case ZCL_CUSTOM_SWITCH_TYPE_LEVEL_MOVE_UP:
            up_down = LEVEL_MOVE_UP;
            cmdOnOff = ZCL_CMD_ONOFF_ON;
            break;
        case ZCL_CUSTOM_SWITCH_TYPE_LEVEL_MOVE_DOWN:
            up_down = LEVEL_MOVE_DOWN;
            cmdOnOff = ZCL_CMD_ONOFF_OFF;
            break;
        default:
            break;
    }

    drv_gpio_output_en(app_button.button[i].row_gpio, 1);
    bool status = drv_gpio_read(app_button.button[i].line_gpio)?true:false;
    drv_gpio_output_en(app_button.button[i].row_gpio, 0);

    if (!status) {
        if (BIT_IS_SET(key->pressed, i)) {
            if (clock_time_exceed(button->hold_time, TIMEOUT_TICK_750MS)) {
                if (button->hold == HOLD_NOT_PRESENT) {
                    button->hold = HOLD_PRESENT;
                    if (!factory_reset) {
                        APP_DEBUG(DEBUG_BUTTON_EN, "Level. Press and hold button: %d\r\n", i+1);

                        if ( up_down != 0xFF) {
                            APP_DEBUG(DEBUG_BUTTON_EN, "Level. Key: %d, up_down: %d, \r\n", i+1, up_down);
                            app_level_move(i+1, up_down);
                        }
                    } else {
                        if (timerFactoryResetEvt) {
                            TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
                        }
                        button_factory_reset_start();
                    }
                }
            }
        }
        if (button->debounce != DEBOUNCE_BUTTON) {
            button->debounce++;
            BIT_SET(key->debounce, i);
            if (button->debounce == DEBOUNCE_BUTTON) {
                BIT_SET(key->pressed, i);
                BIT_CLR(key->debounce, i);
                g_appCtx.not_sleep = true;
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d pressed level\r\n", i+1);
                light_blink_start(1, 30, 1);
                if (!clock_time_exceed(button->pressed_time, TIMEOUT_TICK_500MS)) {
                    button->counter++;
                    BIT_SET(key->counter, i);
                } else {
                    button->counter = 1;
                    BIT_SET(key->counter, i);
                    if (!zb_isDeviceJoinedNwk() && !zb_isDeviceFactoryNew()) {
                        zb_rejoinReq(zb_apsChannelMaskGet(), g_bdbAttrs.scanDuration);
                    }
                }
                button->hold_time = button->pressed_time = clock_time();
            }
        }
    } else {
        if (button->debounce != 1) {
            button->debounce--;
            BIT_SET(key->debounce, i);
            if (button->debounce == 1 && (BIT_IS_SET(key->pressed, i) || button->hold == HOLD_FIX)) {
                BIT_SET(key->released, i);
                BIT_CLR(key->debounce, i);
                g_appCtx.not_sleep = true;
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d released level\r\n", i+1);
            }
        }
    }

    if (BIT_IS_SET(key->released, i) && clock_time_exceed(button->pressed_time, TIMEOUT_TICK_500MS)) {
        if (button->counter >= FR_COUNTER_MAX) {
            APP_DEBUG(DEBUG_BUTTON_EN, "Reset Factory is ready from level\r\n");
            factory_reset = true;
            light_blink_stop();
            light_on();
            if (timerFactoryResetEvt) {
                TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
            }
            timerFactoryResetEvt = TL_ZB_TIMER_SCHEDULE(factoryResetCb, NULL, TIMEOUT_3SEC);
        } else {
            if (button->hold) {
                APP_DEBUG(DEBUG_BUTTON_EN, "Level. Released button: %d\r\n", i+1);
                app_level_stop(i+1);
            } else {
                APP_DEBUG(DEBUG_BUTTON_EN, "Level. Button %d press %d times\r\n", i+1, button->counter);
                switch(button->counter) {
                    case ACTION_SINGLE:                                         // 1
                        app_cmdOnOff(i+1, cmdOnOff);
                        break;
                    case ACTION_DOUBLE:                                         // 2
                        app_level_step(i+1, up_down);
                        break;
                    case ACTION_QUADRUPLE:                                      // 4
                        batteryCb(NULL);
                        if (!g_appCtx.timerSetPollRateEvt) {
                            app_setPollRate(TIMEOUT_20SEC);
                        }
                        break;
                    default:
                        break;
                }

            }
            clearSleepTimer();
        }

        button->counter = 0;
        BIT_CLR(key->counter, i);
        BIT_CLR(key->pressed, i);
        BIT_CLR(key->released, i);
        button->hold = HOLD_NOT_PRESENT;
    } else if (BIT_IS_SET(key->pressed, i) && button->counter == 1 && button->hold == HOLD_PRESENT) {
        button->hold = HOLD_FIX;
        button->counter = 0;
        BIT_CLR(key->counter, i);
        BIT_CLR(key->pressed, i);
        clearSleepTimer();
    }
}

static void read_button_multifunction(uint8_t i) {
    bool report = false;
    button_t *button = &app_button.button[i];
    app_button_t *key = &app_button;
    zcl_msInputAttr_t *msInputAttr = zcl_msInputAttrsGet();
    msInputAttr += i;

    drv_gpio_output_en(app_button.button[i].row_gpio, 1);
    bool status = drv_gpio_read(app_button.button[i].line_gpio)?true:false;
    drv_gpio_output_en(app_button.button[i].row_gpio, 0);

    if (!status) {
        if (BIT_IS_SET(key->pressed, i)) {
            if (clock_time_exceed(button->hold_time, TIMEOUT_TICK_750MS)) {
                if (button->hold == HOLD_NOT_PRESENT) {
                    button->hold = HOLD_PRESENT;
                    if (!factory_reset) {
                        APP_DEBUG(DEBUG_BUTTON_EN, "Multifunction. Press and hold button: %d\r\n", i+1);
                        msInputAttr->value = ACTION_HOLD;
//                        APP_DEBUG(DEBUG_REPORTING_EN, "MSI report ep: %d value %d\r\n", i+1, msInputAttr->value);
                        app_forcedReport(i+1, ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC, ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE);
                    } else {
                        if (timerFactoryResetEvt) {
                            TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
                        }
                        button_factory_reset_start();
                    }
                }
            }
        }
        if (button->debounce != DEBOUNCE_BUTTON) {
            button->debounce++;
            BIT_SET(key->debounce, i);
            if (button->debounce == DEBOUNCE_BUTTON) {
                BIT_SET(key->pressed, i);
                BIT_CLR(key->debounce, i);
                g_appCtx.not_sleep = true;
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d pressed multifunction\r\n", i+1);
                light_blink_start(1, 30, 1);
                if (!clock_time_exceed(button->pressed_time, TIMEOUT_TICK_500MS)) {
                    button->counter++;
                    BIT_SET(key->counter, i);
                } else {
                    button->counter = 1;
                    BIT_SET(key->counter, i);
                    if (!zb_isDeviceJoinedNwk() && !zb_isDeviceFactoryNew()) {
                        zb_rejoinReq(zb_apsChannelMaskGet(), g_bdbAttrs.scanDuration);
                    }
                }
                button->hold_time = button->pressed_time = clock_time();
            }
        }
    } else {
        if (button->debounce != 1) {
            button->debounce--;
            BIT_SET(key->debounce, i);
            if (button->debounce == 1 && (BIT_IS_SET(key->pressed, i) || button->hold == HOLD_FIX)) {
                BIT_SET(key->released, i);
                BIT_CLR(key->debounce, i);
                g_appCtx.not_sleep = true;
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d released multifunction\r\n", i+1);
            }
        }
    }

    if (BIT_IS_SET(key->released, i) && clock_time_exceed(button->pressed_time, TIMEOUT_TICK_500MS)) {
        if (button->counter >= FR_COUNTER_MAX) {
            APP_DEBUG(DEBUG_BUTTON_EN, "Reset Factory is ready from multifunction\r\n");
            factory_reset = true;
            light_blink_stop();
            light_on();
            if (timerFactoryResetEvt) {
                TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
            }
            timerFactoryResetEvt = TL_ZB_TIMER_SCHEDULE(factoryResetCb, NULL, TIMEOUT_3SEC);
        } else {
            if (button->hold) {
                msInputAttr->value = ACTION_RELEASE;
                report = true;
                APP_DEBUG(DEBUG_BUTTON_EN, "Multifunction. Released button: %d\r\n", i+1);
            } else {
                APP_DEBUG(DEBUG_BUTTON_EN, "Multifunction. Button %d press %d times\r\n", i+1, button->counter);
                switch(button->counter) {
                    case ACTION_SINGLE:                                         // 1
                    case ACTION_DOUBLE:                                         // 2
                    case ACTION_TRIPLE:                                         // 3
                        msInputAttr->value = button->counter;
                        report = true;
                        break;
                    case ACTION_QUADRUPLE:
                        if (button->counter == BATTERY_COUNTER) {
                            batteryCb(NULL);
                            if (!g_appCtx.timerSetPollRateEvt) {
                                app_setPollRate(TIMEOUT_20SEC);
                            }
                        }
                        break;
                    default:
                        break;
                }

            }
            if (report) {
//                APP_DEBUG(DEBUG_REPORTING_EN, "MSI report ep: %d value %d\r\n", i+1, msInputAttr->value);
                app_forcedReport(i+1, ZCL_CLUSTER_GEN_MULTISTATE_INPUT_BASIC, ZCL_MULTISTATE_INPUT_ATTRID_PRESENT_VALUE);
            }
            clearSleepTimer();
        }

        button->counter = 0;
        BIT_CLR(key->counter, i);
        BIT_CLR(key->pressed, i);
        BIT_CLR(key->released, i);
        button->hold = HOLD_NOT_PRESENT;
    } else if (BIT_IS_SET(key->pressed, i) && button->counter == 1 && button->hold == HOLD_PRESENT) {
        button->hold = HOLD_FIX;
        button->counter = 0;
        BIT_CLR(key->counter, i);
        BIT_CLR(key->pressed, i);
        clearSleepTimer();
    }
}

static void read_button_scene(uint8_t i) {
    button_t *button = &app_button.button[i];
    app_button_t *key = &app_button;

    drv_gpio_output_en(app_button.button[i].row_gpio, 1);
    bool status = drv_gpio_read(app_button.button[i].line_gpio)?true:false;
    drv_gpio_output_en(app_button.button[i].row_gpio, 0);

    if (!status) {
        if (BIT_IS_SET(key->pressed, i)) {
            if (clock_time_exceed(button->hold_time, TIMEOUT_TICK_750MS)) {
                if (!button->hold) {
                    button->hold = true;
                    APP_DEBUG(DEBUG_BUTTON_EN, "Scene. Press and hold button: %d\r\n", i+1);
                    if (factory_reset) {
                        if (timerFactoryResetEvt) {
                            TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
                        }
                        button_factory_reset_start();
                    }
                }
            }
        }
        if (button->debounce != DEBOUNCE_BUTTON) {
            button->debounce++;
            BIT_SET(key->debounce, i);
            if (button->debounce == DEBOUNCE_BUTTON) {
                BIT_CLR(key->debounce, i);
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d pressed scene\r\n", i+1);
                light_blink_start(1, 30, 1);
                if (button->counter == 0) {
                    BIT_SET(key->pressed, i);
                    button->counter++;
                    BIT_SET(key->counter, i);
                    g_appCtx.not_sleep = true;
                    if(zb_isDeviceJoinedNwk()) {
                        app_scene_send(i+1);
                    } else if (!zb_isDeviceFactoryNew()) {
                        zb_rejoinReq(zb_apsChannelMaskGet(), g_bdbAttrs.scanDuration);
                    }
                } else if (BIT_IS_SET(key->pressed, i) && !clock_time_exceed(button->pressed_time, TIMEOUT_TICK_750MS)) {
                    button->counter++;
                    if (button->counter >= FR_COUNTER_MAX) {
                        APP_DEBUG(DEBUG_BUTTON_EN, "Reset Factory is ready from scene\r\n");
                        g_appCtx.not_sleep = true;
                        factory_reset = true;
                        light_blink_stop();
                        light_on();
                        if (timerFactoryResetEvt) {
                            TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
                        }
                        timerFactoryResetEvt = TL_ZB_TIMER_SCHEDULE(factoryResetCb, NULL, TIMEOUT_3SEC);
                    }
                }
                button->hold_time = button->pressed_time = clock_time();
            }
        }
    } else {
        if (button->debounce != 1) {
            button->debounce--;
            BIT_SET(key->debounce, i);
            if (button->debounce == 1 && BIT_IS_SET(key->pressed, i)) {
                BIT_SET(key->released, i);
                BIT_CLR(key->debounce, i);
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d released scene\r\n", i+1);
            }
        }
    }

    if (BIT_IS_SET(key->released, i) && clock_time_exceed(button->pressed_time, TIMEOUT_TICK_750MS)) {
        APP_DEBUG(DEBUG_BUTTON_EN, "Scene. Button %d pressed %d times\r\n", i+1, button->counter);
        if (button->counter == BATTERY_COUNTER) {
            batteryCb(NULL);
            if (!g_appCtx.timerSetPollRateEvt) {
                app_setPollRate(TIMEOUT_20SEC);
            }
        }
        clearSleepTimer();
        button->counter = 0;
        BIT_CLR(key->counter, i);
        BIT_CLR(key->pressed, i);
        BIT_CLR(key->released, i);
        button->hold = false;
    }
}

static void read_button_toggle(uint8_t i) {
    uint8_t cmd_onoff;

    button_t *button = &app_button.button[i];
    app_button_t *key = &app_button;

    drv_gpio_output_en(app_button.button[i].row_gpio, 1);
    bool status = drv_gpio_read(app_button.button[i].line_gpio)?true:false;
    drv_gpio_output_en(app_button.button[i].row_gpio, 0);

    if (!status) {
        if (BIT_IS_SET(key->pressed, i)) {
            if (clock_time_exceed(button->hold_time, TIMEOUT_TICK_750MS)) {
                if (button->hold == HOLD_NOT_PRESENT) {
                    button->hold = HOLD_PRESENT;
                    APP_DEBUG(DEBUG_BUTTON_EN, "Toggle. Press and hold button: %d\r\n", i+1);
                    if (factory_reset) {
                        if (timerFactoryResetEvt) {
                            TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
                        }
                        button_factory_reset_start();
                    }
                }
            }
        }
        if (button->debounce != DEBOUNCE_BUTTON) {
            button->debounce++;
            BIT_SET(key->debounce, i);
            if (button->debounce == DEBOUNCE_BUTTON) {
                BIT_CLR(key->debounce, i);
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d pressed toggle\r\n", i+1);
                light_blink_start(1, 30, 1);
                if (button->counter == 0) {
                    button->counter++;
                    BIT_SET(key->counter, i);
                    BIT_SET(key->pressed, i);
                    g_appCtx.not_sleep = true;
                    if(zb_isDeviceJoinedNwk()) {
                        cmd_onoff = ZCL_CMD_ONOFF_ON;
                        switch(device_settings.switchActions[i]) {
                            case ZCL_SWITCH_ACTION_OFF_ON:
                                cmd_onoff = ZCL_CMD_ONOFF_ON;
                                break;
                            case ZCL_SWITCH_ACTION_ON_OFF:
                                cmd_onoff = ZCL_CMD_ONOFF_OFF;
                                break;
                            case ZCL_SWITCH_ACTION_TOGGLE:
                                cmd_onoff = ZCL_CMD_ONOFF_TOGGLE;
                                break;
                            default:
                                break;
                        }
                        app_cmdOnOff(i+1, cmd_onoff);
                    } else if (!zb_isDeviceFactoryNew()) {
                        zb_rejoinReq(zb_apsChannelMaskGet(), g_bdbAttrs.scanDuration);
                    }
                } else if (BIT_IS_SET(key->pressed, i) && !clock_time_exceed(button->pressed_time, TIMEOUT_TICK_750MS)) {
                    button->counter++;
                    if (button->counter >= FR_COUNTER_MAX) {
                        APP_DEBUG(DEBUG_BUTTON_EN, "Reset Factory is ready from toggle\r\n");
                        g_appCtx.not_sleep = true;
                        factory_reset = true;
                        light_blink_stop();
                        light_on();
                        if (timerFactoryResetEvt) {
                            TL_ZB_TIMER_CANCEL(&timerFactoryResetEvt);
                        }
                        timerFactoryResetEvt = TL_ZB_TIMER_SCHEDULE(factoryResetCb, NULL, TIMEOUT_3SEC);
                    }
                }
                button->hold_time = button->pressed_time = clock_time();
            }
        }
    } else {
        if (button->debounce != 1) {
            button->debounce--;
            BIT_SET(key->debounce, i);
            if (button->debounce == 1 && (BIT_IS_SET(key->pressed, i) || button->hold == HOLD_FIX)) {
                BIT_CLR(key->debounce, i);
                BIT_SET(key->released, i);
                g_appCtx.not_sleep = true;
//                APP_DEBUG(DEBUG_BUTTON_EN, "Key %d released toggle\r\n", i+1);
                if((button->counter == 1 || button->hold == HOLD_FIX) && zb_isDeviceJoinedNwk()) {
                    if (device_settings.switchType[i] == ZCL_SWITCH_TYPE_MOMENTARY) {
                        cmd_onoff = ZCL_SWITCH_ACTION_ON_OFF;
                        switch(device_settings.switchActions[i]) {
                            case ZCL_SWITCH_ACTION_OFF_ON:
                                cmd_onoff = ZCL_CMD_ONOFF_OFF;
                                break;
                            case ZCL_SWITCH_ACTION_ON_OFF:
                                cmd_onoff = ZCL_CMD_ONOFF_ON;
                                break;
                            case ZCL_SWITCH_ACTION_TOGGLE:
                                cmd_onoff = ZCL_CMD_ONOFF_TOGGLE;
                                break;
                            default:
                                break;
                        }
                        app_cmdOnOff(i+1, cmd_onoff);
                    }
                }
            }
        }
    }

    if (BIT_IS_SET(key->released, i) && clock_time_exceed(button->pressed_time, TIMEOUT_TICK_750MS)) {
        APP_DEBUG(DEBUG_BUTTON_EN, "Toggle. Button %d pressed %d times\r\n", i+1, button->counter);
        if (button->counter == BATTERY_COUNTER) {
            batteryCb(NULL);
            if (!g_appCtx.timerSetPollRateEvt) {
                app_setPollRate(TIMEOUT_20SEC);
            }
        }
        clearSleepTimer();
        button->counter = 0;
        BIT_CLR(key->counter, i);
        BIT_CLR(key->pressed, i);
        BIT_CLR(key->released, i);
        button->hold = HOLD_NOT_PRESENT;
    } else if (BIT_IS_SET(key->pressed, i) && button->counter == 1 && button->hold == HOLD_PRESENT) {
        button->hold = HOLD_FIX;
        button->counter = 0;
        BIT_CLR(key->counter, i);
        BIT_CLR(key->pressed, i);
        clearSleepTimer();
    }
}


void button_handler() {
    for (uint8_t i = 0; i < app_button.key_num; i++) {
        switch(device_settings.switchType[i]) {
            case ZCL_SWITCH_TYPE_TOGGLE:
            case ZCL_SWITCH_TYPE_MOMENTARY:
                read_button_toggle(i);
                break;
            case ZCL_SWITCH_TYPE_MULTIFUNCTION:
                read_button_multifunction(i);
                break;
            case ZCL_CUSTOM_SWITCH_TYPE_LEVEL_MOVE_UP:
            case ZCL_CUSTOM_SWITCH_TYPE_LEVEL_MOVE_DOWN:
                read_button_level(i);
                break;
            case ZCL_CUSTOM_SWITCH_TYPE_SCENE:
                read_button_scene(i);
                break;
            default:
                break;
        }
    }
}

uint8_t button_idle() {
    app_button_t *key = &app_button;

    if (key->debounce || key->pressed || key->counter) return true;

    return false;
}

void button_clear_sleep() {
    if (timerClearSleepEvt) TL_ZB_TIMER_CANCEL(&timerClearSleepEvt);
}

void button_init() {

    memset(&app_button, 0, sizeof(app_button_t));

    uint8_t row_num, line_num;

    switch(device_model) {
        case DEVICE_BUTTON_8:
            row_num = 2;
            line_num = 4;
            break;
        case DEVICE_BUTTON_12:
            row_num = 3;
            line_num = 4;
            break;
        case DEVICE_BUTTON_20:
            row_num = 4;
            line_num = 5;
            break;
        default:
            row_num = 2;
            line_num = 4;
            break;
    }


    for (uint8_t ir = 0; ir < row_num; ir++) {
        for (uint8_t il = 0; il < line_num; il++) {
            if (ir == 0) app_button.button[app_button.key_num].row_gpio = ROW1_GPIO;
            else if (ir == 1) app_button.button[app_button.key_num].row_gpio = ROW2_GPIO;
            else if (ir == 2) app_button.button[app_button.key_num].row_gpio = ROW3_GPIO;
            else app_button.button[app_button.key_num].row_gpio = ROW4_GPIO;
            if (il == 0) app_button.button[app_button.key_num].line_gpio = LINE1_GPIO;
            else if (il == 1) app_button.button[app_button.key_num].line_gpio = LINE2_GPIO;
            else if (il == 2) app_button.button[app_button.key_num].line_gpio = LINE3_GPIO;
            else if (il == 3) app_button.button[app_button.key_num].line_gpio = LINE4_GPIO;
            else app_button.button[app_button.key_num].line_gpio = LINE5_GPIO;
            app_button.button[app_button.key_num].debounce = 1;
            app_button.button[app_button.key_num++].pressed_time = clock_time();
        }
    }
}
