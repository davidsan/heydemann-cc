	.text
	.ent main
main:	
	lw $4, 0($5) 
	add $6, $4, $3 
	lw $7, 0($6) 
	sw $7, 0($5) 
	addiu $5, $5, 4
	bne $5, $10, main 
	nop
	
	.end main

