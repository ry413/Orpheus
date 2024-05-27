// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"
#include <stdio.h>
#include <time.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/portmacro.h>
#include <esp_sntp.h>
#include <nvs.h>

#include "wifi.h"
#include "backlight.h"
#include "bluetooth.h"

#include "ui_comp_music_item.h"

//////////////////// DEFINITIONS ////////////////////
#define WIFI_CONNECTION_TIMEOUT pdMS_TO_TICKS(30000)  // 30秒超时时间
#define MAX_ITEMS_PER_LIST 5
#define MAX_LISTS 10  // 假设最多有 10 个 MusicList

//////////////////// GLOBAL VARIABLES ////////////////////

// 全局变量用于存储日月时分的时间戳
time_t globalTime = 0;
lv_obj_t * currentTimeLabel;
static lv_obj_t *musicLists[MAX_LISTS]; // 存储 MusicList 的指针数组
static int currentListIndex = 0; // 当前 MusicList 的索引
static int numMusicLists = 0; // MusicList 的总数
static bool playing = false;

static lv_timer_t *musicTimer; // 音频进度条定时器
static int currentPlayTime = 0; // 音频进度条的当前值
static int updateInterval = 0; // 进度条每次更新的间隔, 因为进度条上限固定为100



// prev开头的都是为了在修改值后没有点击[确认]而是[取消]的情况下, 将原来的值放回去
// 不过它们实际上也是那些值的真实拥有者

// 背光亮度等级和时间, 时间分为7级, 0代表永不熄灭
uint32_t prevBacklightLevel;
int backlightTimes[7] = {0, 5, 10, 20, 30, 60, 300};
uint32_t prevBacklightTimeLevel;
// 日期与时间设置
uint32_t prevTimeHour;
uint32_t prevTimeMin;
uint32_t prevDateYear;
uint32_t prevDateMonth;
uint32_t prevDateDay;
// 默认音量和最大音量
uint32_t prevDefaultVolume;
uint32_t prevMaxVolume;


//////////////////// STATIC FUNCTION DECLARATIONS ////////////////////

static void updateCurrentTimeLabel(void);
static void obtainTime(void* pvParameter);
static void updateTimeTask(void *pvParameter);
static void initTimeTask(void *param);
static void updateBacklightTime(int backlightTimeLevel);
static uint32_t getBacklightTimeLevel();
static void createMusicItemTask(void *pvParameter);
static void getDurationTask(void *pvParameter);


//////////////////// 不给lvgl事件直接调用的静态函数 ////////////////////

