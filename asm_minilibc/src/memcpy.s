global memcpy

memcpy:

	xor rcx, rcx
	mov r9, rdx
	call _loop


_loop:
	cmp rcx, rdx
	je _end
	mov r9b, [rsi + rcx]
	mov [rdi + rcx], r9b
	inc rcx
	call _loop


_end:
        ret