section .data
	out1 db "enter a string ",0
	f1 db "%s",0
	out2 db "enter a number ",0
	f2 db "%d",0
	space db " ",0
	newline db " ",10,0

section .bss
	a resb 16
	b resb 4
section .text
	global main
    	extern printf
    	extern scanf
main :
    	push rbp
	mov rbp , rsp
	
	lea rdi , [out1]   
	call printf
	
	
	lea rdi , [f1]
	lea rsi , [a]
	call scanf
	
	lea rdi , [out2]   
	call printf
	
	
	lea rdi , [f2]
	lea rsi , [b]
	call scanf
	
	
	lea rdi , [f1]
	lea rsi , [a]
	call printf
	
	
	lea rdi, [f1]
	lea rsi, [space]
	call printf
	
	lea rdi , [f2]
	mov rsi , [b]
	call printf
	
	lea rdi, [f1]
	lea rsi, [newline]
	call printf
		
	leave
	ret
	


