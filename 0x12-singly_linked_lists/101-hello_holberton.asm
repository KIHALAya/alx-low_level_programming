section .data
    format db 'Hello, Holberton', 0

section .text
    global main
    extern printf

main:
    mov edi, format    ; Load the address of the format string into EDI
    xor eax, eax       ; Clear the EAX register (used for the return value)
    call printf        ; Call the printf function
    mov eax, 0         ; Set the return value of the main function to 0
    ret                ; Return from the main function

