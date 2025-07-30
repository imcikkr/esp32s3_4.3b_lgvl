/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "waveshare_rgb_lcd_port.h"
#include "ui.h"


void func_countUp(lv_event_t *e)
{
    // Your code here 러하러ㅣㅓㅣㅇ라ㅓ히ㅏㅣ렇리ㅏㄹ하ㅣㅓ라ㅣ;ㅓ히ㅏㅁㄴㅇ리;ㅎ리;ㅓㅎㄹ;ㅐ
    lv_label_set_text(ui_LblScreen, "button1 pressed");
}

void func_countDown(lv_event_t *e)
{
    // Your code here
    lv_label_set_text(ui_LblScreen, "button2 pressed");
}

void app_main()
{
    waveshare_esp32_s3_rgb_lcd_init(); // Initialize the Waveshare ESP32-S3 RGB LCD 
    // wavesahre_rgb_lcd_bl_on();  //Turn on the screen backlight 
    // wavesahre_rgb_lcd_bl_off(); //Turn off the screen backlight 
   
    ESP_LOGI(TAG, "Display LVGL demos");
    // Lock the mutex due to the LVGL APIs are not thread-safe
    if (lvgl_port_lock(-1)) {
        // lv_demo_stress();
        // lv_demo_benchmark();
        // lv_demo_music();
#if CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_GT911
        //lv_demo_widgets();
#else
        lv_demo_music();
#endif
        // example_lvgl_demo_ui();
         ui_init();
        //Release the mutex
        lvgl_port_unlock();
    }
}
