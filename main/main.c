#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "motor.h"
#include "servo.h"
#include "ultrasonic.h"


void app_main(void){
    servo_init();
    ultrasonic_init();
    motor_init();

    int distance = 0;

    while (1)
    {
        // scan forward
        for(int i = 0; i <= 180; i++){
            servo_set_angle(i);
            distance = ultrasonic_get_distance_cm();

            printf("Distance: %d\n", distance);

            if(distance > 20){
                motor_forward();
            } else {
                motor_stop();
            }

            vTaskDelay(pdMS_TO_TICKS(25));
        }

        // scan back
        for(int i = 180; i >= 0; i--){
            servo_set_angle(i);
            distance = ultrasonic_get_distance_cm();

            printf("Distance: %d\n", distance);

            if(distance > 20){
                motor_forward();
            } else {
                motor_stop();
            }

            vTaskDelay(pdMS_TO_TICKS(25));
        }
    }
}