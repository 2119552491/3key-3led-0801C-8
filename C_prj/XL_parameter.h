
       
typedef struct
{
//	u8 setflag;			//设置过的标志
	u8 led_mode;                        
//	u8 IR_LED_ON_F; 
//	u8 led_level;	
//	u8 led_num;			//灯的模式  
	u8 led_speed;       
	
}g_comval_t;
extern g_comval_t g_comval;
               

extern byte led_level;// led_level_temp   

extern byte led_level_temp;
extern u8 IR_LED_ON_F;
        
extern byte setflag;              
extern void save_comval( );
extern void read_comval( );
