
#include "XL_common.h"

void time_50us_tick_function(); 

//byte Led_time_50us_tick; 
byte time_50us_tick;
byte time_1ms_tick;  
byte time_10ms_tick;
//byte time_300ms_tick;
byte Led_time_1ms_tick; 
byte time_led_speed_ms_tick;
byte ir_long_tick_err;
 
byte LVD_count;
#define     LVD_count_num 250
#if 0//vel_add_sub & led_speed_add_sub

void levlel_short_add();
void levlel_short_sub();
   
void short_key_add()  
{
	if( g_comval.led_mode <= Color_mode_Max  )
	{
#if  level_fanzhuang  
		if( g_comval.led_level == led_level_Max  )
		{
#if XL_Sleep_led_Flash_warning
			Flash_warning = LED_Flash_time;
#endif
			g_comval.led_level = led_level_Min;
		}
		else
#endif
		{
			if( g_comval.led_level >= led_level_Max - short_key_Light_variety_range ) // led_level_Max
			{
#if XL_Sleep_led_Flash_warning
				Flash_warning = LED_Flash_time;
#endif
				g_comval.led_level = led_level_Max;
			}
			else
				g_comval.led_level += short_key_Light_variety_range;
		}
	}
	else if( g_comval.led_mode <= Color_mode_Max + RTC_mode_Max )
	{             
		short_mode_init_F = 0;
#if  led_speed_fanzhuang
		if( g_comval.led_speed == led_speed_Min  )
		{
	//		Flash_warning = LED_Flash_time;
			g_comval.led_speed = led_speed_Max;
		}
		else
#endif
		{
			if( g_comval.led_speed <= led_speed_Min + speed_variety_range )
			{
#if XL_Sleep_led_Flash_warning
				Flash_warning = LED_Flash_time;
#endif
				g_comval.led_speed = led_speed_Min;
			}
			else
				g_comval.led_speed -= speed_variety_range;
		}
	}
}

void short_key_sub()
{
	if( g_comval.led_mode <= Color_mode_Max  )
	{

#if  level_fanzhuang
		if( g_comval.led_level == led_level_Min )
		{
	//		Flash_warning = LED_Flash_time;
			g_comval.led_level = led_level_Max;
		}
		else
#endif
		{
			if( g_comval.led_level <= led_level_Min + short_key_Light_variety_range )
			{
		//		Flash_warning = LED_Flash_time;
				g_comval.led_level = led_level_Min;
			}
			else
				g_comval.led_level -= short_key_Light_variety_range;
		}
	}
	else if( g_comval.led_mode <= Color_mode_Max + RTC_mode_Max )
	{
                short_mode_init_F = 0;
#if  led_speed_fanzhuang
		if( g_comval.led_speed == led_speed_Max )
		{
	//		Flash_warning = LED_Flash_time;
			g_comval.led_speed = led_speed_Min;
		}
		else
#endif
		{
			if( g_comval.led_speed >= led_speed_Max - speed_variety_range ) // LED_LEVEL_Max
			{
#if XL_Sleep_led_Flash_warning
				Flash_warning = LED_Flash_time;
#endif
				g_comval.led_speed = led_speed_Max;
			}
			else
				g_comval.led_speed += speed_variety_range;
		}
	}
}     
#endif


void time_50us_tick_function()
{
    if( time_50us_tick >= 20) // time_50us_tick
    {
        time_50us_tick = time_50us_tick - 20 ; // Led_time_1ms_tick

		time_1ms_tick++;
		if ( IR_LED_ON_F == 1) // kaiji
		{
			if( led_level_temp < led_level )  
				  led_level_temp++;
			else if( led_level_temp > led_level )
				  led_level_temp--;
		}
		else
		{    
			if( led_level_temp )  
				  led_level_temp--;
		}         
		
		Led_mode_deal();  
#if RGB_Color
		Led_time_1ms_tick++;
#endif  

#if XL_Wuxian
		ir_long_tick_err++;

		if ( ir_long_tick_err >= 150 ) // 9MS   6-12MS
		{
			ir_long_tick_err	=  0;
			if( IR_SETP != 0 )
			{
				ir_err_f = 1;
			}
		}
//		duima_1ms_tick++;
		ir_long_tick++;
#endif

		if( time_1ms_tick >= 10 )
		{
			time_1ms_tick = 0;
			time_10ms_tick++;
			#if GPC_LVD   // #endif
			if( IR_LED_ON_F == 1 )  
			{  
				if( STATUS_.LVDF   )//   
		    	{                       
					LVD_count = 0;
					//LED_G = 1;  
				}
				else                 
				{        
				//	LED_G = 0;
				       	LVD_count++;
				       	if( LVD_count >= LVD_count_num )
				       	{
				       		LVD_count = 0;
				       		IR_LED_ON_F = 0;
				       	} /*
                               		if( LED_B )
                               			LED_B = 0;
                               		else
                               			LED_B = 1;*/
                }
			}  
                        #endif  
			#if XL_Sleep_time 
				sleep_time_deal_function();
			#endif	

			#if XL_Sleep_IC
				IC_SLEEP();
			#endif	

			#if XL_Key_led
				Key_scan();
			#endif
#if IR_Long_key
			switch( IR_KEY_L_deal )
			{/*
				case 51:
					short_mode_init_F = 0;
					g_comval_sensitivity -- ;
					break;
				case 53:
					short_mode_init_F = 0;
					g_comval_sensitivity ++ ;
					break;
				case 101:
					short_mode_init_F = 0;
					led_speed -- ;
					break;
				case 103:
					short_mode_init_F = 0;
					led_speed ++ ;
					break;*/
				case 201:
					if( led_level >= led_level_Max )
						led_level = led_level_Max;
					else
						led_level ++  ;
					break;
				case 203:
					if( led_level <= led_level_Min)
						led_level = led_level_Min;
					else
						led_level -- ;
					break;
				default: 
					break;
			}     
			
                        
			//Color_INIT_LEVEL_TAB();
			engint;
#endif                      

		}
    }
}

