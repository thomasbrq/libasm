global _ft_strcmp

_ft_strcmp:   
    mov rdx, 0                          ;add 0 to the return value (rdx)
    mov rax, 0

    jmp loop_condition

loop_condition:
    mov ch, BYTE[rdi+rdx]
    mov cl, BYTE[rsi+rdx]

    ; if s1[counter] != s2[counter]
    ; jump to end
    cmp ch, cl
    jne end

    ; if s1[counter] == 0
    ; jump to end
    cmp ch, 0
    je end

    ; increment rdx
    inc rdx

    jmp loop_condition

end:
    movzx rax, BYTE[rdi+rdx]
    movzx rcx, BYTE[rsi+rdx]

    sub rax, rcx

    ret