// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: hellll

#include "../ui.h"


void ui_event_comp_Volume_Adjust_Volume_Adjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_Volume_Adjust = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        closeVolumeAdjust(e);
    }
}
void ui_event_comp_Volume_Adjust_VolumeAdjustDecBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_Volume_Adjust = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        decVolume(e);
    }
}
void ui_event_comp_Volume_Adjust_VolumeAdjustAddBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_Volume_Adjust = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        addVolume(e);
    }
}

// COMPONENT Volume_Adjust

lv_obj_t * ui_Volume_Adjust_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Volume_Adjust;
    cui_Volume_Adjust = lv_obj_create(comp_parent);
    lv_obj_remove_style_all(cui_Volume_Adjust);
    lv_obj_set_width(cui_Volume_Adjust, 480);
    lv_obj_set_height(cui_Volume_Adjust, 480);
    lv_obj_set_x(cui_Volume_Adjust, -2);
    lv_obj_set_y(cui_Volume_Adjust, -1);
    lv_obj_set_align(cui_Volume_Adjust, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Volume_Adjust, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_VolumeAdjust;
    cui_VolumeAdjust = lv_obj_create(cui_Volume_Adjust);
    lv_obj_remove_style_all(cui_VolumeAdjust);
    lv_obj_set_width(cui_VolumeAdjust, 160);
    lv_obj_set_height(cui_VolumeAdjust, 80);
    lv_obj_set_x(cui_VolumeAdjust, 160);
    lv_obj_set_y(cui_VolumeAdjust, -170);
    lv_obj_set_align(cui_VolumeAdjust, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_VolumeAdjust, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_VolumeAdjust, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(cui_VolumeAdjust, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_VolumeAdjustDecBtn;
    cui_VolumeAdjustDecBtn = lv_obj_create(cui_VolumeAdjust);
    lv_obj_remove_style_all(cui_VolumeAdjustDecBtn);
    lv_obj_set_width(cui_VolumeAdjustDecBtn, 80);
    lv_obj_set_height(cui_VolumeAdjustDecBtn, 81);
    lv_obj_set_x(cui_VolumeAdjustDecBtn, -3);
    lv_obj_set_y(cui_VolumeAdjustDecBtn, -25);
    lv_obj_set_align(cui_VolumeAdjustDecBtn, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_VolumeAdjustDecBtn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_VolumeAdjustDecBtn, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_VolumeAdjustDecBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_VolumeAdjustDecBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_VolumeAdjustDecBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_VolumeAdjustDecBtn, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_VolumeAdjustDecBtn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_VolumeAdjustDecBtn, lv_color_hex(0xE1DBE4), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(cui_VolumeAdjustDecBtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_t * cui_VolumeAdjustDecImg;
    cui_VolumeAdjustDecImg = lv_img_create(cui_VolumeAdjustDecBtn);
    lv_img_set_src(cui_VolumeAdjustDecImg, &ui_img_404002205);
    lv_obj_set_width(cui_VolumeAdjustDecImg, LV_SIZE_CONTENT);   /// 30
    lv_obj_set_height(cui_VolumeAdjustDecImg, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_x(cui_VolumeAdjustDecImg, -5);
    lv_obj_set_y(cui_VolumeAdjustDecImg, 0);
    lv_obj_set_align(cui_VolumeAdjustDecImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_VolumeAdjustDecImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_VolumeAdjustDecImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(cui_VolumeAdjustDecImg, 384);

    lv_obj_t * cui_VolumeAdjustAddBtn;
    cui_VolumeAdjustAddBtn = lv_obj_create(cui_VolumeAdjust);
    lv_obj_remove_style_all(cui_VolumeAdjustAddBtn);
    lv_obj_set_width(cui_VolumeAdjustAddBtn, 80);
    lv_obj_set_height(cui_VolumeAdjustAddBtn, 81);
    lv_obj_set_x(cui_VolumeAdjustAddBtn, 2);
    lv_obj_set_y(cui_VolumeAdjustAddBtn, -5);
    lv_obj_set_align(cui_VolumeAdjustAddBtn, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_VolumeAdjustAddBtn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_VolumeAdjustAddBtn, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_VolumeAdjustAddBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_VolumeAdjustAddBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_VolumeAdjustAddBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_VolumeAdjustAddBtn, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_VolumeAdjustAddBtn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_VolumeAdjustAddBtn, lv_color_hex(0xE1DBE4), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(cui_VolumeAdjustAddBtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_t * cui_VolumeAdjustAddImg;
    cui_VolumeAdjustAddImg = lv_img_create(cui_VolumeAdjustAddBtn);
    lv_img_set_src(cui_VolumeAdjustAddImg, &ui_img_239308628);
    lv_obj_set_width(cui_VolumeAdjustAddImg, LV_SIZE_CONTENT);   /// 30
    lv_obj_set_height(cui_VolumeAdjustAddImg, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_x(cui_VolumeAdjustAddImg, 6);
    lv_obj_set_y(cui_VolumeAdjustAddImg, 0);
    lv_obj_set_align(cui_VolumeAdjustAddImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_VolumeAdjustAddImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_VolumeAdjustAddImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(cui_VolumeAdjustAddImg, 384);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_VOLUME_ADJUST_NUM);
    children[UI_COMP_VOLUME_ADJUST_VOLUME_ADJUST] = cui_Volume_Adjust;
    children[UI_COMP_VOLUME_ADJUST_VOLUMEADJUST] = cui_VolumeAdjust;
    children[UI_COMP_VOLUME_ADJUST_VOLUMEADJUST_VOLUMEADJUSTDECBTN] = cui_VolumeAdjustDecBtn;
    children[UI_COMP_VOLUME_ADJUST_VOLUMEADJUST_VOLUMEADJUSTDECBTN_VOLUMEADJUSTDECIMG] = cui_VolumeAdjustDecImg;
    children[UI_COMP_VOLUME_ADJUST_VOLUMEADJUST_VOLUMEADJUSTADDBTN] = cui_VolumeAdjustAddBtn;
    children[UI_COMP_VOLUME_ADJUST_VOLUMEADJUST_VOLUMEADJUSTADDBTN_VOLUMEADJUSTADDIMG] = cui_VolumeAdjustAddImg;
    lv_obj_add_event_cb(cui_Volume_Adjust, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Volume_Adjust, del_component_child_event_cb, LV_EVENT_DELETE, children);
    lv_obj_add_event_cb(cui_VolumeAdjustDecBtn, ui_event_comp_Volume_Adjust_VolumeAdjustDecBtn, LV_EVENT_ALL, children);
    lv_obj_add_event_cb(cui_VolumeAdjustAddBtn, ui_event_comp_Volume_Adjust_VolumeAdjustAddBtn, LV_EVENT_ALL, children);
    lv_obj_add_event_cb(cui_Volume_Adjust, ui_event_comp_Volume_Adjust_Volume_Adjust, LV_EVENT_ALL, children);
    ui_comp_Volume_Adjust_create_hook(cui_Volume_Adjust);
    return cui_Volume_Adjust;
}

