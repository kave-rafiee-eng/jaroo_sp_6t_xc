; ========================================================================================================================
; * Created by: Holtek Touch Key Workshop, Version 3.0.2.6
; MAIN_PROGRAM_V101.inc
; 05:48:27 PM Friday, October 24, 2014
; =========================================================================================================;;***********************************
;;***** MAIN_PROGRAM INCLUDE FILE   *
;;***********************************
;=-------------------------------
;=INCLUDE LIBRARY               -
;=EXTERNAL REFERENCE FILE       -
;=-------------------------------
INCLUDE "..\TKS_GLOBE_VARIES.INC"
INCLUDE "MAIN_PROGRAM_20160302.MCU"

        ;-FUNCTION DEFINE               ;-FUNCTION NAME
INCLUDE "..\BS83B08A_LIBV413\BS83B08A_LIBV413.AEX"
#DEFINE EXTEND_FUNCTION_1A_INITIAL      _BS83B08A_LIBV413_INITIAL
#DEFINE EXTEND_FUNCTION_1A              _BS83B08A_LIBV413

;--
;INCLUDE "..\IIC_SLAVE_TEST_6x370\IIC_SLAVE_TEST_6x370.AEX"
;#DEFINE EXTEND_FUNCTION_1B_INITIAL      _IIC_SLAVE_TEST_6x370_INITIAL
;#DEFINE EXTEND_FUNCTION_1B              _IIC_SLAVE_TEST_6x370

;--
INCLUDE "..\USER_PROGRAM\USER_PROGRAM.AEX"
#DEFINE EXTEND_FUNCTION_1D_INITIAL      _USER_PROGRAM_INITIAL
#DEFINE EXTEND_FUNCTION_1D              _USER_PROGRAM
