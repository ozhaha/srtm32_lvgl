//
// Created by ozcom on 2022/5/14.
//
#include "tim.h"
#include "log.h"
#include "gui/lvgl.h"


uint32_t my_lv_tick_count = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

    if (htim == &htim6) {
        /* lvgl心跳 */
        lv_tick_inc(1);
        my_lv_tick_count++;
    }

}