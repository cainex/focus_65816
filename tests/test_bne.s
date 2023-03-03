    .org $8000

Start:
    LDA #$01    ; load register A with value 1
    CMP #$02    ; compare A with value 2
    BNE Success ; Branch to Success if A is not equal to 2
    LDA #$CC    ; load register A with value CC (fail)
    JMP End     ; jump to end of program

    LDA #$01
    CMP #$01
    BNE Fail    ; Branch to fail - A is equal to 1

Success:
    LDA #$FF    ; load register A with value FF (pass)
    JMP End
Fail:
    LDA #$CC
End:
    STA $FF00   ; store A to address FF00
    BRK         ; end program
