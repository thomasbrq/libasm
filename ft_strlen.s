global _ft_strlen

_ft_strlen:   
    mov rax, 0                          ;add 0 to the return value (rax)
    jmp loop_condition                  ;go to loop_condition

loop_start:
    inc rax                             ;rax++
    jmp loop_condition

loop_condition:
    cmp BYTE[rdi + rax], 0          ; str[i]
    jnz loop_start                  ; jump to loop_start if str[i] != 0
    ret