// 把globalTime更新到currentTimeLabel上
static void updateCurrentTimeLabel(void) {
    struct tm timeinfo;
    char timeStr[9];

    localtime_r(&globalTime, &timeinfo);
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);
    lv_label_set_text(currentTimeLabel, timeStr);
}
// 从NTP获取时间
static void obtainTime(void* pvParameter)
{
    // NTP服务器列表, 这是macOS上使用ntpdate测试出的一些延迟低的服务器, 2024.5.15
    const char* ntp_servers[] = {
        "cn.ntp.org.cn",
        // "edu.ntp.org.cn",
        // "ntp.sjtu.edu.cn",
        // "ntp.aliyun.com",
        // "pool.ntp.org",
    };
    const int num_ntp_servers = sizeof(ntp_servers) / sizeof(ntp_servers[0]);

    time_t now = 0;
    struct tm timeinfo = { 0 };
    int retry = 0;
    const int retry_count = 20;
    // 放个IP
    ip_addr_t *addr = NULL;
    ipaddr_aton("111.230.50.201", addr);
    esp_sntp_setserver(0, addr);

    esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
    for (int i = 0; i < num_ntp_servers; ++i) {
        esp_sntp_setservername(i, ntp_servers[i]);
    }
    esp_sntp_init();

    while (timeinfo.tm_year < (2016 - 1900) && ++retry < retry_count) {
        ESP_LOGI("obtainTime", "等待系统时间设置... (%d/%d) 正在尝试连接服务器: %s", retry, retry_count, ntp_servers[retry % num_ntp_servers]);

        time(&now);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        localtime_r(&now, &timeinfo);
    }

    if (retry >= retry_count) {
        ESP_LOGE("obtainTime", "在 %d 次重试后无法获取时间。请检查您的网络连接。", retry_count);
    } else {
        ESP_LOGI("obtainTime", "系统时间已设置。");
        // 修正时区
        timeinfo.tm_hour += 8;
        mktime(&timeinfo);
        // 保存全局时间
        globalTime = mktime(&timeinfo);
    }
    // 启动定时器
    xTaskCreate(updateTimeTask, "updateTimeTask", 2048, NULL, 5, NULL);
    vTaskDelete(NULL);
}
// 时间更新定时器
static void updateTimeTask(void *pvParameter)
{
    while (1)
    {
        updateCurrentTimeLabel();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        globalTime += 1;
    }
}
// 初始化时间任务
static void initTimeTask(void *param)
{
    EventGroupHandle_t wifi_event_group = get_wifi_event_group();
    EventBits_t bits = xEventGroupWaitBits(wifi_event_group, WIFI_CONNECTED_BIT, pdFALSE, pdTRUE, WIFI_CONNECTION_TIMEOUT);
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI("initTimeTask", "Wi-Fi 已连接");
        lv_img_set_src(ui_Wifi_Status, &ui_img_1742736079);
        // 异步, 否则会阻塞UI线程
        xTaskCreate(obtainTime, "obtainTime", 4096, NULL, 5, NULL);
    } else {
        ESP_LOGE("initTimeTask", "Wi-Fi 未连接");
    }
    vTaskDelete(NULL); // 删除任务
}
// 更新背光时间到label上
static void updateBacklightTime(int backlightTimeLevel)
{
    int backlightTime = backlightTimes[backlightTimeLevel];
    if (backlightTime == 0) {
        lv_label_set_text(ui_Backlight_Time_Value2, "off");
    } else {
        lv_label_set_text_fmt(ui_Backlight_Time_Value2, "%ds", backlightTime);
    }
}
// 返回当前背光时间label上秒数对应的等级
static uint32_t getBacklightTimeLevel()
{
    const char *text = lv_label_get_text(ui_Backlight_Time_Value2);
    if (strcmp(text, "off") != 0) {
        int backlightTime = atoi(text);
        for (int i = 0; i < 7; i++) {
            if (backlightTimes[i] == backlightTime) {
                return i;
                break;
            }
        }
    }
    return 0;
}
// 创建Music List及item的任务, 由这里发起get_all_file_names
static void createMusicItemTask(void *pvParameters)
{
    // 等待获取完文件名
    get_all_file_names();
    musicLists[currentListIndex] = ui_Music_List_create(ui_Music_List_Container);
    numMusicLists++;
    int items_added = 0;
    for (int i = 0; i < total_files_count; i++) {
        // 如果当前列表的 Music_item 数量达到最大值，切换到下一个列表
        if (items_added >= MAX_ITEMS_PER_LIST) {
            currentListIndex++;
            if (currentListIndex >= MAX_LISTS) {
                ESP_LOGE("create_music_item_task", "Exceeded maximum number of lists");
                break;
            }
            // 创建新的 MusicList
            musicLists[currentListIndex] = ui_Music_List_create(ui_Music_List_Container);
            numMusicLists++;
            lv_obj_add_flag(musicLists[currentListIndex], LV_OBJ_FLAG_HIDDEN);
            items_added = 0; // 重置计数器
        }
        // 创建musicItem
        lv_obj_t *obj = ui_Music_Item_create(musicLists[currentListIndex]);

        lv_obj_t *icon = lv_obj_get_child(obj, 2);
        lv_img_set_src(icon, &ui_img_35201459);

        lv_obj_t *name_label = lv_obj_get_child(obj, 0);
        lv_label_set_text(name_label, utf8_file_names[i]);

        items_added++;
    }
    // 将当前显示的设置为第一个列表
    currentListIndex = 0;
    vTaskDelete(NULL);
}
// 将秒转为hh:mm:ss的函数
static void format_time(int seconds, char * buffer, size_t buffer_size)
{
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int sec = seconds % 60;
    int ret = snprintf(buffer, buffer_size, "%02d:%02d:%02d", hours, minutes, sec);

    // 检查 snprintf 是否成功
    if (ret < 0 || ret >= buffer_size) {
        // 错误处理：确保缓冲区以 null 结尾
        if (buffer_size > 0) {
            buffer[0] = '\0';
        }
        fprintf(stderr, "Error formatting time string\n");
    }
}
// 更新进度条和时间标签的回调函数
static void update_progress(lv_timer_t * timer)
{
    static int interval_counter = 0;
    if (currentPlayTime < current_music_duration) {
        currentPlayTime++;

        // 更新当前时间标签
        char time_str[9]; // hh:mm:ss
        format_time(currentPlayTime, time_str, sizeof(time_str));
        lv_label_set_text(ui_Current_Time, time_str);

        interval_counter++;
        if (interval_counter >= updateInterval) {
            interval_counter = 0;
            // 更新进度条
            lv_slider_set_value(ui_Progress_Slider, lv_slider_get_value(ui_Progress_Slider) + 1, LV_ANIM_OFF);
        }
    } else {
        lv_img_set_src(ui_Play_Pause_Icon, &ui_img_2101671624);
        lv_timer_pause(timer); // 停止定时器
    }
}
// 初始化音频进度条定时器
static void init_progress_bar(void)
{
    // 创建定时器，每秒更新一次
    musicTimer = lv_timer_create(update_progress, 1000, NULL);

    lv_timer_pause(musicTimer); // 初始化时暂停定时器
}
// 获取音乐总时长, 并启动进度条定时器的任务, 因为要先有总时长, 才能使用进度条
static void getDurationTask(void *pvParameter)
{
    EventBits_t bits = xEventGroupWaitBits(get_bluetooth_event_group(), EVENT_PLAY_MUSIC | EVENT_NEXT_TRACK | EVENT_PREV_TRACK, pdTRUE, pdFALSE, 3000);

    if (bits & (EVENT_PLAY_MUSIC | EVENT_NEXT_TRACK | EVENT_PREV_TRACK)) {
        bluetooth_send_at_command("AT+MT", CMD_GET_DURATION);
        bits = xEventGroupWaitBits(get_bluetooth_event_group(), EVENT_DURATION, pdTRUE, pdFALSE, 3000);
        if (bits & EVENT_DURATION) {
            char time_str[12];
            format_time(current_music_duration, time_str, sizeof(time_str));
            lv_label_set_text_static(ui_Total_Time, time_str);

            updateInterval = (current_music_duration / 100); // 进度条更新间隔
            currentPlayTime = 0;
            lv_timer_resume(musicTimer); // 启动定时器
            
        }
    }
    vTaskDelete(NULL);
}


