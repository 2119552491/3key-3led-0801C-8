
#include "XL_common.h"  


#if XL_Sleep_time	
bit sleep_mode_init_F;
byte Time_mode; 
	#if XT_Clock 

	#else
		byte Sleep_time_50us_tick;
	#endif

byte Sleep_time_10ms_tick;
byte Sleep_time_1s_tick;
byte Sleep_time_1min_tick;
//byte Sleep_time_1h_tick;

#if XL_Sleep_led_Flash_warning

bit LED_Flash_warning_F;

#endif

#if XT_Clock 

void sleep_time_deal_function()
{
	if(  Time_mode  )  // && Sleep_time_50us_tick >= 10IR_LED_ON_F ON_F == 1 &&
	{    
		if (Sleep_time_50us_tick >= 200 ) 	//  20	  100
		{              
			Sleep_time_50us_tick =0;
		 	Sleep_time_10ms_tick++;	 	//	Sleep_time_50us_tick= Sleep_time_50us_tick - 10 ; //  		   
			if (Sleep_time_10ms_tick >= 100  )//   200  5	  
			{
				Sleep_time_10ms_tick=0;	
				Sleep_time_1s_tick++; // 	   
			//	if (Sleep_time_1s_tick >= 180   ) //   60 1    60
				{
			//		Sleep_time_1s_tick=0;
			//		Sleep_time_1min_tick++; //  Sleep_time_1min_tick  
					
					if ( Sleep_time_1s_tick  >=  Time_mode ) // 60  led_speed_Max 
					{                             
                        			Sleep_time_1s_tick = Time_mode;  
						short_mode_init_F = 1; 
                                                
                                                g_comval.IR_LED_ON_F = 0;
                                                //Time_mode            = ;
                                                /*
						Time_mode = 240 - Time_mode;  // 240 
						if( g_comval.IR_LED_ON_F )
							g_comval.IR_LED_ON_F = 0;
						else    
							g_comval.IR_LED_ON_F = 1; 
						*/

					}
                                }
			}
		}
	}
}

#else

void sleep_time_deal_function()
{
	if(  Time_mode  )  // && Sleep_time_50us_tick >= 10IR_LED_ON_F ON_F == 1 &&
	{    
		if (Sleep_time_50us_tick >= 200 ) 	//  20	  100
		{              
			Sleep_time_50us_tick =0;
		 	Sleep_time_10ms_tick++;	 	//	Sleep_time_50us_tick= Sleep_time_50us_tick - 10 ; //  		   
			if (Sleep_time_10ms_tick >= 100  )//   200  5	  
			{
				Sleep_time_10ms_tick=0;	
				Sleep_time_1s_tick++; // 	   
				//if (Sleep_time_1s_tick >= 60   ) //   60 1    60
				{
				//	Sleep_time_1s_tick=0;
				//	Sleep_time_1min_tick++; //  Sleep_time_1min_tick  
					
					if ( Sleep_time_1s_tick  >=  Time_mode ) // 60  led_speed_Max 
					{                             
                        			Sleep_time_1s_tick = Time_mode;  
						short_mode_init_F = 1; 

						//Time_mode = 0;
						g_comval.IR_LED_ON_F = 0;

					}
                                }
			}
		}
	}
}

#endif

#endif