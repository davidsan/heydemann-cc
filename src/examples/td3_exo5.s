	.text
	.ent main
main:	
	lw $6, 0($4) 
	lw $7, -4($4)
	add $6, $6, $7
	sw $6, 0($4)
	addiu $4, $4, 4
	bne $4, $5, loop
	nop
	
	.end main

