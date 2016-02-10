; Hello bootloader
; Created for education purposes
; Authors: Gynvael Coldwind, jr00u
; Modified by: yisonPylkita

; set 16bit mode
[bits 16]
[org 0x7c00]

start:
    jmp word 0:code

code:
    ; clear screen (config)
    mov ax, 0xb800
    mov es, ax
    xor di, di
    mov ds, di
    mov ax, di

    ; screen size
    mov cx, 80*25
    cld

    ; clear screen
    rep stosw

    ; colored Hello World
    mov di, (80*12 + 40-6) * 2
    mov si, text
    mov cx, text_end - text

; writing loop
write:
    ; place next character in VRAM (GPU screen register)
    movsb

    ; set character color
    mov al, cl
    and al, 8
    
    ; place character attributes (color) in VRAM
    stosb

    ; while cx is not-null
    loop write

    ; end of program -> terminate
    jmp $

; text to display
text:
    db "Hello bootloader"

text_end:
    ; boot sector signature
    times (510 - ($-start)) db 0
    db 0x55, 0xAA

    ; set program size to floppy disk size
    times ((1440*1024) - ($-start)) db 0

