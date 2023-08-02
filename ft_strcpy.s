global _ft_strcpy

_ft_strcpy:
    mov rax, 0                          ;add 0 to the return value (rax)
    jmp loop_condition                  ;go to loop_condition label

loop_condition:
    cmp BYTE[rsi + rax], 0
    je end                              ;if equal to zero go to end
    mov cl, [rsi+rax]                   ;save the second parameter char in cl register
    mov [rdi+rax], cl                   ;replace the char in the first parameter with the second parameter char
    inc rax                             ;rax++
    jmp loop_condition

end:
    mov cl, [rsi+rax]                   ;add \0 at end.
    mov [rdi+rax], cl
    mov rax, rdi                        ;add the result to the return.
    ret