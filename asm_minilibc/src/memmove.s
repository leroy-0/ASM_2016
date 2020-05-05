global memmove

memmove:
	xor 	rcx, rcx
	cmp 	rdi, rsi
	jg 		_inverse

_loop:
	cmp 	rcx, rdx
	je 		_end
	mov 	al, byte [rsi + rcx]
	mov 	byte [rdi + rcx], al
	inc 	rcx
	jmp 	_loop

_inverse:
	dec 	rdx

_inverse_loop:
	cmp 	rdx, -1
	je 		_end
	mov 	al, byte [rsi + rdx]
	mov 	byte [rdi + rdx], al
	dec 	rdx
	jmp 	_inverse_loop

_end:
	mov 	rax, rdi
    ret
