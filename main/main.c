#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "motor.h"
#include "servo.h"
#include "ultrasonic.h"



// void app_main(void){
//     servo_init();

//     while (1)
//     {
//         for(int i = 0; i<180;i++){
//             servo_set_angle(i);
//             vTaskDelay(pdMS_TO_TICKS(17));
//         }
//         for(int i = 180; i>0;i--){
//             servo_set_angle(i);
//             vTaskDelay(pdMS_TO_TICKS(17));
//         }
//     }
    
// }



// void app_main(void)
// {
//     motor_init();

//     while (1)
//     {
//         motor_forward();
//         vTaskDelay(pdMS_TO_TICKS(3000));

//         motor_stop();
//         vTaskDelay(pdMS_TO_TICKS(3000));

//         motor_left_forward();
//         vTaskDelay(pdMS_TO_TICKS(3000));

//         motor_stop();
//         vTaskDelay(pdMS_TO_TICKS(3000));
        
//         motor_right_forward();
//         vTaskDelay(pdMS_TO_TICKS(3000));

        
//         motor_stop();
//         vTaskDelay(pdMS_TO_TICKS(3000));


//     }
// }
