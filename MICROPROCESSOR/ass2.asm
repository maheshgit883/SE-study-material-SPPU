section .data
	msg1 db 10,13,"Enter a string:"
	len1 equ $-msg1

section .bss
	str1 resb 200                 ;string declaration
	result resb 16

section .text

global _start
	_start:

;display
	mov Rax,1
	mov Rdi,1
	mov Rsi,msg1
	mov Rdx,len1
	syscall

;store string 

	mov rax,0
	mov rdi,0
	mov rsi,str1
	mov rdx,200
	syscall

call display

;exit system call
	mov Rax ,60
	mov Rdi,0
	syscall


%macro dispmsg 2
	mov Rax,1
	mov Rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro



display:
	mov rbx,rax                      ; store no in rbx
	mov rdi,result                   ;point rdi to result variable 
	mov cx,16                        ;load count of rotation in cl  

	up1: 
		rol rbx,04               ;rotate no of left by four bits
		mov al,bl	         ; move lower byte in dl		
		and al,0fh               ;get only LSB
		cmp al,09h               ;compare with 39h
		jg add_37                ;if greater than 39h skip add 37    
		add al,30h                
		jmp skip                 ;else add 30     
	add_37: 
		add al,37h                 
	skip: 
		mov [rdi],al             ;store ascii code in result variable
		inc rdi                  ; point to next byte
		dec cx                   ; decrement counter
		jnz up1                  ; if not zero jump to repeat
		dispmsg result,16        ;call to macro
ret






;when you accept string , length automatically returns in Rax register
;input welcome
; rax -> 0000000000000008
;copy rax to rbx
;rbx = 0000000000000008

; when you wnat to display no on screen you have to convert it from  hex  to ascii format
; hex 0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f
; ascii 30,31,32,33,34,35,36,37,38,39,(3a,3b,3c,3d,3e,3f,40), 41,42,43,44,45


;rbx = 0000000000000008
; we have to convert 0 to 30 and 8 to 38 in rbx
; so final rbx register contents must be 
; 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 38


;algorithm to display result
;1. take cnt value as 16 into cnt variable
;2. move address of "result" variable into rdi
;3. rotate left rbx register by 4 bits
;rbx reg=16 digit number you want to display
;4. move b1 into al 
;5. and al with 0fh
;6 compare al with 09h
;7 if greater add 37h into al
;8. else add 30 h into al
;9. move al into memory location pointed by rdi
;10. increment rdi
;11. loop the statement till count value becomes zero
;12. return from procedure







	
