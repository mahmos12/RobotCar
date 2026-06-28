#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "motor.h"
#include "servo.h"
#include "ultrasonic.h"
#include "button.h"

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "motor.h"
#include "servo.h"
#include "ultrasonic.h"

void app_main(void)
{
    
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
