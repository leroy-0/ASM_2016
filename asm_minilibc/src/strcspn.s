global	strcspn

strcspn:
	mov rdx, rdi
	mov rcx, rsi

_loop:
	mov al, byte [rcx]
	cmp byte [rdx], al
	je _stop
	cmp al, 0
	je 	_arg2_end
	jne _arg2_loop

_arg2_end:
	mov rcx, rsi
	inc rdx
	jmp _loop

_arg2_loop:
	inc rcx
	jmp	_loop

_stop:
	sub rdx, rdi
	mov rax, rdx
	ret