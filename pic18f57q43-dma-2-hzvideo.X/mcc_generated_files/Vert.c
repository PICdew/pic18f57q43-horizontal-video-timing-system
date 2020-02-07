void PWM1_16BIT_Initialize(void) Vertical Pulse
{
    //PWMERS External Reset Disabled;
    PWM1ERS = 0x00;

    //PWMCLK NCO1OUT;
    PWM1CLK = 0x0A;

    //PWMLDS Autoload disabled;
    PWM1LDS = 0x00;

    //PWMPRL 112; 
    PWM1PRL = 0x70;

    //PWMPRH 0;
    PWM1PRH = 0x00;

    //PWMCPRE No prescale;
    PWM1CPRE = 0x00;

    //PWMPIPOS No postscale;
    PWM1PIPOS = 0x00;

    //PWMS1P2IF PWM2 output match did not occur; PWMS1P1IF PWM1 output match did not occur;
    PWM1GIR = 0x00;

    //PWMS1P2IE disabled; PWMS1P1IE disabled;
    PWM1GIE = 0x00;

    //PWMPOL2 disabled; PWMPOL1 disabled; PWMPPEN disabled; PWMMODE Left aligned mode;
    PWM1S1CFG = 0x00;

    //PWMS1P1L 97; 
    PWM1S1P1L = 0x61;

    //PWMS1P1H 0;
    PWM1S1P1H = 0x00;

    //PWMS1P2L 97; 
    PWM1S1P2L = 0x61;

    //PWMS1P2H 0;
    PWM1S1P2H = 0x00;

    //Clear PWM1_16BIT period interrupt flag
    PIR4bits.PWM1PIF = 0;

    //Clear PWM1_16BIT interrupt flag
    PIR4bits.PWM1IF = 0;

    //Clear PWM1_16BIT slice 1, output 1 interrupt flag
    PWM1GIRbits.S1P1IF = 0;

    //Clear PWM1_16BIT slice 1, output 2 interrupt flag
    PWM1GIRbits.S1P2IF = 0;

    //PWM1_16BIT interrupt enable bit
    PIE4bits.PWM1IE = 0;

    //PWM1_16BIT period interrupt enable bit
    PIE4bits.PWM1PIE = 0;

    //Set default interrupt handlers
    PWM1_16BIT_Slice1Output1_SetInterruptHandler(PWM1_16BIT_Slice1Output1_DefaultInterruptHandler);
    PWM1_16BIT_Slice1Output2_SetInterruptHandler(PWM1_16BIT_Slice1Output2_DefaultInterruptHandler);
    PWM1_16BIT_Period_SetInterruptHandler(PWM1_16BIT_Period_DefaultInterruptHandler);

    //PWMEN enabled; PWMLD disabled; PWMERSPOL disabled; PWMERSNOW disabled;
    PWM1CON = 0x00;
}