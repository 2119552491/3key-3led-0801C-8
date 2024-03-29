
extern byte LED_R_PWM_expect;
extern byte LED_G_PWM_expect;
extern byte LED_B_PWM_expect;

extern byte RTC_mode;
extern byte Color_mode;
extern byte Color_mode_temp;

extern byte led_mode;

extern byte led_level;
extern byte led_speed;
//extern byte led_level_count;
//extern bit led_level_init_F;
extern byte led_level_adjust_temp;

extern byte led_level_255_1;
extern byte XL_temp_count;

extern byte RTC_led_level;
extern byte LED_duty;

extern void LED_Color_LEVEL_TABLE();
extern void LED_Color_LEVEL_TEMP_TABLE();
extern void LED_PWM_4_LEVEL_TABLE(); 
extern void LED_PWM_16_LEVEL_TABLE(); 
                            
              
                            
extern const u8 R_LED_Color_LEVEL_TABLE[];
extern const u8 G_LED_Color_LEVEL_TABLE[];
extern const u8 B_LED_Color_LEVEL_TABLE[];



extern const u8 LED_liushui_JUMP_Mode_TABLE[];
extern const u8 LED_7_JUMP_Mode_TABLE[];
extern const u8 HC_qicailiushui_TABLE[]; 

extern byte R_Color_Level;
extern byte G_Color_Level;
extern byte B_Color_Level;

extern void Color_INIT_LEVEL_TAB();

extern byte led_level_16_2;
extern byte led_level_16_3;
extern byte led_level_16_4;
extern byte led_level_16_5;

extern byte led_level_16_6;
extern byte led_level_16_7;
extern byte led_level_16_8;
extern byte led_level_16_9;

extern byte led_level_16_10;
extern byte led_level_16_11;
extern byte led_level_16_12;
extern byte led_level_16_13;

extern byte led_level_16_14;
extern byte led_level_16_15;