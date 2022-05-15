//
// Created by ozcom on 2022/5/15.
//

#include "app.h"

#include "lv_demos.h"
#include "../gui/lvgl.h"

#define USE_MY_CUSTOM_LV_DEMO 0

static void custom_lv_demo();

void app_run(void) {

#if LV_USE_DEMO_WIDGETS
    lv_demo_widgets();
#endif

#if LV_USE_DEMO_MUSIC
    lv_demo_music();
#endif

#if USE_MY_CUSTOM_LV_DEMO
    custom_lv_demo();
#endif

}

static void btn_event_cb(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;

        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

static void custom_lv_demo() {

    lv_obj_t *btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/

    lv_obj_t *label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/
    lv_obj_center(label);

}