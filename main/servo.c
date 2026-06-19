#include "servo.h"
#include "driver/mcpwm_prelude.h"

#define SERVO_PIN 8

static mcpwm_timer_handle_t timer = NULL;
static mcpwm_oper_handle_t oper = NULL;
static mcpwm_cmpr_handle_t cmpr = NULL;
static mcpwm_gen_handle_t generator = NULL;

static int angle_to_compare(int angle)
{
    return 500 + (angle * 2000) / 180;
}

void servo_init(void)
{
    mcpwm_timer_config_t timcfg = {
        .group_id = 0,
        .clk_src = MCPWM_TIMER_CLK_SRC_DEFAULT,
        .resolution_hz = 1000000,
        .period_ticks = 20000,
        .count_mode = MCPWM_TIMER_COUNT_MODE_UP,
    };

    mcpwm_new_timer(&timcfg, &timer);

    mcpwm_operator_config_t operator_cfg = {
        .group_id = 0,
    };

    mcpwm_new_operator(&operator_cfg, &oper);

    mcpwm_operator_connect_timer(oper, timer);

    mcpwm_comparator_config_t cmpr_cfg = {
        .flags.update_cmp_on_tez = true,
    };

    mcpwm_new_comparator(oper, &cmpr_cfg, &cmpr);

    mcpwm_generator_config_t generator_cfg = {
        .gen_gpio_num = SERVO_PIN,
    };

    mcpwm_new_generator(oper, &generator_cfg, &generator);

    mcpwm_generator_set_action_on_timer_event(
        generator,
        MCPWM_GEN_TIMER_EVENT_ACTION(
            MCPWM_TIMER_DIRECTION_UP,
            MCPWM_TIMER_EVENT_EMPTY,
            MCPWM_GEN_ACTION_HIGH));

    mcpwm_generator_set_action_on_compare_event(
        generator,
        MCPWM_GEN_COMPARE_EVENT_ACTION(
            MCPWM_TIMER_DIRECTION_UP,
            cmpr,
            MCPWM_GEN_ACTION_LOW));

    mcpwm_timer_enable(timer);
    mcpwm_timer_start_stop(timer, MCPWM_TIMER_START_NO_STOP);
}

void servo_set_angle(int angle)
{
    mcpwm_comparator_set_compare_value(cmpr, angle_to_compare(angle));
}