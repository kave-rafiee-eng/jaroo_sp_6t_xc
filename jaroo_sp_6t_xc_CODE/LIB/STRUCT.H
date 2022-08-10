#ifndef _STRUCT_H
#define _STRUCT_H

	struct ST_jaroo
	{
		volatile unsigned char LEVEL : 4; 
		volatile unsigned char SOFT : 7; 
		volatile unsigned char POWER : 7; 
		volatile unsigned char SOFT_SLOW ;
		volatile unsigned char OFF : 1;		
			
	};

	struct ST_touch
	{
		 
		unsigned char EDGE_ON : 1;
				
	};


	struct ST_pwm
	{
		volatile unsigned char timer  ; 
		volatile unsigned char comp  ; 
				
		volatile unsigned char PULSE_MODE : 1 ; 

	
	};

	
#endif
