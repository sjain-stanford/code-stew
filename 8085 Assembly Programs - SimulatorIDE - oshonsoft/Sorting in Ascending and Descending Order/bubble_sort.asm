; Sorting in Ascending and Descending Order by Bubble Sort
; Outer Loop: ( N-1 ) times
; Inner Loop: ( N-Outer Loop ) times each
	.ORG	0000H
START:	LXI	H,0050H
	MOV	C,M	; Outer Loop
	DCR	C
REPEAT:	MOV	D,C	; Inner Loop
	LXI	H,0051H
LOOP:	MOV	A,M
	INX	H
	CMP	M
	JC	NEXT
	MOV	B,M
	MOV	M,A
	DCX	H
	MOV	M,B
	INX	H
NEXT:	DCR	D
	JNZ	LOOP
	DCR	C
	JNZ	REPEAT

; Reversing the sorted array to get Descending Order
	LXI	B,0050H
	LDAX	B
	MOV	L,A
L1:	INX	B
	DCR	A
	JNZ	L1
	LXI	D,0061H
L2:	LDAX	B
	STAX	D
	DCX	B
	INX	D
	DCR	L
	JNZ	L2
	HLT

