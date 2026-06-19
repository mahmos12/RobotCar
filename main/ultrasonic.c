#include "ultrasonic.h"

#include "driver/gpio.h"
#include "esp_timer.h"
#include "esp_rom_sys.h"

#define TRIG_PIN 21
#define ECHO_PIN 20

static int64_t read_distance_us(void)
{
    int64_t t0;

    gpio_set_level(TRIG_PIN, 1);
    esp_rom_delay_us(10);
    gpio_set_level(TRIG_PIN, 0);

    t0 = esp_timer_get_time();

    while (gpio_get_level(ECHO_PIN) == 0)
    {
        if (esp_timer_get_time() - t0 > 20000)
            return -1;
    }

    int64_t start = esp_timer_get_time();

    t0 = esp_timer_get_time();

    while (gpio_get_level(ECHO_PIN) == 1)
    {
        if (esp_timer_get_time() - t0 > 20000)
            return -1;
    }

    int64_t stop = esp_timer_get_time();

    return stop - start;
}

void ultrasonic_init(void)
{
    gpio_config_t trig = {
        .pin_bit_mask = 1ULL << TRIG_PIN,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };

    gpio_config(&trig);

    gpio_config_t echo = {
        .pin_bit_mask = 1ULL << ECHO_PIN,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };

    gpio_config(&echo);
}

int ultrasonic_get_distance_cm(void)
{
    int64_t time_us = read_distance_us();

    if (time_us < 0)
        return -1;

    return time_us / 58;
}