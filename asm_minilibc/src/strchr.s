global strchr

strchr:
	xor		rax, rax

_loop:
	cmp 	byte [rdi], sil
	je 		_found
	cmp 	byte [rdi], 0
	je 		_notfound
	inc 	rdi
	jmp 	_loop

_notfound:
	ret

_found:
	mov 	rax, rdi
	ret