//////////////////// 给lvgl的事件用的回调 ////////////////////

// ******************** initial actions ********************
// 不知道有什么要写在initial actions里的, 暂时写个initTime
// 初始化全局时间
void initTime(lv_event_t * e)
{
    // 在初始化时间时把默认显示时间的label设置为主界面的, 否则currentTimeLabel为空很危险
    currentTimeLabel = ui_Header_Main_Time;
    // 因为要等待WiFi连接才能开始获取事件, 所以创建异步任务, 否则会阻塞界面加载
    xTaskCreate(initTimeTask, "initTimeTask", 4096, NULL, 5, NULL);
    xTaskCreate(createMusicItemTask, "createMusicItemTask", 8192, NULL, 5, NULL);
}


// ******************** 未知分类 ********************
// 各个screen loaded时, 将时间label设置到currentTimeLabel上, 保持全局时间显示, Settings界面没有
void setTimeMain(lv_event_t * e)
{
    currentTimeLabel = ui_Header_Main_Time;
    // 本来只有主界面要加这个防止时间未初始化就更新值, 但是用户有可能会在时间未初始化时乱点点到别的界面, 所以每个界面都加上了
    if(globalTime > 0)
        updateCurrentTimeLabel();
    init_progress_bar();
}
void setTimeMusic(lv_event_t * e)
{
    currentTimeLabel = ui_Header_Music_Time;
    if(globalTime > 0)
        updateCurrentTimeLabel();
}
void setTimeNatureSound(lv_event_t * e)
{
    currentTimeLabel = ui_Header_Nature_Sound_Time;
    if(globalTime > 0)
        updateCurrentTimeLabel();
}
void setTimeBluetooth(lv_event_t * e)
{
    currentTimeLabel = ui_Header_Bluetooth_Time;
    if(globalTime > 0)
        updateCurrentTimeLabel();
}
void setTimeMode(lv_event_t * e)
{
    currentTimeLabel = ui_Header_Mode_Time;
    if(globalTime > 0)
        updateCurrentTimeLabel();
}
void setTimeWakeup(lv_event_t * e)
{
	currentTimeLabel = ui_Header_Wake_up_Time;
    if(globalTime > 0)
        updateCurrentTimeLabel();
}
void setTimeGuide(lv_event_t * e)
{
    currentTimeLabel = ui_Header_Guide_Time;
    if(globalTime > 0)
        updateCurrentTimeLabel();
}


// ******************** 背光设置 ********************
// 初始化背光亮度和时间
void initBacklightSettings(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("BLSettings", NVS_READONLY, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("backlightSettings", "Failed to open NVS");
        return;
    }

    err = nvs_get_u32(nvs_handle, "level", &prevBacklightLevel);
    lv_label_set_text_fmt(ui_Backlight_Brightness_Value2, "%ld", prevBacklightLevel);
    if (err != ESP_OK) {
        ESP_LOGE("backlightSettings", "Failed to get backlightLevel from NVS");
        nvs_close(nvs_handle);
        return;
    }

    err = nvs_get_u32(nvs_handle, "time", &prevBacklightTimeLevel);
    updateBacklightTime(prevBacklightTimeLevel);
    if (err != ESP_OK) {
        ESP_LOGE("backlightSettings", "Failed to get backlightTimeLevel from NVS");
        nvs_close(nvs_handle);
        return;
    }
    nvs_close(nvs_handle);
}
// 确认保存背光亮度
void saveBacklightBrightness(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("BLSettings", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBacklightLevel", "Failed to open NVS");
        return;
    }
    const char *text = lv_label_get_text(ui_Backlight_Brightness_Value2);
    prevBacklightLevel = atoi(text);
    err = nvs_set_u32(nvs_handle, "level", prevBacklightLevel);

    if (err != ESP_OK) {
        ESP_LOGE("saveBacklightLevel", "Failed to set backlightLevel in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBacklightLevel", "Failed to commit NVS changes");
    }
    nvs_close(nvs_handle);
}
// 取消保存背光亮度
void cancelSaveBacklightBrightness(lv_event_t * e)
{
    lv_label_set_text_fmt(ui_Backlight_Brightness_Value2, "%ld", prevBacklightLevel);
    setBacklight(prevBacklightLevel);
}
// 增加背光亮度
void addBrightness(lv_event_t * e)
{
    const char *text = lv_label_get_text(ui_Backlight_Brightness_Value2);
    int brightnessLevel = atoi(text);
    brightnessLevel = (brightnessLevel < 5) ? brightnessLevel + 1 : 5;
    lv_label_set_text_fmt(ui_Backlight_Brightness_Value2, "%d", brightnessLevel);
    setBacklight(brightnessLevel);
}
// 减少背光亮度
void decBrightness(lv_event_t * e)
{
    const char *text = lv_label_get_text(ui_Backlight_Brightness_Value2);
    int brightnessLevel = atoi(text);
    brightnessLevel = (brightnessLevel > 1) ? brightnessLevel - 1 : 1;
    lv_label_set_text_fmt(ui_Backlight_Brightness_Value2, "%d", brightnessLevel);
    setBacklight(brightnessLevel);
}
// 确认保存背光时间
void saveBacklightTime(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("BLSettings", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBacklightTime", "Failed to open NVS");
        return;
    }
    prevBacklightTimeLevel = getBacklightTimeLevel();
    err = nvs_set_u32(nvs_handle, "time", prevBacklightTimeLevel);
    if (err != ESP_OK) {
        ESP_LOGE("saveBacklightTime", "Failed to set backlightTime in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBacklightTime", "Failed to commit NVS changes");
    }
    nvs_close(nvs_handle);
}
// 取消保存背光时间
void cancelSaveBacklightTime(lv_event_t * e)
{
    updateBacklightTime(prevBacklightTimeLevel);
}
// 增加背光时间
void addBacklightTime(lv_event_t * e)
{
    int backlightTimeLevel = getBacklightTimeLevel();
    if (backlightTimeLevel < 6) {
        backlightTimeLevel++;
    }
    updateBacklightTime(backlightTimeLevel);
}
// 减少背光时间
void decBacklightTime(lv_event_t * e)
{
    int backlightTimeLevel = getBacklightTimeLevel();
    if (backlightTimeLevel > 0) {
        backlightTimeLevel--;
    }
    updateBacklightTime(backlightTimeLevel);
}

