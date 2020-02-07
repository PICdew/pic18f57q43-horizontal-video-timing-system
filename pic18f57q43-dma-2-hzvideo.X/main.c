/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC18F57Q43
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
/*
                      PWM reprogramming table
                      {PWM1P1L, PWM1P1H, PWM1P2L, PWM1P2H, PWM1PRL, PWM1PRH,
                       PWM2P1L, PWM2P1H, PWM2P2L, PWM2P2H, PWM2PRL, PWM2PRH}
*/
uint8_t Vert[] =      {0x71, 0x00, 0x71, 0x00, 0x70, 0x00,
                       0x61, 0x00, 0x61, 0x00, 0x70, 0x00};

uint8_t Horz[] =      {0x12, 0x00, 0x18, 0x00, 0xE1, 0x00,
					   0x26, 0x00, 0xCF, 0x00, 0xE1, 0x00};

void	DMA_Setup(void);
/*
                         Main application
*/
void main(void)
{
    SYSTEM_Initialize();
	DMA_Setup();
    PWMEN = 0x0F;

    while (1)
    {
        // Add your application code
    }
}

/*
                         DMA Config
*/
void	DMA_Setup(void)
{
    DMASELECT = 0;              //select DMA1
    DMAnSSA   = &Vert[0];       //set source start address to Vertical pulse constants
    DMAnDSA   = 0x4020;         //set destination start address to start of PWM registers
    DMAnCON1  = 0x42;           //set control register1
    DMAnSSZ   = 12;             //set source size
    DMAnDSZ   = 12;             //set destination size
    DMAnSIRQ  = 0x01;           //set DMA Transfer Trigger Source (start of vertical)
    DMAnAIRQ  = 0x01;           //set DMA Transfer abort Source
    DMAnCON0  = 0xC0;           //set control register0

    DMASELECT = 1;              //select DMA2
    DMAnSSA   = &Horz[0];  		//set source start address to Horizonal pulse constants
    DMAnDSA   = 0x4020;         //set destination start address to start of PWM registers
    DMAnCON1  = 0x42;           //set control register1
    DMAnSSZ   = 12;             //set source size
    DMAnDSZ   = 12;             //set destination size
    DMAnSIRQ  = 0x01;           //set DMA Transfer Trigger Source (start of Horizontal)
    DMAnAIRQ  = 0x01;           //set DMA Transfer abort Source
    DMAnCON0  = 0xC0;           //set control register0

	asm ("BANKSEL PRLOCK");     //unlock arbiter to set dma priority
    asm ("MOVLW 0x55");
    asm ("MOVWF PRLOCK");
    asm ("MOVLW 0xAA");
    asm ("MOVWF PRLOCK");
    asm ("BSF PRLOCK, 0");
	DMA1PR	=	0;			    //set DMA1 to highest priority
	DMA2PR  =   1;			    //set DMA2 to next highest priority
}

/**
 End of File
*/