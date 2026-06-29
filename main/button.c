#include "button.h"

#define ON_OFF_PIN 5


void button_init(){
    gpio_config_t cfg = {
        .pin_bit_mask = (1ULL << ON_OFF_PIN),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&cfg);
}

bool button_pressed(void){
    return gpio_get_level(ON_OFF_PIN) == 0;
}