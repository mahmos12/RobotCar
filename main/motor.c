#include "motor.h"
#include "driver/gpio.h"

#define IN1_PIN 12
#define IN2_PIN 13
#define IN3_PIN 11
#define IN4_PIN 10

void motor_init(void)
{
    gpio_config_t cfg = {
        .pin_bit_mask =
            (1ULL << IN1_PIN) |
            (1ULL << IN2_PIN) |
            (1ULL << IN3_PIN) |
            (1ULL << IN4_PIN),
        .mode = GPIO_MODE_OUTPUT
    };

    gpio_config(&cfg);
}

void motor_forward(void)
{
    gpio_set_level(IN1_PIN, 1);
    gpio_set_level(IN2_PIN, 0);
    gpio_set_level(IN3_PIN, 1);
    gpio_set_level(IN4_PIN, 0);
}

void motor_backward(void)
{
    gpio_set_level(IN1_PIN, 0);
    gpio_set_level(IN2_PIN, 1);
    gpio_set_level(IN3_PIN, 0);
    gpio_set_level(IN4_PIN, 1);
}

void motor_stop(void)
{
    gpio_set_level(IN1_PIN, 0);
    gpio_set_level(IN2_PIN, 0);
    gpio_set_level(IN3_PIN, 0);
    gpio_set_level(IN4_PIN, 0);
}

void motor_right_forward(void)
{
    gpio_set_level(IN1_PIN, 0);
    gpio_set_level(IN2_PIN, 1);
    gpio_set_level(IN3_PIN, 1);
    gpio_set_level(IN4_PIN, 0);
}

void motor_left_forward(void)
{
    gpio_set_level(IN1_PIN, 1);
    gpio_set_level(IN2_PIN, 0);
    gpio_set_level(IN3_PIN, 0);
    gpio_set_level(IN4_PIN, 1);
}

void motor_left_backward(void)
{
    gpio_set_level(IN1_PIN, 0);
    gpio_set_level(IN2_PIN, 1);
    gpio_set_level(IN3_PIN, 1);
    gpio_set_level(IN4_PIN, 0);
}

void motor_right_backward(void)
{
    gpio_set_level(IN1_PIN, 1);
    gpio_set_level(IN2_PIN, 0);
    gpio_set_level(IN3_PIN, 0);
    gpio_set_level(IN4_PIN, 1);
}