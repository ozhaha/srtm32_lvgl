//
// Created by ozcom on 2022/5/15.
//

#include "lv_drv.h"
#include "../lvgl.h"
#include "log.h"

#define MY_DISP_HOR_RES DISP_HOR_RES
#define MY_DISP_VER_RES DISP_VER_RES

static void disp_init();

static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

void lv_drv_init(void) {

    disp_init();

    static lv_disp_draw_buf_t draw_buf_dsc_1;
    static lv_color_t buf_1[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
    static lv_color_t buf_2[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
    lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, buf_2, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/

    /* Example for 2) */
//    static lv_disp_draw_buf_t draw_buf_dsc_2;
//    static lv_color_t buf_2_1[MY_DISP_HOR_RES * 10];                        /*A buffer for 10 rows*/
//    static lv_color_t buf_2_2[MY_DISP_HOR_RES * 10];                        /*An other buffer for 10 rows*/
//    lv_disp_draw_buf_init(&draw_buf_dsc_2, buf_2_1, buf_2_2, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/

    /* Example for 3) also set disp_drv.full_refresh = 1 below*/
//    static lv_disp_draw_buf_t draw_buf_dsc_3;
//    static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*A screen sized buffer*/
//    static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*Another screen sized buffer*/
//    lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2,
//                          MY_DISP_VER_RES * LV_VER_RES_MAX);   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LVGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES;
    disp_drv.ver_res = MY_DISP_VER_RES;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf_dsc_1;

    /*Required for Example 3)*/
    //disp_drv.full_refresh = 1

    /* Fill a memory array with a color if you have GPU.
     * Note that, in lv_conf.h you can enable GPUs that has built-in support in LVGL.
     * But if you have a different GPU you can use with this callback.*/
    //disp_drv.gpu_fill_cb = gpu_fill;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

#if USE_GC9A01
#include "display/GC9A01.h"
#endif

#if USE_ST7565

#include "display/ST7565.h"

#endif

#if USE_SSD1963
#include "display/SSD1963.h"
#endif


static void disp_init() {

#if USE_GC9A01
    GC9A01_init();
#endif

#if USE_ST7565
    st7565_init();
#endif

#if USE_SSD1963
    SSD1963_init();
#endif


}

static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {

#if USE_GC9A01
    GC9A01_flush(disp_drv, area, color_p);
#endif

#if USE_ST7565
    st7565_flush(disp_drv, area, color_p);
#endif

#if USE_SSD1963
    SSD1963_flush(disp_drv, area, color_p);
#endif

//    LOGD("---disp_flush--->{x1=%d,y1=%d,x2=%d,y2=%d}", area->x1, area->y1, area->x2, area->y2);

    lv_disp_flush_ready(disp_drv);
}