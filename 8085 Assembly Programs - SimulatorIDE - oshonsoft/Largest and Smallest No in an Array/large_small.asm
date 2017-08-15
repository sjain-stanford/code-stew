	.ORG	0000H
	LXI	H,0050H
	MOV	C,M	; C - no. of elements in the array
	INX	H
	MOV	D,M	; D - MAX no.
	MOV	E,M	; E - MIN no.
	INX	H
	DCR	C

; Segment to get Largest of the numbers
LOOP:	MOV	A,D
	CMP	M
	JNC	L1
	MOV	D,M

; Segment to get Smallest of the numbers
L1:	MOV	A,E
	CMP	M
	JC	L2
	MOV	E,M

; Next Iteration
L2:	INX	H
	DCR	C
	JNZ	LOOP

; Store Largest and Smallest of numbers to memory
	MOV	A,D
	STA	00A0H
	MOV	A,E
	STA	00A1H
	HLT
