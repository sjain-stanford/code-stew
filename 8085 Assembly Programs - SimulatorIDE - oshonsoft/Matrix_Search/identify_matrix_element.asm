; This program searches a 3x3 Matrix (stored in a row-major order)
; for a number (76)H. When it finds it, it stores the row and column
; details in (00A0)H and (00A1)H. If 76 does not exist in the matrix,
; then it stores 0,0 as the row and column.

; Store the 9 elements of the matrix in (0050 - 0055)H
START:	MVI	B,00H	; row
	MVI	C,00H	; column
	LXI	H,0050H
	MVI	E,09H
L2:	MVI	D,03H
	INR	B
L3:	MOV	A,M
	CPI	76H
	JZ	L1	; if Zero is Set, then 76 is present
	INX	H
	DCR	E
	JZ	L4
	DCR	D
	JNZ	L3
	JMP	L2
L1:	MOV	A,B
	STA	00A0H
	MVI	A,03H
	SUB	D
	INR	A
	STA	00A1H
	HLT
L4:	MVI	A,00H
	STA	00A0H
	STA	00A1H
	HLT