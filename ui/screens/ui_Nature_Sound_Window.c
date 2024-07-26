// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Nature_Sound_Window_screen_init(void)
{
    ui_Nature_Sound_Window = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Nature_Sound_Window, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Nature_Sound_Window, &ui_img_861711258, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Nature_Sound = lv_obj_create(ui_Nature_Sound_Window);
    lv_obj_remove_style_all(ui_Header_Nature_Sound);
    lv_obj_set_height(ui_Header_Nature_Sound, 30);
    lv_obj_set_width(ui_Header_Nature_Sound, lv_pct(100));
    lv_obj_set_x(ui_Header_Nature_Sound, 0);
    lv_obj_set_y(ui_Header_Nature_Sound, -225);
    lv_obj_set_align(ui_Header_Nature_Sound, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Header_Nature_Sound, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Header_Nature_Sound_Text = lv_label_create(ui_Header_Nature_Sound);
    lv_obj_set_width(ui_Header_Nature_Sound_Text, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Header_Nature_Sound_Text, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Header_Nature_Sound_Text, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Header_Nature_Sound_Text, "自然之音");
    lv_obj_set_style_text_color(ui_Header_Nature_Sound_Text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Nature_Sound_Text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Header_Nature_Sound_Text, &ui_font_LanTing18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Nature_Sound_Time = lv_label_create(ui_Header_Nature_Sound);
    lv_obj_set_width(ui_Header_Nature_Sound_Time, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Header_Nature_Sound_Time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Header_Nature_Sound_Time, 300);
    lv_obj_set_y(ui_Header_Nature_Sound_Time, 0);
    lv_obj_set_align(ui_Header_Nature_Sound_Time, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Header_Nature_Sound_Time, "");
    lv_obj_set_style_text_color(ui_Header_Nature_Sound_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Nature_Sound_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Header_Nature_Sound_Time, &ui_font_LanTing18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Nature_Sound_Menu = lv_obj_create(ui_Nature_Sound_Window);
    lv_obj_remove_style_all(ui_Nature_Sound_Menu);
    lv_obj_set_width(ui_Nature_Sound_Menu, 400);
    lv_obj_set_height(ui_Nature_Sound_Menu, 400);
    lv_obj_set_align(ui_Nature_Sound_Menu, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Nature_Sound_Menu, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_Nature_Sound_Menu, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_obj_clear_flag(ui_Nature_Sound_Menu, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Bird_Sound = lv_obj_create(ui_Nature_Sound_Menu);
    lv_obj_remove_style_all(ui_Bird_Sound);
    lv_obj_set_width(ui_Bird_Sound, 150);
    lv_obj_set_height(ui_Bird_Sound, 150);
    lv_obj_set_x(ui_Bird_Sound, -117);
    lv_obj_set_y(ui_Bird_Sound, 2);
    lv_obj_set_align(ui_Bird_Sound, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Bird_Sound, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_Bird_Sound, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Bird_Sound, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Bird_Sound_Btn = lv_btn_create(ui_Bird_Sound);
    lv_obj_set_width(ui_Bird_Sound_Btn, 90);
    lv_obj_set_height(ui_Bird_Sound_Btn, 90);
    lv_obj_set_align(ui_Bird_Sound_Btn, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Bird_Sound_Btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Bird_Sound_Btn, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_Bird_Sound_Btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Bird_Sound_Btn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Bird_Sound_Btn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bird_Sound_Btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bird_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bird_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Bird_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_Bird_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_Bird_Sound_Btn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Bird_Sound_Icon = lv_img_create(ui_Bird_Sound_Btn);
    lv_img_set_src(ui_Bird_Sound_Icon, &ui_img_12669592);
    lv_obj_set_width(ui_Bird_Sound_Icon, LV_SIZE_CONTENT);   /// 29
    lv_obj_set_height(ui_Bird_Sound_Icon, LV_SIZE_CONTENT);    /// 35
    lv_obj_set_x(ui_Bird_Sound_Icon, 130);
    lv_obj_set_y(ui_Bird_Sound_Icon, 12);
    lv_obj_set_align(ui_Bird_Sound_Icon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Bird_Sound_Icon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Bird_Sound_Icon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Bird_Sound_Text = lv_label_create(ui_Bird_Sound);
    lv_obj_set_width(ui_Bird_Sound_Text, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Bird_Sound_Text, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Bird_Sound_Text, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Bird_Sound_Text, "鸟叫");
    lv_obj_set_style_text_color(ui_Bird_Sound_Text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Bird_Sound_Text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Bird_Sound_Text, &ui_font_LanTing18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bug_Sound = lv_obj_create(ui_Nature_Sound_Menu);
    lv_obj_remove_style_all(ui_Bug_Sound);
    lv_obj_set_width(ui_Bug_Sound, 150);
    lv_obj_set_height(ui_Bug_Sound, 150);
    lv_obj_set_x(ui_Bug_Sound, 106);
    lv_obj_set_y(ui_Bug_Sound, 2);
    lv_obj_set_align(ui_Bug_Sound, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Bug_Sound, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_Bug_Sound, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Bug_Sound, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Bug_Sound_Btn = lv_btn_create(ui_Bug_Sound);
    lv_obj_set_width(ui_Bug_Sound_Btn, 90);
    lv_obj_set_height(ui_Bug_Sound_Btn, 90);
    lv_obj_set_align(ui_Bug_Sound_Btn, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Bug_Sound_Btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Bug_Sound_Btn, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_Bug_Sound_Btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Bug_Sound_Btn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Bug_Sound_Btn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bug_Sound_Btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bug_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bug_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Bug_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_Bug_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_Bug_Sound_Btn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Bug_Sound_Icon = lv_img_create(ui_Bug_Sound_Btn);
    lv_img_set_src(ui_Bug_Sound_Icon, &ui_img_2034599484);
    lv_obj_set_width(ui_Bug_Sound_Icon, LV_SIZE_CONTENT);   /// 29
    lv_obj_set_height(ui_Bug_Sound_Icon, LV_SIZE_CONTENT);    /// 35
    lv_obj_set_x(ui_Bug_Sound_Icon, 130);
    lv_obj_set_y(ui_Bug_Sound_Icon, 12);
    lv_obj_set_align(ui_Bug_Sound_Icon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Bug_Sound_Icon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Bug_Sound_Icon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Bug_Sound_Text = lv_label_create(ui_Bug_Sound);
    lv_obj_set_width(ui_Bug_Sound_Text, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Bug_Sound_Text, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Bug_Sound_Text, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Bug_Sound_Text, "虫鸣");
    lv_obj_set_style_text_color(ui_Bug_Sound_Text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Bug_Sound_Text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Bug_Sound_Text, &ui_font_LanTing18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Forest_Sound = lv_obj_create(ui_Nature_Sound_Menu);
    lv_obj_remove_style_all(ui_Forest_Sound);
    lv_obj_set_width(ui_Forest_Sound, 150);
    lv_obj_set_height(ui_Forest_Sound, 150);
    lv_obj_set_x(ui_Forest_Sound, -125);
    lv_obj_set_y(ui_Forest_Sound, 151);
    lv_obj_set_align(ui_Forest_Sound, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Forest_Sound, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_Forest_Sound, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Forest_Sound, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Forest_Sound_Btn = lv_btn_create(ui_Forest_Sound);
    lv_obj_set_width(ui_Forest_Sound_Btn, 90);
    lv_obj_set_height(ui_Forest_Sound_Btn, 90);
    lv_obj_set_align(ui_Forest_Sound_Btn, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Forest_Sound_Btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Forest_Sound_Btn, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_Forest_Sound_Btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Forest_Sound_Btn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Forest_Sound_Btn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Forest_Sound_Btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Forest_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Forest_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Forest_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_Forest_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_Forest_Sound_Btn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Forest_Sound_Icon = lv_img_create(ui_Forest_Sound_Btn);
    lv_img_set_src(ui_Forest_Sound_Icon, &ui_img_304460963);
    lv_obj_set_width(ui_Forest_Sound_Icon, LV_SIZE_CONTENT);   /// 29
    lv_obj_set_height(ui_Forest_Sound_Icon, LV_SIZE_CONTENT);    /// 35
    lv_obj_set_x(ui_Forest_Sound_Icon, 130);
    lv_obj_set_y(ui_Forest_Sound_Icon, 12);
    lv_obj_set_align(ui_Forest_Sound_Icon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Forest_Sound_Icon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Forest_Sound_Icon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Forest_Sound_Text = lv_label_create(ui_Forest_Sound);
    lv_obj_set_width(ui_Forest_Sound_Text, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Forest_Sound_Text, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Forest_Sound_Text, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Forest_Sound_Text, "森林");
    lv_obj_set_style_text_color(ui_Forest_Sound_Text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Forest_Sound_Text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Forest_Sound_Text, &ui_font_LanTing18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Sea_Sound = lv_obj_create(ui_Nature_Sound_Menu);
    lv_obj_remove_style_all(ui_Sea_Sound);
    lv_obj_set_width(ui_Sea_Sound, 150);
    lv_obj_set_height(ui_Sea_Sound, 150);
    lv_obj_set_x(ui_Sea_Sound, 97);
    lv_obj_set_y(ui_Sea_Sound, 150);
    lv_obj_set_align(ui_Sea_Sound, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Sea_Sound, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_Sea_Sound, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Sea_Sound, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Sea_Sound_Btn = lv_btn_create(ui_Sea_Sound);
    lv_obj_set_width(ui_Sea_Sound_Btn, 90);
    lv_obj_set_height(ui_Sea_Sound_Btn, 90);
    lv_obj_set_align(ui_Sea_Sound_Btn, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Sea_Sound_Btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Sea_Sound_Btn, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_Sea_Sound_Btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Sea_Sound_Btn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Sea_Sound_Btn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Sea_Sound_Btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sea_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Sea_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Sea_Sound_Btn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_Sea_Sound_Btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_Sea_Sound_Btn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Sea_Sound_Icon = lv_img_create(ui_Sea_Sound_Btn);
    lv_img_set_src(ui_Sea_Sound_Icon, &ui_img_1893023884);
    lv_obj_set_width(ui_Sea_Sound_Icon, LV_SIZE_CONTENT);   /// 29
    lv_obj_set_height(ui_Sea_Sound_Icon, LV_SIZE_CONTENT);    /// 35
    lv_obj_set_x(ui_Sea_Sound_Icon, 130);
    lv_obj_set_y(ui_Sea_Sound_Icon, 12);
    lv_obj_set_align(ui_Sea_Sound_Icon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Sea_Sound_Icon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Sea_Sound_Icon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Sea_Sound_Text = lv_label_create(ui_Sea_Sound);
    lv_obj_set_width(ui_Sea_Sound_Text, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Sea_Sound_Text, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Sea_Sound_Text, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Sea_Sound_Text, "大海");
    lv_obj_set_style_text_color(ui_Sea_Sound_Text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Sea_Sound_Text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Sea_Sound_Text, &ui_font_LanTing18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BackToMainWindowBtn7 = lv_imgbtn_create(ui_Nature_Sound_Window);
    lv_imgbtn_set_src(ui_BackToMainWindowBtn7, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_348826415, NULL);
    lv_imgbtn_set_src(ui_BackToMainWindowBtn7, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_348826415, NULL);
    lv_obj_set_height(ui_BackToMainWindowBtn7, 50);
    lv_obj_set_width(ui_BackToMainWindowBtn7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_BackToMainWindowBtn7, -212);
    lv_obj_set_y(ui_BackToMainWindowBtn7, -212);
    lv_obj_set_align(ui_BackToMainWindowBtn7, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_BackToMainWindowBtn7, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_img_recolor(ui_BackToMainWindowBtn7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_BackToMainWindowBtn7, 100, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Nature_Header_Volume = ui_Header_Volume_create(ui_Nature_Sound_Window);
    lv_obj_set_x(ui_Nature_Header_Volume, 187);
    lv_obj_set_y(ui_Nature_Header_Volume, -216);

    ui_Nature_Window_Volume_adjust = ui_Volume_Adjust_create(ui_Nature_Sound_Window);
    lv_obj_set_x(ui_Nature_Window_Volume_adjust, 0);
    lv_obj_set_y(ui_Nature_Window_Volume_adjust, 0);
    lv_obj_add_flag(ui_Nature_Window_Volume_adjust, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_event_cb(ui_Bird_Sound_Btn, ui_event_Bird_Sound_Btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Bug_Sound_Btn, ui_event_Bug_Sound_Btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Forest_Sound_Btn, ui_event_Forest_Sound_Btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Sea_Sound_Btn, ui_event_Sea_Sound_Btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BackToMainWindowBtn7, ui_event_BackToMainWindowBtn7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Nature_Sound_Window, ui_event_Nature_Sound_Window, LV_EVENT_ALL, NULL);

}
