global strstr

strstr:
	push rbp
	mov bl, -1
	mov rax, rdi
	mov rbp, rsi

_loop:
	cmp byte [rdi], 0
	je 	_end_first
	cmp byte [rsi], 0
	je 	_end

	mov r12b, byte [rsi]
	cmp byte [rdi], r12b
	je 	_found
	jne _notfound

_end_loop:
	cmp bl, 0
	je 	_inc
	jne _no_inc

_inc:
	inc rsi
	jmp _no_inc

_no_inc:
	inc rdi
	jmp _loop

_null:
	xor		rax, rax
	ret

_end_first:
	pop 	rbp
	cmp 	byte [rsi], 0
	jne 	_null
	ret

_end:
	pop rbp
	ret

_notfound:
	mov rsi, rbp
	mov rax, 0
	mov rbx, -1
	jmp _end_loop

_first_found:
	mov rbx, 0
	mov rax, rdi
	jmp _end_loop

_found:
	cmp bl, -1
	je 	_first_found
	jmp _end_loop