/**
   CWG1 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     cwg1.c
 
   @Summary
     This is the generated driver implementation file for the CWG1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CWG1.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
         Device            :  PIC18F57Q43
         Driver Version    :  2.11
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.10 and above or later
         MPLAB             :  MPLAB X 5.30
 */ 

 /*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
 
 /**
   Section: Included Files
 */

#include <xc.h>
#include "cwg1.h"

/**
  Section: CWG1 APIs
*/

void CWG1_Initialize(void)
{
    // Set the CWG1 to the options selected in PIC10 / PIC12 / PIC16 / PIC18 MCUs

	// CWG1POLA non inverted; CWG1POLC non inverted; CWG1POLB non inverted; CWG1POLD non inverted; 
	CWG1CON1 = 0x00;

	// CWG1DBR 0; 
	CWG1DBR = 0x00;

	// CWG1DBF 0; 
	CWG1DBF = 0x00;

	// SHUTDOWN No Auto-shutdown; REN enabled; CWG1LSDB tri-stated; CWG1LSAC tri-stated; 
	CWG1AS0 = 0x54;

	// AS1E disabled; AS0E disabled; AS3E disabled; AS2E disabled; AS5E disabled; AS4E disabled; AS7E disabled; AS6E enabled; 
	CWG1AS1 = 0x40;

	// CWG1CS FOSC; 
	CWG1CLKCON = 0x00;

	// CWG1STRD disabled; CWG1STRB disabled; CWG1STRC disabled; CWG1STRA enabled; CWG1OVRD low; CWG1OVRA low; CWG1OVRB low; CWG1OVRC low; 
	CWG1STR = 0x01;

	// CWG1ISM NCO1OUT; 
	CWG1ISM = 0x0C;

	// CWG1LD Buffer_not_loaded; CWG1EN enabled; CWG1MODE Steering mode; 
	CWG1CON0 = 0x80;

}


void CWG1_AutoShutdownEventSet()
{
    CWG1AS0bits.SHUTDOWN = 1;
}

void CWG1_AutoShutdownEventClear()
{
    CWG1AS0bits.SHUTDOWN = 0;
}


/**
 End of File
*/