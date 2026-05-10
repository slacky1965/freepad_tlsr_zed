#ifndef SRC_INCLUDE_APP_COLOR_TEMP_H_
#define SRC_INCLUDE_APP_COLOR_TEMP_H_

enum {
    COLOR_TEMPERATURE_COOLEST = 153,
    COLOR_TEMPERATURE_COOL    = 250,
    COLOR_TEMPERATURE_NEUTRAL = 370,
    COLOR_TEMPERATURE_WARM    = 454,
    COLOR_TEMPERATURE_WARMEST = 500
};

#define STEP_COLOR_NUM          5
#define STEP_COLOR_TEMP         {COLOR_TEMPERATURE_COOLEST, COLOR_TEMPERATURE_COOL, COLOR_TEMPERATURE_NEUTRAL, COLOR_TEMPERATURE_WARM, COLOR_TEMPERATURE_WARMEST}
#define COLOR_MOVE_UP           0x00
#define COLOR_MOVE_DOWN         0x01
#define COLOR_MOVE_ALTERNATE    0x02
#define COLOR_MOVE_ALT_UP       0x10
#define COLOR_MOVE_ALT_DOWN     0x11
#define COLOR_MOVE_ALT_BIT      4
#define colorCtrlMove2CTCmd_t   zcl_colorCtrlMoveToColorTemperatureCmd_t
#define colorCtrlStopCmd_t      zcl_colorCtrlStopMoveStepCmd_t
#define colorCtrlStepCTCmd_t    zcl_colorCtrlStepColorTemperatureCmd_t

void app_color_move_to_temp(uint8_t ep, uint8_t up_down);
void app_color_stop_step(uint8_t ep);
void app_color_step_temp(uint8_t ep, uint8_t up_down);
int32_t app_repeatCmdColorCtrl(void *args);

#endif /* SRC_INCLUDE_APP_COLOR_TEMP_H_ */
