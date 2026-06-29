#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "motor.h"
#include "servo.h"
#include "ultrasonic.h"
#include "button.h"

bool system_on = false;
bool last_button = false;

void app_main(void)
{
    button_init();
    servo_init();
    ultrasonic_init();
    motor_init();

    int distance;
    int front;
    int left;
    int right;

    while (1){
        bool current_button = button_pressed();

        if (current_button && !last_button)
        {
            vTaskDelay(pdMS_TO_TICKS(20));

            if (button_pressed()){
                system_on = !system_on;

                if (system_on){
                    printf("System ON\n");
                }else{
                    printf("System OFF\n");
                    motor_stop();
                }
            }
        }

        last_button = current_button;
        last_button = current_button;
        if(system_on){
            //   --------------------
            // SCAN FORWARD
            // --------------------
            front = 1000;

            servo_set_angle(35);
            vTaskDelay(pdMS_TO_TICKS(40));
            distance = ultrasonic_get_distance_cm();
            if (distance < front)
                front = distance;

            servo_set_angle(90);
            vTaskDelay(pdMS_TO_TICKS(40));
            distance = ultrasonic_get_distance_cm();
            if (distance < front)
                front = distance;

            servo_set_angle(135);
            vTaskDelay(pdMS_TO_TICKS(40));
            distance = ultrasonic_get_distance_cm();
            if (distance < front)
                front = distance;

            printf("Front sector: %d\n", front);

            // --------------------
            // FREE
            // --------------------
            if (front > 20)
            {
                motor_forward();
                vTaskDelay(pdMS_TO_TICKS(100));
                continue;
            }

            // --------------------
            // HINDER
            // --------------------
            motor_stop();
            vTaskDelay(pdMS_TO_TICKS(200));

            // check left
            servo_set_angle(0);
            vTaskDelay(pdMS_TO_TICKS(300));
            left = ultrasonic_get_distance_cm();

            // check right
            servo_set_angle(180);
            vTaskDelay(pdMS_TO_TICKS(300));
            right = ultrasonic_get_distance_cm();

            printf("Left: %d Right: %d\n", left, right);

            // back to medel
            servo_set_angle(90);
            vTaskDelay(pdMS_TO_TICKS(200));

            // --------------------
            // dessition
            // --------------------
            if (left > right && left > 20)
            {
                motor_backward();
                vTaskDelay(pdMS_TO_TICKS(200));
                motor_left_forward();
                vTaskDelay(pdMS_TO_TICKS(500));
            }
            else if (right > 20)
            {
                motor_backward();
                vTaskDelay(pdMS_TO_TICKS(200));
                motor_right_forward();
                vTaskDelay(pdMS_TO_TICKS(500));
            }
            else
            {
                motor_backward();
                vTaskDelay(pdMS_TO_TICKS(500));

                motor_left_backward();
                vTaskDelay(pdMS_TO_TICKS(500));
            }

            motor_stop();
            vTaskDelay(pdMS_TO_TICKS(100));
        }

    }
    vTaskDelay(pdMS_TO_TICKS(20));
}

    


// void app_main(void)
// {
//     servo_init();
//     ultrasonic_init();
//     motor_init();

//     int distance;
//     int front;
//     int left;
//     int right;

//     while (1)
//     {
//         // --------------------
//         // SCAN FORWARD
//         // --------------------
//         front = 1000;

//         servo_set_angle(35);
//         vTaskDelay(pdMS_TO_TICKS(40));
//         distance = ultrasonic_get_distance_cm();
//         if (distance < front)
//             front = distance;

//         servo_set_angle(90);
//         vTaskDelay(pdMS_TO_TICKS(40));
//         distance = ultrasonic_get_distance_cm();
//         if (distance < front)
//             front = distance;

//         servo_set_angle(135);
//         vTaskDelay(pdMS_TO_TICKS(40));
//         distance = ultrasonic_get_distance_cm();
//         if (distance < front)
//             front = distance;

//         printf("Front sector: %d\n", front);

//         // --------------------
//         // FREE
//         // --------------------
//         if (front > 20)
//         {
//             motor_forward();
//             vTaskDelay(pdMS_TO_TICKS(100));
//             continue;
//         }

//         // --------------------
//         // HINDER
//         // --------------------
//         motor_stop();
//         vTaskDelay(pdMS_TO_TICKS(200));

//         // check left
//         servo_set_angle(0);
//         vTaskDelay(pdMS_TO_TICKS(300));
//         left = ultrasonic_get_distance_cm();

//         // check right
//         servo_set_angle(180);
//         vTaskDelay(pdMS_TO_TICKS(300));
//         right = ultrasonic_get_distance_cm();

//         printf("Left: %d Right: %d\n", left, right);

//         // back to medel
//         servo_set_angle(90);
//         vTaskDelay(pdMS_TO_TICKS(200));

//         // --------------------
//         // dessition
//         // --------------------
//         if (left > right && left > 20)
//         {
//             motor_backward();
//             vTaskDelay(pdMS_TO_TICKS(200));
//             motor_left_forward();
//             vTaskDelay(pdMS_TO_TICKS(500));
//         }
//         else if (right > 20)
//         {
//             motor_backward();
//             vTaskDelay(pdMS_TO_TICKS(200));
//             motor_right_forward();
//             vTaskDelay(pdMS_TO_TICKS(500));
//         }
//         else
//         {
//             motor_backward();
//             vTaskDelay(pdMS_TO_TICKS(500));

//             motor_left_backward();
//             vTaskDelay(pdMS_TO_TICKS(500));
//         }

//         motor_stop();
//         vTaskDelay(pdMS_TO_TICKS(100));
//     }
// }
