/********************************************************************
 FileName:     	HardwareProfile - PIC24FJ64GB004 PIM.h
 Dependencies:  See INCLUDES section
 Processor:     PIC24FJ64GB004
 Hardware:      PIC24FJ64GB004 PIM
 Compiler:      Microchip C30
 Company:       Microchip Technology, Inc.

 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the �Company�) for its PIC� Microcontroller is intended and
 supplied to you, the Company�s customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************
 File Description:

 Change History:
  Rev   Date         Description
  1.0   11/19/2004   Initial release
  2.1   02/26/2007   Updated for simplicity and to use common
                     coding style
  2.3   09/15/2008   Broke out each hardware platform into its own
                     "HardwareProfile - xxx.h" file
  2.4b  04/08/2009   Initial support for PIC24FJ64GB004 family
********************************************************************/

#ifndef HARDWARE_PROFILE_PIC24FJ64GB004_PIM_H
#define HARDWARE_PROFILE_PIC24FJ64GB004_PIM_H
/************  PHDC Demo Configuration *******************/ 
    #define PHD_USE_POT_FOR_TEMP_SIMULATION
    #define PHD_USE_LCD_DISPLAY
    #define PHD_USE_RTCC_FOR_TIME_STAMP
    //#define DEMO_BOARD_HAS_ONLY_ONE_PUSH_BUTTON

    /*******************************************************************/
    /******** USB stack hardware selection options *********************/
    /*******************************************************************/
    //This section is the set of definitions required by the MCHPFSUSB
    //  framework.  These definitions tell the firmware what mode it is
    //  running in, and where it can find the results to some information
    //  that the stack needs.
    //These definitions are required by every application developed with
    //  this revision of the MCHPFSUSB framework.  Please review each
    //  option carefully and determine which options are desired/required
    //  for your application.

    //#define USE_SELF_POWER_SENSE_IO
    #define tris_self_power     TRISAbits.TRISA2    // Input
    #define self_power          1

    #define USE_USB_BUS_SENSE_IO
    #define tris_usb_bus_sense  TRISBbits.TRISB5    // Input
    #define USB_BUS_SENSE       U1OTGSTATbits.SESVD 
   
    //Uncomment this to make the output HEX of this project 
    //   to be able to be bootloaded using the HID bootloader
    #define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER	

    //If the application is going to be used with the HID bootloader
    //  then this will provide a function for the application to 
    //  enter the bootloader from the application (optional)
    #if defined(PROGRAMMABLE_WITH_USB_HID_BOOTLOADER)
        #define EnterBootloader() __asm__("goto 0x400")
    #endif   

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    /** Board definition ***********************************************/
    //These defintions will tell the main() function which board is
    //  currently selected.  This will allow the application to add
    //  the correct configuration bits as wells use the correct
    //  initialization functions for the board.  These defitions are only
    //  required in the stack provided demos.  They are not required in
    //  final application design.
    #define DEMO_BOARD PIC24FJ64GB004_PIM
    #define EXPLORER_16
    #define PIC24FJ64GB004_PIM
    #define CLOCK_FREQ 32000000
	#define EXPLORER_16
	#define GetSystemClock()		(CLOCK_FREQ)			// Hz
    #define GetInstructionClock()	(GetSystemClock()/1)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
    
    /** LED ************************************************************/
    #define mInitAllLEDs()      LATA &= 0xFD7F; TRISA &= 0xFD7F; LATB &= 0xFFF3; TRISB &= 0xFFF3;
    
    #define mLED_1              LATAbits.LATA7
    #define mLED_2              LATBbits.LATB3
    #define mLED_3              LATBbits.LATB2
    #define mLED_4              LATAbits.LATA9

    #define mGetLED_1()         mLED_1
    #define mGetLED_2()         mLED_2
    #define mGetLED_3()         mLED_3
    #define mGetLED_4()         mLED_4     
    
    #define mLED_1_On()         mLED_1 = 1;
    #define mLED_2_On()         mLED_2 = 1;
    #define mLED_3_On()         mLED_3 = 1;
    #define mLED_4_On()         mLED_4 = 1;
    
    #define mLED_1_Off()        mLED_1 = 0;
    #define mLED_2_Off()        mLED_2 = 0;
    #define mLED_3_Off()        mLED_3 = 0;
    #define mLED_4_Off()        mLED_4 = 0;
    
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;
    #define mLED_2_Toggle()     mLED_2 = !mLED_2;
    #define mLED_3_Toggle()     mLED_3 = !mLED_3;
    #define mLED_4_Toggle()     mLED_4 = !mLED_4;
    
    /** SWITCH *********************************************************/
    #define mInitSwitch2()      TRISAbits.TRISA10=1;
    #define mInitSwitch3()      TRISAbits.TRISA9=1;
    #define mInitAllSwitches()  mInitSwitch2();mInitSwitch3();
    #define sw2                 PORTAbits.RA10
    #define sw3                 PORTAbits.RA9
    
    /** POT ************************************************************/
    #define mInitPOT()  {AD1PCFGLbits.PCFG7 = 0;    AD1CON2bits.VCFG = 0x0;    AD1CON3bits.ADCS = 0xFF;    AD1CON1bits.SSRC = 0x0;    AD1CON3bits.SAMC = 0b10000;    AD1CON1bits.FORM = 0b00;    AD1CON2bits.SMPI = 0x0;    AD1CON1bits.ADON = 1;}
    
    /** I/O pin definitions ********************************************/
    #define INPUT_PIN 1
    #define OUTPUT_PIN 0
    
    /*  LCD Module I/O pins *******************************************/ 
	#define LCD_DATA0_TRIS		(TRISBbits.TRISB0)		
	#define LCD_DATA0_IO		(LATBbits.LATB0)
	#define LCD_DATA1_TRIS		(TRISBbits.TRISB1)
	#define LCD_DATA1_IO		(LATBbits.LATB1)
	#define LCD_DATA2_TRIS		(TRISBbits.TRISB2)
	#define LCD_DATA2_IO		(LATBbits.LATB2)
	#define LCD_DATA3_TRIS		(TRISBbits.TRISB9)		
	#define LCD_DATA3_IO		(LATBbits.LATB9)
	#define LCD_DATA4_TRIS		(TRISBbits.TRISB8)		
	#define LCD_DATA4_IO		(LATBbits.LATB8)
	#define LCD_DATA5_TRIS		(TRISBbits.TRISB7)
	#define LCD_DATA5_IO		(LATBbits.LATB7)
	#define LCD_DATA6_TRIS		(TRISAbits.TRISA1)
	#define LCD_DATA6_IO		(LATAbits.LATA1)
	#define LCD_DATA7_TRIS		(TRISAbits.TRISA0)
	#define LCD_DATA7_IO		(LATAbits.LATA0)
	#define LCD_RD_WR_TRIS		(TRISBbits.TRISB13)
	#define LCD_RD_WR_IO		(LATBbits.LATB13)
	#define LCD_RS_TRIS			(TRISCbits.TRISC7)
	#define LCD_RS_IO			(LATCbits.LATC7)
	#define LCD_E_TRIS			(TRISBbits.TRISB3)
	#define LCD_E_IO			(LATBbits.LATB3)

#endif  //HARDWARE_PROFILE_PIC24FJ64GB004_PIM_H
