#include "button.h"
#include "driver/gpio.h"

#define ON_OFF_PIN 5




gpio_config_t cfg = {
    .pin_bit_mask = (1ULL << ON_OFF_PIN),
    .mode = GPIO_MODE_INPUT,
    .pull_up_en = GPIO_PULLUP_ENABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE,
};
gpio_config(&cfg);

void button_on(){
    gpio_set_level(ON_OFF_PIN,1);

}

void button_off(){
    gpio_set_level(ON_OFF_PIN,0);

}