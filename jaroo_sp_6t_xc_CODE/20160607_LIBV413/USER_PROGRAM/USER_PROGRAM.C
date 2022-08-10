
#include "USER_PROGRAM.H"  
#include "../../LIB/BS83B08A/TIMER.H"    
#include "../../LIB/BS83B08A/EX_INT.H"         
#include "../../LIB/STRUCT.H"
#include "../../LIB/FUN/GPIO.H"
#include "../../LIB/FUN/TOUCH.H"
#include "../../LIB/USER_SETING.H"

struct ST_jaroo  jaroo;
struct ST_touch  touch;
struct ST_pwm pwm;

unsigned char i=0;


#define vector_multy_fun0_interupt 0x0C
#define vector_ex_interupt 0x04


#define timer_100us_reload 249  
#define timer_number_load_for_10ms 100



void ini_main();
void pwm_generator();


volatile char timer_load=0;
void __attribute((interrupt(vector_multy_fun0_interupt)))  timer()
{ 
	
	_ton=0;	
	
	if( jaroo.OFF == 0 ){
		
		pwm.timer++;
			
		if ( pwm.timer < pwm.comp ){
			
			if( jaroo.LEVEL == 1 )led1 = 1;
			else if( jaroo.LEVEL == 2 )led2 = 1;
			else if( jaroo.LEVEL == 3 )led3 = 1;
			else if( jaroo.LEVEL == 4 )led4 = 1;
			else if( jaroo.LEVEL == 5 )led5 = 1;
			led_on=1;
							
		}
		else { 
			
			led1=0;
			led2=0;
			led3=0;
			led4=0;
			led5=0;
			
			led_on=0;
			
		}
					
		if (pwm.timer >= 100 ){ pwm.timer = 0;
			
			 if( pwm.PULSE_MODE ){ pwm.comp++;
			 	if( pwm.comp >= 100 )pwm.PULSE_MODE=0;	
			 }
			 else{
			 	pwm.comp--;
			 	if( pwm.comp == 0 )pwm.PULSE_MODE=1;
			 	
			 }
			 
	 	  	  
		}

		_ts=0;
		_tpsc0=0;_tpsc1=1;_tpsc2=0;	
		_ton=1;		
		
	}
	else{
		
		
			_tpsc0=1;_tpsc1=1;_tpsc2=1;	
			_tmr = timer_100us_reload;
			_ton=1;			
							
			if( jaroo.SOFT_SLOW == SOFT_START_TIME ){ jaroo.SOFT_SLOW=0;
				if( jaroo.SOFT < (100-jaroo.POWER) )jaroo.SOFT++;
				else if( jaroo.SOFT > (100-jaroo.POWER) )jaroo.SOFT--; 
			}
			else jaroo.SOFT_SLOW++;
		
			timer_load++;
			
			if( timer_load < jaroo.SOFT ){
				drive=0;
			}
			else if( timer_load == jaroo.SOFT ) drive=1;
			else { drive=0;
			
				timer_load=0;
				_ton=0;	
			}
				
		
	}

	
}

void __attribute((interrupt(vector_ex_interupt)))  ex_interupt()
{ 

	if( jaroo.OFF == 1 ){
		
		_tpsc0=1;_tpsc1=1;_tpsc2=1;
		_tmr = timer_100us_reload;
		_ton=1;
	}
		
}




void USER_PROGRAM_INITIAL()
{
	ini_main();	
}



void USER_PROGRAM()
{
										
	GET_KEY_BITMAP();
	touch_led_manage();
	_clrwdt();
	
	if( DATA_BUF[0]&(0x01<<TOUCH_ON) ){ 
		
		if( touch.EDGE_ON == 0 ){touch.EDGE_ON=1;
			
			jaroo.OFF=1 - jaroo.OFF;
			if( jaroo.OFF == 1 ){ jaroo.SOFT = 90; }
			else{
				
				_tmr = 0;
				_ton=1;
					
			}	
				
		}
	}
	else{ touch.EDGE_ON=0;
		
		
	}
	
	if( DATA_BUF[0] > 0 )pwm.comp=90;
		
}



void ini_main(){

	clock_ini();
	
	jaroo.LEVEL = START_LEVEL;

	pwm.PULSE_MODE=1;
	pwm.comp=0;
	pwm.timer=0;
	
	touch.EDGE_ON=0;
	
	jaroo.LEVEL=3;
	jaroo.OFF=0;
	jaroo.POWER=POWER_LEVEL3;
	jaroo.SOFT_SLOW=0;
	jaroo.SOFT=90;
		
	GPIO_ini();
	
	EX_INT_init();
	
	timer_interupt_enable();
	_emi=1;
		
	_ts=0;
	_tpsc0=0;_tpsc1=1;_tpsc2=0;	
	
	_tmr=0;
	_ton=1;
	
	
}



