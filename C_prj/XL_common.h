
 

#include "W1631.h"
#include "XL_IO_config.h" 


#include "XL_IR.h"

#include "XL_key_juzheng.h" 
#include "XL_key_led.h"

#include "XL_time1.h"   
#include "XL_parameter.h"
#include "XL_sleep_dingshi.h"
#include "XL_sleep_IC.h"   
#include "XL_init.h"
#include "XL_RGB_Color.h" 
#include "XL_RGB_Jump.h"
#include "XL_table.h"     
#include "XL_RGB_fade.h"
//#include "XL_HC_qicailiushui.h" 
//#include "XL_HC_one_color_liushui_9999999900.h"

//#include "XL_HC_fade.h"   
#include "XL_I2C24C02.h"   





#define GPC_LVD              1
#define PMW                  1


#define XL_Wuxian 		          0
#define XL_wuxian_IR      	      0    //4
#define XL_wuxian_433      	      0    //4
#define XL_wuxian_duima      	  0    //4

#define XL_Sleep_led_Flash_warning 		    0
#define XL_level_led_Flash_warning 		    0
#define XL_speed_led_Flash_warning 		    0
#define XL_AD_led_Flash_warning 		    0
#define XL_mode_led_Flash_warning 		    0
#define XL_music_mode_led_Flash_warning     0

#define LED_Flash_time  				    1

#define level_add_sub			0

#define Color_mode_Max  16//1//49
#define RTC_mode_Max    0//2
#define MIC_mode_Max    0 

#define RTC_mode_auto_Max 0

            
#define Key_long_time  50 // 13  
#define key_long_time  50
#define Key_short_time 5              
#define key_short_time 5 
               
#define Led_num_Max   200         
#define Led_num_Min   10
                
#define IR_Long_key     1                
 

#define led_level_1_16_Max 	 			16 // 240+8//
#define led_level_1_8_Max 	 			led_level_1_16_Max + led_level_1_16_Max // 240+8//
#define led_level_1_4_Max 	 			led_level_1_8_Max + led_level_1_8_Max // 240+8//
#define led_level_2_4_Max 	 			led_level_1_4_Max + led_level_1_4_Max // 240+8//
#define led_level_3_4_Max 	 			led_level_1_4_Max + led_level_1_4_Max + led_level_1_4_Max// 240+8//


#define led_level_Min 	 	 			25//12//led_level_1_16_Max//101//41//  410// 820//
#define led_level_Max 	 	 			250//250//led_level_2_4_Max + led_level_2_4_Max - 1//240+8//200// 200//100// 2048//4096//16//  8192//
#define short_key_Light_variety_range	led_level_1_16_Max//33//// 53//


#define user_color_define		0
#define level_limit			    0
#define level_fanzhuang			0


#define led_speed_Max      		24//led_speed_2_4_Max + led_speed_2_4_Max//15//165//20
#define led_speed_Min 	   		3//led_speed_1_4_Max//15//3//2//10
#define led_speed_Mid      		20//10//11
#define speed_variety_range  	led_speed_Min//15//2


#define led_speed_limit			0
#define led_speed_fanzhuang	 	0            
#define led_speed_add_sub	 	0 


#define long_48_RGB_table        0
          
#define  XL_huancai 		     0
#define  RGB_color           	 1
#define  W_Color 			  	 1
#define  YW_Color 				 0
#define  XL_huancai_one_mode 	 0 
     
#define SYSCLK_8M    0

#define XL_send_GRB			 	  1
#define XL_send_BRG			 	  0

#define XL_HC_RGB_fade 		   		0
#define XL_HC_RGB_qicailiushui 		0

#define led_mode_max_limit	 0


#define XL_RTC_3fade 		 0
#define XL_RTC_7fade 		 0
#define XL_RTC_fade 		 XL_RTC_3fade + XL_RTC_7fade

                        
///////////////////////////////////////////////////
#define XL_RTC_huxi			 0

#define XL_RTC_JUMP 		    0                 
#define XL_RTC_liushui_JUMP     0

#define XL_Key_juzheng	 		0  
#define XL_Key_led	 	        1 // 
#define IO_fuyong		        0


#define XL_parameter   		 0                               
#define XL_24C02    		 0
#define XL_Sleep_time            0   
#define XL_Sleep_led_Flash_warning 0
#define XL_Sleep_IC              1

                                   
#define nop   NOP();
#define disgint DIS_IRQ();   
#define engint EN_IRQ();

#define GOTO goto   
