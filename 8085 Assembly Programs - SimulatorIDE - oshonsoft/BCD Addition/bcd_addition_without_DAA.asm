; nibble addition : max when 9+9 = 12h
; D --> final carry of BCD sum
; E --> set to 1 when addition of lower nibble is greater than 9 (i.e. A to F and even if carried over, e.g. 10 to 12 --> max is 9+9 = 12))
; B --> sum of two numbers (normal hex form)
; If CY = 1 && E = 1, then add 66h to B to get BCD result
; If CY = 1 && E = 0, then add 60h to B
; If CY = 0, and
;		i)if lower Nibble > 9, add 06h to B, then
;		ii)if higher Nibble > 9, add 60h to B

	.ORG	0000H

; To check for CY and E
	MVI	D,00H
	MVI	E,00H
	LXI	H,00A0H
	MOV	A,M
	ANI	0FH
	MOV	C,A
	INX	H
	MOV	A,M
	ANI	0FH
	ADD	C
	CPI	0AH	; If Acc >= 0AH, carry is reset
	JC	L1
	INR	E
L1:	MOV	A,M
	DCX	H
	ADD	M
	MOV	B,A
	JNC	L2	; CY = 0 cases are handled after L2

; CY = 1 cases are handled below
	INR	D
	MOV	A,E
	DCR	A
	JNZ	L4
; if after decrementing, A == 0, then it means that initially E = 1
; if after decrementing, A != 0, then initially, E = 0
	MOV	A,B
	ADI	66H	; case: CY = 1 && E = 1
	MOV	B,A
	JMP	L3
L4:	MOV	A,B
	ADI	060H	; case: CY = 1 && E = 0
	MOV	B,A
	JMP	L3

; case: CY = 0
L2:	MOV	A,E
	DCR	A
	JNZ	L5	; case: (lower nibble of B) < 9
	MOV	A,B
	ADI	06H	; case: (lower nibble of B) > 9
	JNC	NC1
	INR	D
NC1:	MOV	B,A
L5:	MOV	A,B
	ANI	0F0H
	CPI	0A0H
	JC	L3	; case: (higher nibble of B) < 9
	MOV	A,B
	ADI	060H	; case: (higher nibble of B) > 9
	JNC	NC2
	INR	D
NC2:	MOV	B,A
L3:	INX	H
	INX	H
	MOV	M,B	; store bcd sum
	INX	H
	MOV	M,D	; store carry
	HLT

