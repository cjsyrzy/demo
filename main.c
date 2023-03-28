
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

// #include "lvgl/lvgl.h"
// #include "lvgl/demos/lv_demos.h"
// #include "lv_drivers/win32drv/win32drv.h"

#include "delay.h"
#include "com.h"
#include "lin.h"

/*********************
 *      DEFINES
 *********************/
// #define HOR_RES 100
// #define VER_RES 40
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
// static lv_disp_drv_t disp_drv;
// static lv_disp_draw_buf_t draw_buf;
// static lv_color_t disp_buf1[HOR_RES * VER_RES];
// uint8_t buf[HOR_RES * VER_RES + 100];
// static lv_disp_t *dispplay = NULL;

// uint8_t enable_display = 0;

// static void flush_cb(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
// {
//     LV_UNUSED(area);
//     LV_UNUSED(color_p);

//     static int i, j;
//     int k = 0;

//     for (j = area->y1; j <= area->y2; j++)
//     {
//         for (i = area->x1; i <= area->x2; i++)
//         {
//             // buf[j * HOR_RES + i].full = color_p->full;

//             // if(color_p->full == 255)
//             // {
//             //     buf[k++] = ' ';
//             // }
//             // else
//             // {
//             //     buf[k++] = '1';
//             // }

//             if ((color_p->ch.blue > 0) && (color_p->ch.red > 0) && (color_p->ch.green > 0))
//             {
//                 buf[k++] = ' ';
//             }
//             else
//             {
//                 buf[k++] = '1';
//             }

//             // if (color_p->ch.red == 0)
//             // {
//             //     buf[k++] = '1';
//             // }
//             // else
//             // {
//             //     if (color_p->ch.blue == 0)
//             //         buf[k++] = '1';
//             //     else
//             //         buf[k++] = ' ';
//             // }
//             color_p++;
//         }
//         buf[k++] = '\r';
//         buf[k++] = '\n';
//     }
//     buf[k] = 0;

//     if (enable_display)
//     {
//         puts(buf);
//     }

//     // printf("x1 = %d", area->x1);
//     // printf("x2 = %d", area->x2);
//     // printf("y1 = %d", area->y1);
//     // printf("y2 = %d", area->y2);
//     // printf("\r\n");

//     // if (((area->x1 == 0) && (area->x2 == HOR_RES)) && ((area->y1 == 0) && (area->y2 == VER_RES)))
//     // {
//     //     printf("full");
//     // }
//     // else
//     // {
//     //     printf("not full");
//     // }

//     // i = 0;
//     // do
//     // {
//     //     if(i%HOR_RES == 0)
//     //         printf("\r\n");

//     //     if(color_p[i].full)
//     //     {
//     //         putchar('8');
//     //     }
//     //     else
//     //     {
//     //         putchar(' ');
//     //     }
//     // } while (++ i < HOR_RES*VER_RES);

//     lv_disp_flush_ready(disp_drv);
// }

// static void hal_init(void)
// {
//     memset(buf, 0, sizeof(buf));

//     lv_disp_draw_buf_init(&draw_buf, disp_buf1, NULL, HOR_RES * VER_RES);

//     lv_disp_drv_init(&disp_drv);
//     disp_drv.draw_buf = &draw_buf;
//     disp_drv.flush_cb = flush_cb;
//     disp_drv.hor_res = HOR_RES;
//     disp_drv.ver_res = VER_RES;
//     // disp_drv.full_refresh = 1;
//     // disp_drv.direct_mode = 1;
//     dispplay = lv_disp_drv_register(&disp_drv);
//     // if(dispplay != NULL)
//     // {
//     //     printf("create display ok\r\n");
//     // }

//     // static lv_indev_drv_t indev_mouse_drv;
//     // lv_indev_drv_init(&indev_mouse_drv);
//     // indev_mouse_drv.type = LV_INDEV_TYPE_POINTER;
//     // indev_mouse_drv.read_cb = lv_test_mouse_read_cb;
//     // lv_test_mouse_indev = lv_indev_drv_register(&indev_mouse_drv);

