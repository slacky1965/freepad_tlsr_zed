#ifndef SRC_INCLUDE_APP_BUTTON_H_
#define SRC_INCLUDE_APP_BUTTON_H_

typedef enum {
    ACTION_HOLD = 0,
    ACTION_SINGLE,
    ACTION_DOUBLE,
    ACTION_TRIPLE,
    ACTION_QUADRUPLE,
    ACTION_CLEAR = 250,
    ACTION_RELEASE = 255,
    ACTION_EMPTY = 300,
} switch_action_t;

extern bool factory_reset;

//static inline unsigned int gpio_read_cache(u32 pin, u8 *p) {
//    return p[pin>>8] & (pin & 0xff);
//}

void button_handler();
bool button_idle();
void button_init();
void button_clear_sleep();

#endif /* SRC_INCLUDE_APP_BUTTON_H_ */