// ******************** 蓝牙设置 ********************
// 初始化蓝牙名称和密码
void initBluetoothSettings(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("BluetoothCfg", NVS_READONLY, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("initBluetoothSettings", "Failed to open NVS: %s", esp_err_to_name(err));
        return;
    }

    // 读取蓝牙名称
    size_t required_size = 0;
    err = nvs_get_str(nvs_handle, "name", NULL, &required_size);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGE("initBluetoothSettings", "Failed to get size for name from NVS: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return;
    }

    if (required_size > 0) {
        char *prevBluetoothName = malloc(required_size);
        if (prevBluetoothName == NULL) {
            ESP_LOGE("initBluetoothSettings", "Failed to allocate memory for Bluetooth name");
            nvs_close(nvs_handle);
            return;
        }
        err = nvs_get_str(nvs_handle, "name", prevBluetoothName, &required_size);
        if (err != ESP_OK) {
            ESP_LOGE("initBluetoothSettings", "Failed to get name from NVS: %s", esp_err_to_name(err));
            free(prevBluetoothName);
            nvs_close(nvs_handle);
            return;
        }
        lv_textarea_set_text(ui_Bluetooth_Name_Input2, prevBluetoothName);
        free(prevBluetoothName);
    } else {
        ESP_LOGI("initBluetoothSettings", "Bluetooth name not set in NVS");
    }

    // 读取蓝牙密码
    required_size = 0;
    err = nvs_get_str(nvs_handle, "password", NULL, &required_size);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGE("initBluetoothSettings", "Failed to get size for password from NVS: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return;
    }

    if (required_size > 0) {
        char *prevBluetoothPassword = malloc(required_size);
        if (prevBluetoothPassword == NULL) {
            ESP_LOGE("initBluetoothSettings", "Failed to allocate memory for Bluetooth password");
            nvs_close(nvs_handle);
            return;
        }
        err = nvs_get_str(nvs_handle, "password", prevBluetoothPassword, &required_size);
        if (err != ESP_OK) {
            ESP_LOGE("initBluetoothSettings", "Failed to get password from NVS: %s", esp_err_to_name(err));
            free(prevBluetoothPassword);
            nvs_close(nvs_handle);
            return;
        }
        lv_textarea_set_text(ui_Bluetooth_Password_Input2, prevBluetoothPassword);
        free(prevBluetoothPassword);
    } else {
        ESP_LOGI("initBluetoothSettings", "Bluetooth password not set in NVS");
    }

    nvs_close(nvs_handle);
}
// 确认保存蓝牙名称
void saveBluetoothNameSetting(lv_event_t * e)
{
    const char *name = lv_textarea_get_text(ui_Bluetooth_Name_Input2);

    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("BluetoothCfg", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBluetoothNameSetting", "Failed to open NVS");
        return;
    }

    err = nvs_set_str(nvs_handle, "name", name);
    if (err != ESP_OK) {
        ESP_LOGE("saveBluetoothNameSetting", "Failed to set name in NVS");
        nvs_close(nvs_handle);
        return;
    }


    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBluetoothNameSetting", "Failed to commit NVS changes");
    }

    nvs_close(nvs_handle);
}
// 确认保存蓝牙密码
void saveBluetoothPasswordSetting(lv_event_t * e)
{
    const char *password = lv_textarea_get_text(ui_Bluetooth_Password_Input2);

    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("BluetoothCfg", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBluetoothPasswordSetting", "Failed to open NVS");
        return;
    }
    err = nvs_set_str(nvs_handle, "password", password);
    if (err != ESP_OK) {
        ESP_LOGE("saveBluetoothPasswordSetting", "Failed to set password in NVS");
        nvs_close(nvs_handle);
        return;
    }

    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveBluetoothPasswordSetting", "Failed to commit NVS changes");
    }

    nvs_close(nvs_handle);
}