//     // static lv_indev_drv_t indev_keypad_drv;
//     // lv_indev_drv_init(&indev_keypad_drv);
//     // indev_keypad_drv.type = LV_INDEV_TYPE_KEYPAD;
//     // indev_keypad_drv.read_cb = lv_test_keypad_read_cb;
//     // lv_test_keypad_indev = lv_indev_drv_register(&indev_keypad_drv);

//     // static lv_indev_drv_t indev_encoder_drv;
//     // lv_indev_drv_init(&indev_encoder_drv);
//     // indev_encoder_drv.type = LV_INDEV_TYPE_ENCODER;
//     // indev_encoder_drv.read_cb = lv_test_encoder_read_cb;
//     // lv_test_encoder_indev = lv_indev_drv_register(&indev_encoder_drv);
// }

// static void my_widget(void)
// {
//     // lv_obj_t * label1 = lv_label_create(lv_scr_act());
//     // lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
//     // lv_label_set_recolor(label1, true);                      /*Enable re-coloring by commands in the text*/
//     // lv_label_set_text(label1, "#0000ff Re-color# #ff00ff words# #ff0000 of a# label, align the lines to the center "
//     //                   "and wrap long text automatically.");
//     // lv_obj_set_width(label1, 150);  /*Set smaller width to make the lines wrap*/
//     // lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
//     // lv_obj_align(label1, LV_ALIGN_CENTER, 0, -40);

//     lv_obj_t *label2 = lv_label_create(lv_scr_act());
//     lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
//     lv_obj_set_width(label2, 80);
//     lv_label_set_text(label2, "It is a circularly scrolling text. ");
//     lv_obj_align(label2, LV_ALIGN_CENTER, 0, 0);

//     // lv_obj_t *ta = lv_textarea_create(lv_scr_act());
//     // lv_textarea_set_text(ta, "ABCDE abcde");
//     // lv_obj_set_size(ta, 148, 40);
//     // lv_obj_align(ta, LV_ALIGN_CENTER, 0, 0);
// }

// static void lv_example_gif_1(void)
// {
//     // LV_IMG_DECLARE(img_bulb_gif);
//     lv_obj_t *img;

//     // img = lv_gif_create(lv_scr_act());
//     // lv_gif_set_src(img, &img_bulb_gif);
//     // lv_obj_align(img, LV_ALIGN_LEFT_MID, 20, 0);

//     img = lv_gif_create(lv_scr_act());
//     /* Assuming a File system is attached to letter 'A'
//      * E.g. set LV_USE_FS_STDIO 'A' in lv_conf.h */
//     lv_gif_set_src(img, "C:/Users/zhang.yu126/Desktop/display/test.gif");
//     lv_obj_align(img, LV_ALIGN_RIGHT_MID, 0, 0);
// }

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nCmdShow)
{
    printf("project start\r\n");

    /*Initialize LittlevGL*/
    // lv_init();

    /*Initialize the HAL for LittlevGL*/
    // lv_win32_init(hInstance, SW_SHOWNORMAL, 800, 480, NULL);

    /*Output prompt information to the console, you can also use printf() to print directly*/
    // LV_LOG_USER("LVGL initialization completed!");
    // lv_demo_widgets();
    // lv_demo_benchmark();
    // lv_demo_music();
    // lv_demo_stress();

    /*Run the demo*/
    // my_widget();
    // lv_example_gif_1();

    // if (strcmp("1", szCmdLine) == 0)
    // {
    //     enable_display = 1;
    // }

    // printf("struct size a %d\r\n",sizeof(struct a));
    uint8_t dat[8] = {0x9d, 0xff, 0xf9, 0x20, 0x64, 0x00, 0x00, 0x00};
    uint8_t dat2[8] = {0x9d, 0xff, 0xf9, 0x20, 0x00, 0x00, 0x00, 0x00};
    while (1)
    {
        com_init(7, 460800);
        // com_init(7, 19200);
        lin_init();
        delay_ms(100);
        lin_write(0x03,dat,1);
        // lin_read(0x03,dat,1);
        printf("delay 1000 ms\r\n");
        delay_ms(1000);
        lin_write(0x03,dat2,1);
        com_close();
        return 0;
    }
}
