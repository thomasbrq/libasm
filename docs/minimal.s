section .text
    global start    ;symbol start
    global _main    ;symbol main

start:              ;entry point (label)
    call _main
    ret

_main:
    ret