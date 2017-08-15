;*******************************************************
;	File Name	: source.asm	
;	Description	: Electronic Dice
;	Author		: SRJ
;	Target		: Microchip PIC 12F629 Microcontroller
;	Compiler	: Microchip Assembler (MPASM)
;	IDE			: Microchip MPLAB IDE v8.63
;*******************************************************

	list		p=PIC12F629		; selects the device
	#include	<p12F629.inc>	; include header file for the selected PIC
	errorlevel	-302			; no warnings about register not in bank 0
	radix	hex					; hexadecimal

;--------------------
;Configuration Bits 
;--------------------
; internal oscillator selected, watch-dog timer OFF, power-up timer ON, no ext reset, 
; brown-out detect OFF, no program memory code and data memory code protection 

__CONFIG		_INTRC_OSC_NOCLKOUT & _WDT_OFF & _PWRTE_ON & _MCLRE_OFF & _BODEN_OFF & _CP_OFF & _CPD_OFF

;---------------------------------------------------------------------------------------------------------

		org		0x0000
start	movlw	0x00			; disable all interrupts
		movwf	INTCON

		bcf		STATUS,RP0		; select bank 0
		clrf	GPIO			; init. GPIO
		movlw	0x07
		movwf	CMCON			; internal comparator in off mode, thus GP<2:0> are digital IO pins now
	
		bsf		STATUS,RP0		; select bank 1
		movlw	b'00001000'		; GP0,GP1,GP2,GP4 - configure as output 
		movwf	TRISIO			; GP3 - configure as input
		
		bcf		STATUS,RP0		; select bank 0
		
repeat	movlw	0x02		; show dots for number 1
		movwf	GPIO
		call 	delay
		
		movlw	0x10		; show dots for number 2
		movwf	GPIO
		call	delay

		movlw	0x12		; show dots for number 3
		movwf	GPIO
		call	delay

		movlw	0x11		; show dots for number 4
		movwf	GPIO
		call	delay

		movlw	0x13		; show dots for number 5
		movwf	GPIO
		call 	delay

		movlw	0x15		; show dots for number 6
		movwf	GPIO
		call 	delay
		
		goto repeat
		
delay	btfss	GPIO,GP3	; check if input switch is pressed, if yes, then stay within the
		return				; loop, else return
		goto	delay

		end
;******************************************************
	