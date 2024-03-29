

#include "XL_common.h" 


byte IR_KEY_L_deal; 

#if XL_Wuxian
void IR_DECODE();
void IR_KEY_DEAL();
void IR_Key_Table();


u8 ir_tick;
byte IR_SETP;
byte ir_long_tick;

byte IR_KEY_L;


bit ir_err_f;
bit IR_H_F;
bit ir_repeat_f;



bit ir_ok_F;
bit ir_deal_F;
bit ir_end_F;
byte ir_count;


#if  XL_wuxian_IR
	u8 IR_KEY_H;
#endif

#if  XL_wuxian_433
	u8 IR_KEY_L1;
#endif




//////////bu dui dizhi ma 
u8 ADDR_H;
byte ADDR_L;

void IR_DECODE()
{
#if XL_wuxian_433
	if (IR_in == 1)
	{                   

		if (!IR_H_F)
		{
			if (IR_SETP == 1)
			{
				if ((ir_tick > 150) && (ir_tick < 250)) // 9MS   5.5-7MS
				{
					IR_SETP++;
				}
				else
					ir_err_f = 1;
			}
			else if ((IR_SETP >= 3) && (IR_SETP < 50))
			{
				if ((ir_tick >= 2) && (ir_tick < 35)) // 200-1000
				{
					IR_SETP++;
				}
				else
					ir_err_f = 1;
			}
			ir_tick = 0;
			IR_H_F = 1;
		}
	}
	else
	{
		if (IR_H_F)
		{
			//ir_long_tick = 0;
			if (IR_SETP == 0)
			{
				IR_SETP++;
			}
			else if ((IR_SETP >= 2) && (IR_SETP < 50))
			{
				if ((ir_tick >= 2) && (ir_tick < 40)) // 400-2MS IR_time_1mS_tick
				{
					IR_SETP++;  
					
					asm{
					{
			   	   	    //RLR  IR_KEY_H;
			                    RLR  IR_KEY_L;
			                  //  RLR  ADDR_H;
			                  //  RLR  ADDR_L;
					};

					if (ir_tick > 15)
					{          
						IR_KEY_L = IR_KEY_L | 0x01;  

					}
					else
					{           
						IR_KEY_L = IR_KEY_L & 0xFE; 
	
					}					

					if (IR_SETP == 49)
					{
						if( (IR_KEY_L1 != IR_KEY_L ) ) // && IR_KEY_L2 == IR_KEY_L && IR_KEY_L3 == IR_KEY_L
						{
							IR_KEY_L1 = IR_KEY_L;
						}
						else
						{
							ir_end_F = 1;
							ir_ok_F = 1; 
						//	ir_deal_F = 0;
						//	ir_count = 0;				
						}
						ir_long_tick = 0;
					}
				}
				else
					ir_err_f = 1;
			}
			else
			{
				IR_SETP = 1;
			}
			ir_tick = 0;
			IR_H_F = 0;
		}
	}
#endif

#if XL_wuxian_IR

	if (IR_in == 1)
	{                
		if (!IR_H_F)
		{
			if (IR_SETP == 1)
			{
				if ((ir_tick > 20) ) //&& (ir_tick < 254) 9MS   6-12MS
				{                  
				//	LED_R = 1;
					IR_SETP++;
					ir_long_tick_err = 0;
				}
				else
					ir_err_f = 1;
			}
			else if ((IR_SETP >= 3) && (IR_SETP < 67))
			{
				if ((ir_tick > 4) && (ir_tick < 20)) // 200-1000
				{
					if(ir_repeat_f==1)
					{
                     				ir_repeat_f=0;
				  	 	IR_SETP=0;
					}
                   		 	else
					{
						IR_SETP++;
					}
				}
				else
					ir_err_f = 1;
			}
			ir_tick = 0;
			IR_H_F = 1;
		}
	}
	else
	{       

		if (IR_H_F)
		{
			ir_long_tick = 0;
			if (IR_SETP == 0)
			{
				IR_SETP++;
			}
			else if (IR_SETP == 2)
			{         
				
				if ((ir_tick > 20) && (ir_tick < 110)) // 50*60=3ms  3000-5500
				{            
					ir_repeat_f = 0;
					IR_KEY_H = 0;
					IR_KEY_L = 0;
					ADDR_H = 0;
					ADDR_L = 0;
					IR_SETP++;
				}
				/////////////////   �ӳ����ĵط�
				/*
				else  if((ir_tick>35)&&(ir_tick<60)) //50*60=3ms  <
				{
					IR_SETP++;
                   			ir_ok_F=1;
					ir_repeat_f = 1;
					//IR_Long_KEY_tick=0;
				}*/
				
				////////////////////////
				else
				{        
				//	LED_R = 0;
					ir_err_f = 1;
				}
			}
			else if ((IR_SETP >= 2) && (IR_SETP < 67))
			{            
				
				if ((ir_tick > 4) && (ir_tick < 40)) // 400-2MS
				{             
					
					IR_SETP++;         
					asm{
					{
			   	   	    RRR  IR_KEY_H;
			                    RRR  IR_KEY_L;
			                    RRR  ADDR_H;
			                    RRR  ADDR_L;
					};

					if (ir_tick > 20)
					{          
						IR_KEY_H = IR_KEY_H | 0x80;
						//IR_KEY_H .7 = 1;
					}
					else
					{           
						IR_KEY_H = IR_KEY_H & 0x7F; 
						//IR_KEY_H .7 = 0;
   	   	   	   	   	   	
					}
					if (IR_SETP == 67)
					{
						ir_end_F = 1;
						ir_ok_F = 1;    
						ir_deal_F = 0;
						ir_count = 0;
						ir_long_tick_err = 0;
						//ir_long_tick = 0;

					}
				}
				else
					ir_err_f = 1;
			}
			else if (IR_SETP == 68)
				IR_SETP++;
			else
			{
				IR_SETP = 1;
			}
			ir_tick = 0;
			IR_H_F = 0;
		}
	}
#endif
	if (ir_err_f )
	{
	//	ir_long_tick = 0;
		ir_err_f = 0;
		ir_repeat_f = 0;
		IR_SETP = 0;
		IR_KEY_L = 0xff;
	//	ir_end_f   = 0;
	}

	if(ir_end_F)
	{
#if XL_wuxian_IR
		if(ir_long_tick > 100)    //  160   �ߵ�ƽʱ�����120ms��Ϊң������̧��
#endif

#if XL_wuxian_433
		if(ir_long_tick > 100)    // 220 160   �ߵ�ƽʱ�����120ms��Ϊң������̧��
#endif
		{    

#if IR_Long_key    
			short_mode_init_F = 1;  
			switch( IR_KEY_L_deal )
			{
				case 200:
					levlel_short_add();
					break;
				case 202:
					levlel_short_sub();
					break;
			}
#endif
			IR_KEY_L_deal = 0; 
			ir_count = 0;
			ir_end_F = 0;
			ir_deal_F = 0;

			ir_repeat_f = 0;
			ir_long_tick   = 0;
			IR_KEY_L = 0;     
			IR_SETP = 0;
			//IR_KEY_L1= 0;
			// Write_Eeprom();

#if XL_24C02		   
			save_comval();
#endif
		}
	}
}
  
#if XL_wuxian_IR
	#define ir_count_repeat 3
#endif

#if XL_wuxian_433
	#define ir_count_repeat 6
#endif
  
void IR_KEY_DEAL()  //
{         
	u8 key_loop_time;
	
	if ( ir_ok_F == 0 )
		return;
	ir_ok_F = 0;  	


	ir_count++; // 
	if (ir_count >= ir_count_repeat)
	{
	//	ir_count = 4;
		return;
	}



//	IR_Dui_Ma_DEAL();  	//	duima

//	if( return_F )
//		return;
	if (ir_deal_F == 1)
		return;
	ir_deal_F = 1;  
	        
	if ( ADDR_L != 0x00  ) //0xE2 0xE2 0xFF 0xBA   0x12 0x00 0xE2
		return;	
	if ( ADDR_H != 0xFF ) // 0xFB 0xFF 0x21 0xFB  0xF6 0xCF 0xEF 0xFB
		return;			 // 
		 //   0x28
                   
	key_loop_time = 0;

	        /*
	if( IR_KEY_L == 0x01 )      // 0x25
	{
		if( LED_R )
			LED_R = 0; 
		else
			LED_R = 1;  
	}            */
	short_mode_init_F = 1; 
#if IR_KEY_L_ON_OFF


	if( IR_KEY_L == IR_KEY_L_ON )      // 0x25
	{
		if( g_comval.IR_LED_ON_F )
		{
			g_comval.IR_LED_ON_F = 0; 
#if XL_Sleep_time
			Time_mode   = 0;
#endif
		}
		else
		{
			g_comval.IR_LED_ON_F = 1; 
		}
	}  


#else

	g_comval.IR_LED_ON_F = 1; 
	if( IR_KEY_L == IR_KEY_L_OFF )      // 0x25
	{
		g_comval.IR_LED_ON_F = 0; 
#if XL_Sleep_time
		Time_mode   = 0;
#endif
		return;	
	}  
/*
	if( IR_KEY_L == IR_KEY_L_ON )      // 0x25
	{
		g_comval.IR_LED_ON_F = 1; 
		return;	
	}  
*/

#endif
	if( g_comval.IR_LED_ON_F )      // 0x25
	{  

		SMG_byte_to_suzhu( IR_KEY_L ); 
		SMG_abcdefg_value_get();
	}   
#if 0 
	if( g_comval.IR_LED_ON_F )      // 0x25
	{         
		switch( IR_KEY_L )
		{          
			case led_mode_add_key:  //0x0C  IR_KEY_L_speed_add
				g_comval.led_mode++;

			case 0x0C:   
				ir_deal_F = 0;       
				IR_KEY_L_deal = 200; 
				if(ir_count >= ir_count_repeat - 1) //
				{
					IR_KEY_L_deal  = 201;
				}
				break;   
			case 0x0B:          
				ir_deal_F = 0;       
				IR_KEY_L_deal = 202; 
				if(ir_count >= ir_count_repeat - 1) //
				{
					IR_KEY_L_deal  = 203;
				}
				break;  /*  
			case 7:
				g_comval.led_mode=8;
				break;
			case 9:
				g_comval.led_mode++;
				if( g_comval.led_mode >= Color_mode_Max + 1 )
					g_comval.led_mode = 1;
				break;   */
			case 0x05:        
				sleep_mode_init_F = 1;
				Time_mode = 20;//360
				break;
			case 0x06:      
				sleep_mode_init_F = 1;
				Time_mode = 40;
				break;
			case 0x02:        
				sleep_mode_init_F = 1;
				Time_mode = 60;
				break;      
			case 0x01:
				//sleep_mode_init_F = 1;
				Time_mode = 0;
				break;   

		} 
	}              
#endif
}



#endif

#if 0 



void IR_Key_Table()
{
	a += 1;
	pcadd a;
	ret 10//255 

	ret 10
	ret 0 //
	ret 13
	ret 16
	ret 19

	ret 11
	ret 0 //
	ret 14
	ret 17
	ret 20

	ret 12
	ret 0 //
	ret 15
	ret 18
	ret 21

	ret 0 //
	ret 1
}

		while(1)
		{
			key_loop_time++;
			a = key_loop_time;
			IR_Key_Table();
			if(IR_KEY_L==a)
			{
				if( key_loop_time <= Color_mode_Max)
				{
				//	Color_mode = key_loop_time;
					led_mode = key_loop_time;// short_mode_init_F = 1;
				//	RTC_mode =0; // LED_W
				}
				break;
			}
			if(key_loop_time >= Color_mode_Max +1 )
			{
				break;
			}
		}

		switch( led_mode  ) 
		{
			case 17:// 
				key_mode = 1;
				break;
			case 1:// auto
				key_mode = 2;
				break;
			case 6:// auto
				key_mode = 3;
				break;
			case 11:// auto
				key_mode = 4;
				break;
			case 3:// auto
				key_mode = 5;
				break;
			case 5:// auto
				key_mode = 6;
				break;
			case 15:// auto
				key_mode = 7;
				break;
			case 10:// auto
				key_mode = 8;
				break;
			case 13:// auto
				key_mode = 9;
				break;
			case 18://  Color_mode_Max + 1
				key_mode = 10;
				break;
			case 19://  Color_mode_Max + 2
				key_mode = 11;
				break;
			case 20 :// auto  Color_mode_Max + 3
				key_mode = 12;
				break;
			case 21 :// auto  Color_mode_Max + 4
				key_mode = 13;
				break;
			case 22 :// auto Color_mode_Max + 5
				key_mode = 14;
				break;
			case 23:// auto Color_mode_Max + 6
				key_mode = 15;
				break;
			case 24 :// auto Color_mode_Max + 7
				key_mode = 16;
				break;
			case 25  :// auto Color_mode_Max + 8
				key_mode = 17;
				break;
			case 26:// auto  Color_mode_Max + RTC_mode_Max + 1
				key_mode = 18;
				break;
			default:
				break;
		}

				if( RTC_mode )//ir_long_key_sub_F = 1;
				{
					IR_KEY_L_deal = 0x71;
					short_mode_init_F = 0;
				}
				else if( Color_mode )//ir_long_key_sub_F = 1;
					IR_KEY_L_deal = 0x72;
				if(ir_count == 3) //
				{
					if( RTC_mode )//ir_long_key_sub_F = 1;
					{
						short_mode_init_F = 0;
						IR_KEY_L_deal = 0x73;
					}
					else if( Color_mode )//ir_long_key_sub_F = 1;
						IR_KEY_L_deal = 0x74;
				}
				ir_deal_F = 0;

				if( RTC_mode )//ir_long_key_sub_F = 1;
				{
					IR_KEY_L_deal = 0x41;
					short_mode_init_F = 0;
				}
				else if( Color_mode )//ir_long_key_sub_F = 1;
					IR_KEY_L_deal = 0x42;
				if(ir_count == 3) //
				{
					if( RTC_mode )//ir_long_key_sub_F = 1;
					{
						IR_KEY_L_deal = 0x43;
						short_mode_init_F = 0;
					}
					else if( Color_mode )//ir_long_key_sub_F = 1;
						IR_KEY_L_deal = 0x44;
				}
				ir_deal_F = 0;  
				
#endif