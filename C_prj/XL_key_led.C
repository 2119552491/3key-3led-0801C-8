
#include "XL_common.h"

void Key_scan();

#if XL_Key_led
byte add_F1;
byte add_F;
byte add_F2;
#if XL_key_1
	byte key1_tick; 
	 
	#if XL_key_1_long
		bit KEY_long_time_F1; 
	#endif	
#endif

#if XL_key_2
	byte key2_tick;
	#if XL_key_2_long
		bit KEY_long_time_F2; 
	#endif
#endif

#if XL_key_3
	byte key3_tick;
	#if XL_key_3_long
		bit KEY_long_time_F3; 
	#endif
#endif

#if XL_key_4
	byte key4_tick;
	#if XL_key_4_long
		bit KEY_long_time_F4; 
	#endif
#endif

#if XL_key_5
	byte key5_tick;
	#if XL_key_5_long
		bit KEY_long_time_F5; 
	#endif
#endif

void Key_scan()
{

	#if XL_key_3
			key3_tick++;
	#endif  
	#if XL_key_2
			key2_tick++;
	#endif

	#if XL_key_4
			key4_tick++; 
	#endif		
	#if XL_key_5
			key5_tick++;
	#endif	 
		
	//if( g_comval.IR_LED_ON_F == 1 )  // g_comval. ON_F  led_level_init_F
	{ 
		#if XL_key_1
				key1_tick++;
		#endif
	}

	#if IO_fuyong           
			//IOSTA =  GLJC_in_mode;//0  U1_2mode 
			//U1_2 = 1;  

			
		//	XL_temp_count = 0;
        	//	XL_temp_count = 0x23;//T_Key1_mode | T_Key2_mode | T_Key5_mode  ; //
			//PORTB = GPIO_INIT_;
			
			IOSTB = GPIO_INIT_  ; //Jingzheng_IN_mode_init | T_Key4_mode |
			/*
        		T_Key1_Signal = 1;
        		T_Key2_Signal = 1;
        		T_Key5_Signal = 1;
			*/

			Delay10us();
			Delay10us();
			Delay10us();  
			

			//Delay10us();
	#endif
#if XL_key_3  
 
	if( T_Key3_Signal == 0 ) //  speed
	{
		if(key3_tick >= key_long_time ) // 
		{
			key3_tick  = key_long_time;
#if XL_key_3_long
			if( KEY_long_time_F3 == 0 )
			{	
				KEY_long_time_F3 = 1;
			}
#endif
		}
	}
	else
	{
		if (  key3_tick >= Key_short_time   ) // 
		{      
			short_mode_init_F = 1;
#if XL_key_3_long
			if ( KEY_long_time_F3 == 0 )
#endif
			{
				
						if( LED_G )		LED_G = 0;
				else	if( LED_G == 0)	LED_G = 1;
				/*
				if( g_comval.IR_LED_ON_F )
				{
					g_comval.IR_LED_ON_F	= 0;
				}
				else
				{
					g_comval.IR_LED_ON_F = 1;
				}     
				*/           
			}
		}
		key3_tick = 0;
	//	KEY_long_time_F3 = 0;
	} 
#endif

#if XL_key_1
	if( T_Key1_Signal == 0 ) //  LED
	{
		if(key1_tick >= key_long_time ) // 
		{
			key1_tick  = key_long_time;

#if XL_key_1_long

			if( KEY_long_time_F1 == 0 )
			{	
				KEY_long_time_F1 = 1;


				short_mode_init_F = 1;
			}
#endif
		}
	}
	else
	{
		if (  key1_tick >= Key_short_time   ) // 
		{         
#if XL_key_1_long
			if ( KEY_long_time_F1 == 0 ) 
#endif
			{
				short_mode_init_F = 1;

			}

		}
		key1_tick = 0;
#if XL_key_1_long
		KEY_long_time_F1 = 0;
#endif
	}
#endif

#if XL_key_2//
		if( T_Key2_Signal == 0 || T_Key1_Signal == 0 || T_Key3_Signal  == 0) //   sub
		{
			if( key2_tick >= key_long_time ) // 
			{         
				key2_tick  = key_long_time;
#if XL_key_2_long//
			//	sub_F = 1;
				if( KEY_long_time_F2 == 0 )
				{	
					KEY_long_time_F2 = 1;
					if( add_F )
						IR_KEY_L_deal = 203;
					else
						IR_KEY_L_deal = 201;
				}
#endif
			}
		}
		else
		{
			if (  key2_tick >= Key_short_time   ) // add 
			{        
#if XL_key_2_long//
				IR_KEY_L_deal = 0;
				if ( KEY_long_time_F2 == 0 )   
#endif
				{
					short_mode_init_F =1; 
					if( IR_LED_ON_F )
					{
						IR_LED_ON_F = 0;  //g_comval.led_mode++; 
					}
					else	         
					{
						IR_LED_ON_F = 1;  
						//if( g_comval.led_mode == 0 )
						{
						//	g_comval.led_mode = 1;
						}            
					}          
				}  
#if XL_key_2_long
				if( add_F )		add_F = 0;
				else	if( add_F == 0)	add_F = 1;
#endif	
			}
			key2_tick = 0;
#if XL_key_2_long//
			KEY_long_time_F2 = 0;
#endif
		}

#endif


#if XL_key_4
		if( T_Key4_Signal == 0 ) //  //  LED
		{
			if( key4_tick >= key_long_time )  
			{
				key4_tick  = key_long_time;
#if XL_key_4_long //  #endif

				if( KEY_long_time_F4 == 0 )
				{	
					KEY_long_time_F4 = 1;
					IR_KEY_L_deal = 203;
				}

#endif
			}
		}
		else
		{
			if (  key4_tick >= Key_short_time   )  
			{
				short_mode_init_F = 1;
				sleep_mode_init_F = 1;
				if ( KEY_long_time_F2 == 0 )
				{

					//levlel_short_sub();
				}              
#if XL_key_4_long //  #endif
				IR_KEY_L_deal = 0;
#endif
			}
			key4_tick = 0;
			KEY_long_time_F4 = 0;
		}     

#endif

#if XL_key_5

		if( T_Key5_Signal == 1 ) //  //  LED
		{
			if( key5_tick >= Key_short_time )  
			{
				key5_tick  = Key_short_time;
				short_mode_init_F = 1;
				if( KEY_long_time_F5 == 0 )   
				{           
					KEY_long_time_F5 = 1;  
					g_comval.IR_LED_ON_F = 1;
				}
#if XL_key_5_long //  

		//	if( KEY_long_time_F5 == 0 )
			{	
		//		KEY_long_time_F5 = 1;
			}

#endif
			}
		}
		else
		{
			if (  key5_tick >= Key_short_time   )  
			{
				sleep_mode_init_F = 1;
				short_mode_init_F = 1;  
				g_comval.IR_LED_ON_F = 0;

			//	if ( KEY_long_time_F5 == 0 )
				{        

				}
			}
			key5_tick = 0;
			KEY_long_time_F5 = 0;
		}  
#endif

#if IO_fuyong//0//// 0 //  
	          
        /*
	T_Key1_Signal = 0;
	T_Key2_Signal = 0;
	T_Key3_Signal = 0;
	T_Key4_Signal = 0;*/
	IOSTB = T_Key5_mode;// GPIO_INIT_  T_Key5_mode  0xff-XL_temp_count  ;// Jingzheng_IN_mode_init IN_mode_init 
	
	T_Key1_Signal = 0;
	T_Key2_Signal = 0;
	T_Key3_Signal = 0;
	T_Key4_Signal = 0;
	
	Delay10us();
	Delay10us();
	Delay10us();       
  	if( g_comval.IR_LED_ON_F )          
	{
			if( g_comval.led_level == led_level_1_2_Max )
				T_Key1_Signal = 1;// on_off_Blue_led
			else
				T_Key1_Signal = 0;

			if( Time_mode == 5 )
				T_Key2_Signal = 1;// on_off_Blue_led
			else
				T_Key2_Signal = 0;

			if( Time_mode == 25 )
				T_Key3_Signal = 1;// on_off_Blue_led
			else
				T_Key3_Signal = 0;

			if( Time_mode == 60 )
				T_Key4_Signal = 1;// on_off_Blue_led
			else
				T_Key4_Signal = 0;

/*
			if( Time_mode == 60  || Time_mode == 180 )
				T_Key4_Signal = 1;// on_off_Blue_led
			else
				T_Key4_Signal = 0;   
				
			U1_2 = 0;
		
*/       
	}
	/*
	else
	{                        
		T_Key1_Signal = 0;
		T_Key2_Signal = 0;
		T_Key3_Signal = 0;
		T_Key4_Signal = 0;
	}  */
#endif  
}

#endif