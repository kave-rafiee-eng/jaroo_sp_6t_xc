#include    "../../20160607_LIBV413/USER_PROGRAM/USER_PROGRAM.H"  
#include "TOUCH.H"
#include "GPIO.H"
#include "../STRUCT.H"
#include "../USER_SETING.H"

extern struct ST_jaroo  jaroo;
extern struct ST_touch  touch;



void touch_led_manage(){
	
	if( DATA_BUF[0]&(0x01<<TOUCH_1) )jaroo.LEVEL=1;
	else if( DATA_BUF[0]&(0x01<<TOUCH_2) )jaroo.LEVEL=2;
	else if( DATA_BUF[0]&(0x01<<TOUCH_3) )jaroo.LEVEL=3;
	else if( DATA_BUF[0]&(0x01<<TOUCH_4) )jaroo.LEVEL=4;
	else if( DATA_BUF[0]&(0x01<<TOUCH_5) )jaroo.LEVEL=5;
	
	

	
	if( jaroo.OFF == 1 ){
		led1=0; led2=0; led3=0; led4=0; led5=0; led_on=1;
		if( jaroo.LEVEL == 1 ){ led1=1; jaroo.POWER=POWER_LEVEL1; }
		if( jaroo.LEVEL == 2 ){ led2=1; jaroo.POWER=POWER_LEVEL2; }
		if( jaroo.LEVEL == 3 ){ led3=1; jaroo.POWER=POWER_LEVEL3; }
		if( jaroo.LEVEL == 4 ){ led4=1; jaroo.POWER=POWER_LEVEL4; }
		if( jaroo.LEVEL == 5 ){ led5=1; jaroo.POWER=POWER_LEVEL5; }	
		
	}
	
	
		
	
}