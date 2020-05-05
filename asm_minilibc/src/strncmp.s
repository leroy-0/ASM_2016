global strncmp


strncmp:
xor rcx, rcx
cmp rcx, rdx
je _stop_0

_loop:
mov al, byte[rdi]
cmp al, 0
je _stop
cmp byte[rsi], 0
je _stop
cmp al, byte[rsi]
jne _stop
inc rcx
cmp rcx, rdx
je _stop
inc rdi
inc rsi
jmp _loop

_stop:
sub al, byte[rsi]
movsx rax, al
ret


_stop_0:
mov rax, 0
ret