// ******************** 时间设置 ********************
// 初始化时间与日期
void initDateTimeSettings(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("TimeSettings", NVS_READONLY, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("initDateTimeSettings", "Failed to open NVS: %s", esp_err_to_name(err));
        return;
    }
    err = nvs_get_u32(nvs_handle, "year", &prevDateYear);
    if (err != ESP_OK) {
        ESP_LOGE("initDateTimeSettings", "Failed to get year from NVS: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_get_u32(nvs_handle, "month", &prevDateMonth);
    if (err != ESP_OK) {
        ESP_LOGE("initDateTimeSettings", "Failed to get month from NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_get_u32(nvs_handle, "day", &prevDateDay);
    if (err != ESP_OK) {
        ESP_LOGE("initDateTimeSettings", "Failed to get day from NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_get_u32(nvs_handle, "hour", &prevTimeHour);
    if (err != ESP_OK) {
        ESP_LOGE("initDateTimeSettings", "Failed to get hour from NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_get_u32(nvs_handle, "minute", &prevTimeMin);
    if (err != ESP_OK) {
        ESP_LOGE("initDateTimeSettings", "Failed to get minute from NVS");
        nvs_close(nvs_handle);
        return;
    }
    nvs_close(nvs_handle);

    char year_text[5], month_text[3], day_text[3], hour_text[3], min_text[3];
    snprintf(year_text, sizeof(year_text), "%ld", prevDateYear);
    snprintf(month_text, sizeof(month_text), "%02ld", prevDateMonth);
    snprintf(day_text, sizeof(day_text), "%02ld", prevDateDay);
    snprintf(hour_text, sizeof(hour_text), "%02ld", prevTimeHour);
    snprintf(min_text, sizeof(min_text), "%02ld", prevTimeMin);
    lv_textarea_set_text(ui_Date_Setting_Year2, year_text);
    lv_textarea_set_text(ui_Date_Setting_Month2, month_text);
    lv_textarea_set_text(ui_Date_Setting_Day2, day_text);
    lv_textarea_set_text(ui_Time_Setting_Hour2, hour_text);
    lv_textarea_set_text(ui_Time_Setting_Min2, min_text);
}
// 确认保存时间
void saveTimeSetting(lv_event_t * e)
{
    const char *hour_text = lv_textarea_get_text(ui_Time_Setting_Hour2);
    const char *min_text = lv_textarea_get_text(ui_Time_Setting_Min2);
    // 检查输入
    int hour = atoi(hour_text);
    int min = atoi(min_text);
    if (hour < 0 || hour > 23 || min < 0 || min > 59) {
        char hour_text[3];
        snprintf(hour_text, sizeof(hour_text), "%ld", prevTimeHour);
        lv_textarea_set_text(ui_Time_Setting_Hour2, hour_text);
        char min_text[3];
        snprintf(min_text, sizeof(min_text), "%ld", prevTimeMin);
        lv_textarea_set_text(ui_Time_Setting_Min2, min_text);
        ESP_LOGE("saveTimeSetting", "Invalid input: hour=%s, minute=%s", hour_text, min_text);
        return;
    }
    prevTimeHour = hour;
    prevTimeMin = min;

    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("TimeSettings", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveTimeSetting", "Failed to open NVS");
        return;
    }
    err = nvs_set_u32(nvs_handle, "hour", prevTimeHour);
    if (err != ESP_OK) {
        ESP_LOGE("saveTimeSetting", "Failed to set hour in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_set_u32(nvs_handle, "minute", prevTimeMin);
    if (err != ESP_OK) {
        ESP_LOGE("saveTimeSetting", "Failed to set minute in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveTimeSetting", "Failed to commit NVS changes");
    }

    nvs_close(nvs_handle);
}
// 确认保存日期
void saveDateSetting(lv_event_t * e)
{
    const char *year_text = lv_textarea_get_text(ui_Date_Setting_Year2);
    const char *month_text = lv_textarea_get_text(ui_Date_Setting_Month2);
    const char *day_text = lv_textarea_get_text(ui_Date_Setting_Day2);
    // 检查输入
    uint32_t year = (uint32_t)atoi(year_text);
    uint32_t month = (uint32_t)atoi(month_text);
    uint32_t day = (uint32_t)atoi(day_text);
    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        char year_text[5];
        snprintf(year_text, sizeof(year_text), "%ld", prevDateYear);
        lv_textarea_set_text(ui_Date_Setting_Year2, year_text);
        char month_text[3];
        snprintf(month_text, sizeof(month_text), "%ld", prevDateMonth);
        lv_textarea_set_text(ui_Date_Setting_Month2, month_text);
        char day_text[3];
        snprintf(day_text, sizeof(day_text), "%ld", prevDateDay);
        lv_textarea_set_text(ui_Date_Setting_Day2, day_text);

        ESP_LOGE("saveDateSetting", "Invalid input: year=%s, month=%s, day=%s", year_text, month_text, day_text);
        return;
    }

    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("TimeSettings", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveDateSetting", "Failed to open NVS");
        return;
    }
    err = nvs_set_u32(nvs_handle, "year", year);
    if (err != ESP_OK) {
        ESP_LOGE("saveDateSetting", "Failed to set year in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_set_u32(nvs_handle, "month", month);
    if (err != ESP_OK) {
        ESP_LOGE("saveDateSetting", "Failed to set month in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_set_u32(nvs_handle, "day", day);
    if (err != ESP_OK) {
        ESP_LOGE("saveDateSetting", "Failed to set day in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveDateSetting", "Failed to commit NVS changes");
    }
    nvs_close(nvs_handle);
}

// ******************** 音量设置 ********************
// 初始化默认音量和最大音量
void initVolumeSettings(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("VolumeCfg", NVS_READONLY, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("initVolumeSettings", "Failed to open NVS");
        return;
    }

    err = nvs_get_u32(nvs_handle, "defaultVolume", &prevDefaultVolume);
    lv_label_set_text_fmt(ui_Default_Volume_Value, "%ld", prevDefaultVolume);
    if (err != ESP_OK) {
        ESP_LOGE("backlightSettings", "Failed to get defaultVolume from NVS");
        nvs_close(nvs_handle);
        return;
    }

    err = nvs_get_u32(nvs_handle, "maxVolume", &prevMaxVolume);
    lv_label_set_text_fmt(ui_Max_Volume_Value, "%ld", prevMaxVolume);
    if (err != ESP_OK) {
        ESP_LOGE("backlightSettings", "Failed to get prevMaxVolume from NVS");
        nvs_close(nvs_handle);
        return;
    }
    nvs_close(nvs_handle);
}
// 增加默认音量
void addDefaultVolume(lv_event_t * e)
{
    const char *text = lv_label_get_text(ui_Default_Volume_Value);
    int defaultVolume = atoi(text);
    defaultVolume = (defaultVolume < 15) ? defaultVolume + 1 : 15;
    lv_label_set_text_fmt(ui_Default_Volume_Value, "%d", defaultVolume);
}
// 减少默认音量
void decDefaultVolume(lv_event_t * e)
{
    const char *text = lv_label_get_text(ui_Default_Volume_Value);
    int defaultVolume = atoi(text);
    defaultVolume = (defaultVolume > 1) ? defaultVolume - 1 : 1;
    lv_label_set_text_fmt(ui_Default_Volume_Value, "%d", defaultVolume);
}
// 增加最大音量
void addMaxVolume(lv_event_t * e)
{
    const char *text = lv_label_get_text(ui_Max_Volume_Value);
    int maxVolume = atoi(text);
    maxVolume = (maxVolume < 15) ? maxVolume + 1 : 15;
    lv_label_set_text_fmt(ui_Max_Volume_Value, "%d", maxVolume);
}
// 减少最大音量
void decMaxVolume(lv_event_t * e)
{
    const char *text = lv_label_get_text(ui_Max_Volume_Value);
    int maxVolume = atoi(text);
    maxVolume = (maxVolume > 1) ? maxVolume - 1 : 1;
    lv_label_set_text_fmt(ui_Max_Volume_Value, "%d", maxVolume);
}
// 确认保存音量设置
void saveVolumeSettings(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("VolumeCfg", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveVolumeSettings", "Failed to open NVS");
        return;
    }

    const char *text = lv_label_get_text(ui_Default_Volume_Value);
    prevDefaultVolume = atoi(text);
    err = nvs_set_u32(nvs_handle, "defaultVolume", prevDefaultVolume);
    if (err != ESP_OK) {
        ESP_LOGE("saveVolumeSettings", "Failed to set defaultVolume in NVS");
        nvs_close(nvs_handle);
        return;
    }

    text = lv_label_get_text(ui_Max_Volume_Value);
    prevMaxVolume = atoi(text);
    err = nvs_set_u32(nvs_handle, "maxVolume", prevMaxVolume);
    if (err != ESP_OK) {
        ESP_LOGE("saveMaxVolume", "Failed to set maxVolume in NVS");
        nvs_close(nvs_handle);
        return;
    }

    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveMaxVolume", "Failed to commit NVS changes");
    }
    nvs_close(nvs_handle);
}
// 取消保存音量设置
void cancelSaveVolumeSettings(lv_event_t * e)
{
    lv_label_set_text_fmt(ui_Default_Volume_Value, "%ld", prevDefaultVolume);
    lv_label_set_text_fmt(ui_Max_Volume_Value, "%ld", prevMaxVolume);
}

// ******************** ID设置 ********************
// 初始化ID设置
void initIDSettings(lv_event_t * e)
{
    uint32_t id;
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("IDSettings", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("initIDSettings", "Failed to open NVS");
        return;
    }
    err = nvs_get_u32(nvs_handle, "ID", &id);
    if (err != ESP_OK) {
        ESP_LOGE("initIDSettings", "Failed to get ID in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("initIDSettings", "Failed to commit NVS changes");
    }
    // 将 uint32_t 转换为字符串
    char id_str[12]; // uint32_t 最大值为 4294967295，需要 11 个字符的空间加上 null 终止符, 谁知道哪来的那么大ID
    snprintf(id_str, sizeof(id_str), "%lu", id);
    lv_textarea_set_text(ui_ID_Setting_Input2, id_str);
    nvs_close(nvs_handle);
}
// 确认保存ID设置
void saveIDSetting(lv_event_t * e)
{
    const char *ID = lv_textarea_get_text(ui_ID_Setting_Input2);

    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("IDSettings", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveIDSetting", "Failed to open NVS");
        return;
    }
    err = nvs_set_u32(nvs_handle, "ID", (uint32_t)atoi(ID));
    if (err != ESP_OK) {
        ESP_LOGE("saveIDSetting", "Failed to set ID in NVS");
        nvs_close(nvs_handle);
        return;
    }
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveIDSetting", "Failed to commit NVS changes");
    }
    nvs_close(nvs_handle);
}

// ******************** ID设置 ********************
// 初始化Wifi名称和密码
void initWifiSettings(lv_event_t * e)
{
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("WifiCfg", NVS_READONLY, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("initWifiSettings", "Failed to open NVS: %s", esp_err_to_name(err));
        return;
    }

    // 读取Wifi名称
    size_t required_size = 0;
    err = nvs_get_str(nvs_handle, "name", NULL, &required_size);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGE("initWifiSettings", "Failed to get size for name from NVS: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return;
    }

    if (required_size > 0) {
        char *wifiName = malloc(required_size);
        if (wifiName == NULL) {
            ESP_LOGE("initWifiSettings", "Failed to allocate memory for Bluetooth name");
            nvs_close(nvs_handle);
            return;
        }
        err = nvs_get_str(nvs_handle, "name", wifiName, &required_size);
        if (err != ESP_OK) {
            ESP_LOGE("initWifiSettings", "Failed to get name from NVS: %s", esp_err_to_name(err));
            free(wifiName);
            nvs_close(nvs_handle);
            return;
        }
        lv_textarea_set_text(ui_Bluetooth_Name_Input2, wifiName);
        free(wifiName);
    } else {
        ESP_LOGI("initWifiSettings", "Bluetooth name not set in NVS");
    }

    // 读取Wifi密码
    required_size = 0;
    err = nvs_get_str(nvs_handle, "password", NULL, &required_size);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGE("initWifiSettings", "Failed to get size for password from NVS: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return;
    }

    if (required_size > 0) {
        char *wifiPassword = malloc(required_size);
        if (wifiPassword == NULL) {
            ESP_LOGE("initWifiSettings", "Failed to allocate memory for Bluetooth password");
            nvs_close(nvs_handle);
            return;
        }
        err = nvs_get_str(nvs_handle, "password", wifiPassword, &required_size);
        if (err != ESP_OK) {
            ESP_LOGE("initWifiSettings", "Failed to get password from NVS: %s", esp_err_to_name(err));
            free(wifiPassword);
            nvs_close(nvs_handle);
            return;
        }
        lv_textarea_set_text(ui_Bluetooth_Password_Input2, wifiPassword);
        free(wifiPassword);
    } else {
        ESP_LOGI("initWifiSettings", "Bluetooth password not set in NVS");
    }

    nvs_close(nvs_handle);
}
// 确认保存WiFi名称
void saveWifiNameSetting(lv_event_t * e)
{
    const char *name = lv_textarea_get_text(ui_Wifi_Name_Input);

    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("WifiCfg", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveWifiNameSetting", "Failed to open NVS");
        return;
    }

    err = nvs_set_str(nvs_handle, "name", name);
    if (err != ESP_OK) {
        ESP_LOGE("saveWifiNameSetting", "Failed to set name in NVS");
        nvs_close(nvs_handle);
        return;
    }

    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveWifiNameSetting", "Failed to commit NVS changes");
    }

    nvs_close(nvs_handle);
}
// 确认保存WiFi密码
void saveWifiPasswordSetting(lv_event_t * e)
{
    const char *password = lv_textarea_get_text(ui_Wifi_Password_Input);

    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("WifiCfg", NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveWifiPasswordSetting", "Failed to open NVS");
        return;
    }
    err = nvs_set_str(nvs_handle, "password", password);
    if (err != ESP_OK) {
        ESP_LOGE("saveWifiPasswordSetting", "Failed to set password in NVS");
        nvs_close(nvs_handle);
        return;
    }

    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE("saveWifiPasswordSetting", "Failed to commit NVS changes");
    }

    nvs_close(nvs_handle);
}


void disconnectWifi(lv_event_t * e)
{
    wifi_disconnect();
    lv_img_set_src(ui_Wifi_Status, &ui_img_236134236);
}

void prevMusicList(lv_event_t *e)
{
    if (numMusicLists == 0)
        return;
    // 隐藏当前列表
    lv_obj_add_flag(musicLists[currentListIndex], LV_OBJ_FLAG_HIDDEN);
    
    // 切换到上一个列表
    currentListIndex--;
    if (currentListIndex < 0) {
        currentListIndex = numMusicLists - 1; // 循环到最后一个列表
    }
    
    // 显示上一个列表
    lv_obj_clear_flag(musicLists[currentListIndex], LV_OBJ_FLAG_HIDDEN);
}

void nextMusicList(lv_event_t *e)
{
    if (numMusicLists == 0)
        return;
    // 隐藏当前列表
    lv_obj_add_flag(musicLists[currentListIndex], LV_OBJ_FLAG_HIDDEN);
    
    // 切换到下一个列表
    currentListIndex++;
    if (currentListIndex >= numMusicLists) {
        currentListIndex = 0; // 循环到第一个列表
    }
    
    // 显示下一个列表
    lv_obj_clear_flag(musicLists[currentListIndex], LV_OBJ_FLAG_HIDDEN);
}

void sendATM2(lv_event_t * e)
{
	// Your code here
    bluetooth_send_at_command("AT+M2", CMD_GET_TOTAL_FILES);
}
// 播放Music List中被点击的音乐
void playSelectedMusic(lv_event_t * e)
{
    // 暂停定时器
    lv_timer_pause(musicTimer);
    // 重置进度条
    lv_bar_set_value(ui_Progress_Slider, 0, LV_ANIM_OFF);
    lv_label_set_text(ui_Current_Time, "00:00:00");
    lv_label_set_text(ui_Total_Time, "00:00:00");

    playing = true;
    lv_img_set_src(ui_Play_Pause_Icon, &ui_img_899744137);


    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *label = lv_obj_get_child(obj, 0);

    char *track_title = lv_label_get_text(label);
    lv_label_set_text(ui_Track_Title, track_title + 3);
    lv_label_set_text(ui_Track_Artist, "null");
    lv_label_set_text(ui_Total_Time, "00:00:00");

    lv_scr_load(ui_Music_Play_Window);

    // 先直接播放被点击的音乐
    char track_id[4] = {0};
    strncpy(track_id, track_title, 3);
    char command[50];
    snprintf(command, sizeof(command), "AT+AJ/music/%s*.???", track_id);
    bluetooth_send_at_command(command, CMD_PLAY_MUSIC);

    // 然后启动获取Duration的任务
    xTaskCreate(getDurationTask, "getDurationTask", 4096, NULL, 1, NULL);

    // 设置当前id
    for (int i = 0; i < total_files_count; i++) {
        if (strcmp(utf8_file_names[i], track_title) == 0) {
            printf("INDEX: %d\n", i);
            current_playing_index = i;
        }
    }
}



void nextTrack(lv_event_t * e) {
    // 暂停定时器
    lv_timer_pause(musicTimer);
    // 重置进度条
    lv_bar_set_value(ui_Progress_Slider, 0, LV_ANIM_OFF);
    lv_label_set_text(ui_Current_Time, "00:00:00");
    lv_label_set_text(ui_Total_Time, "00:00:00");

    playing = true;
    lv_img_set_src(ui_Play_Pause_Icon, &ui_img_899744137);
    
    if (current_playing_index < total_files_count - 1) {
        current_playing_index++;
    } else {
        current_playing_index = 0;
    }
    char *track_title = utf8_file_names[current_playing_index];
    // 跳过编号
    lv_label_set_text(ui_Track_Title, track_title + 3);
    lv_label_set_text(ui_Track_Artist, "null");

    bluetooth_send_at_command("AT+CC", CMD_NEXT_TRACK);
    xTaskCreate(getDurationTask, "getDurationTask", 4096, NULL, 1, NULL);
}

void prevTrack(lv_event_t * e) {
    // 暂停定时器
    lv_timer_pause(musicTimer);
    // 重置进度条
    lv_bar_set_value(ui_Progress_Slider, 0, LV_ANIM_OFF);
    lv_label_set_text(ui_Current_Time, "00:00:00");
    lv_label_set_text(ui_Total_Time, "00:00:00");

    playing = true;
    lv_img_set_src(ui_Play_Pause_Icon, &ui_img_899744137);

    if (current_playing_index > 0) {
        current_playing_index--;
    } else {
        current_playing_index = total_files_count - 1;
    }
    char *track_title = utf8_file_names[current_playing_index];
    // 跳过编号
    lv_label_set_text(ui_Track_Title, track_title + 3);
    lv_label_set_text(ui_Track_Artist, "null");

    bluetooth_send_at_command("AT+CD", CMD_PREV_TRACK);
    xTaskCreate(getDurationTask, "getDurationTask", 4096, NULL, 1, NULL);
}

void PlayPause(lv_event_t * e) {
    bluetooth_send_at_command("AT+CB", CMD_PLAY_PAUSE);
    if(playing) {
        lv_timer_pause(musicTimer);
        lv_img_set_src(ui_Play_Pause_Icon, &ui_img_2101671624);
        playing = false;
    } else {
        lv_timer_resume(musicTimer);
        lv_img_set_src(ui_Play_Pause_Icon, &ui_img_899744137);
        playing = true;
    }
}


void sendATAJ(lv_event_t * e)
{
	// Your code here
}

void releasedProgressSlider(lv_event_t * e)
{
    int percentage = lv_slider_get_value(ui_Progress_Slider);
    currentPlayTime = (percentage * current_music_duration) / 100;

    char time_str[9]; // hh:mm:ss
    format_time(currentPlayTime, time_str, sizeof(time_str));
    lv_label_set_text(ui_Current_Time, time_str);

    // 跳转
}

