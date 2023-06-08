// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: OpenHT_UI

#include "../ui.h"

void ui_screen_scratchpad_1_screen_init(void)
{
    ui_screen_scratchpad_1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_screen_scratchpad_1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_about_panel = lv_obj_create(ui_screen_scratchpad_1);
    lv_obj_set_width(ui_about_panel, 420);
    lv_obj_set_height(ui_about_panel, 660);
    lv_obj_set_align(ui_about_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_about_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_grad_color(ui_about_panel, lv_color_hex(0x464B55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_about_panel, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_about_panel, lv_color_hex(0x191C26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_about_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_about_tab_panel = lv_obj_create(ui_about_panel);
    lv_obj_set_width(ui_about_tab_panel, 400);
    lv_obj_set_height(ui_about_tab_panel, 430);
    lv_obj_set_x(ui_about_tab_panel, 0);
    lv_obj_set_y(ui_about_tab_panel, 35);
    lv_obj_set_align(ui_about_tab_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_about_tab_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_about_tab_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_about_tab_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_about_tab_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_about_tab_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_about_tab_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_about_tab_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_about_tab_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_about_text_area = lv_textarea_create(ui_about_tab_panel);
    lv_obj_set_width(ui_about_text_area, lv_pct(100));
    lv_obj_set_height(ui_about_text_area, lv_pct(100));
    lv_textarea_set_text(ui_about_text_area,
                         "OpenHT is an Open Source handheld two-way radio designed by and for Amateur Radio operators. It showcases freely available open source digital protocols for voice and data. FreeDV and M17 are first class citizens with additional support for FM/AM/SSB.\n\nThis is the Unicorn you've been waiting for, so what are you waiting for?\n\n73,\nM17 Project");
    lv_obj_clear_flag(ui_about_text_area,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_about_text_area, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_color(ui_about_text_area, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_about_text_area, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_about_text_area, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_about_text_area, lv_color_hex(0x464B55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_about_text_area, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_about_text_area, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_about_hw_text_area = lv_textarea_create(ui_about_tab_panel);
    lv_obj_set_width(ui_about_hw_text_area, lv_pct(100));
    lv_obj_set_height(ui_about_hw_text_area, lv_pct(100));
    lv_textarea_set_text(ui_about_hw_text_area,
                         "MCU: STM32F469I\nFPGA: Lattice LIFCL-40\nRF: AT86RF215\n\nBands Supported:\n1: 389.5 - 450 MHz\n2: 2400 - 2483.5 MHz\n\nModes Supported:\n1: M17 (http://m17project.org)\n2: FreeDV (http://freedv.org)\n3: NFM/FM/WFM\n4: AM/SSB\n5: ...and more!");
    lv_obj_add_flag(ui_about_hw_text_area, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_about_hw_text_area,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_about_hw_text_area, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_color(ui_about_hw_text_area, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_about_hw_text_area, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_about_hw_text_area, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_about_hw_text_area, lv_color_hex(0x464B55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_about_hw_text_area, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_about_hw_text_area, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_about_ok_btn = lv_btn_create(ui_about_panel);
    lv_obj_set_width(ui_about_ok_btn, 100);
    lv_obj_set_height(ui_about_ok_btn, 50);
    lv_obj_set_align(ui_about_ok_btn, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_about_ok_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_about_ok_btn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_about_ok_btn, lv_color_hex(0x191C26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_about_ok_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_about_ok_btn, lv_color_hex(0x37B9F5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_about_ok_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label6 = lv_label_create(ui_about_ok_btn);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "OK");
    lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_about_logo = lv_img_create(ui_about_panel);
    lv_img_set_src(ui_about_logo, &ui_img_m17_logo_sm_png);
    lv_obj_set_width(ui_about_logo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_about_logo, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_about_logo, 20);
    lv_obj_set_y(ui_about_logo, 10);
    lv_obj_add_flag(ui_about_logo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_about_logo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_about_logo, 400);

    ui_about_openht_logo = lv_img_create(ui_about_panel);
    lv_img_set_src(ui_about_openht_logo, &ui_img_openht_logo_png);
    lv_obj_set_width(ui_about_openht_logo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_about_openht_logo, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_about_openht_logo, 62);
    lv_obj_set_y(ui_about_openht_logo, -278);
    lv_obj_set_align(ui_about_openht_logo, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_about_openht_logo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_about_openht_logo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label9 = lv_label_create(ui_about_panel);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, 102);
    lv_obj_set_y(ui_Label9, -227);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "FW ver 0.0.1\nFPGA ver: 1337\nBuild Date: 230401");

    lv_obj_add_event_cb(ui_about_ok_btn, ui_event_about_ok_btn, LV_EVENT_ALL, NULL);

}
