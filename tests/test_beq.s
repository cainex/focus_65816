    .org $C000

    ; Set up test values
    LDA #$05          ; A = 5
    STA $00           ; Memory[$00] = 5

    LDA #$05          ; A = 5
    CMP #$05          ; Compare A with 5

    BEQ pass         ; If A == 5, branch to pass
    JMP fail         ; Else, branch to fail

    ; Pass case
pass:
    LDA #$FF          ; A = FF
    STA $01           ; Memory[$01] = FF
    JMP end           ; Branch to end

    ; Fail case
fail:
    LDA #$CC          ; A = CC
    STA $01           ; Memory[$01] = CC

    ; End of program
end:
    BRK               ; End program execution

