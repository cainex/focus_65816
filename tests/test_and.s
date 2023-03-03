    .org $8000
    .data
test_result: .byte $00
    .text
    .proc main
main:
    lda #$AA          ; load the accumulator with $AA
    and #$F0          ; perform the AND operation with $F0
    cmp #$A0          ; compare the result with $A0
    bne fail          ; if not equal, branch to fail
    lda #$FF          ; load the accumulator with $FF
    sta test_result   ; store the value in test_result
    jmp end           ; jump to end
fail:
    lda #$CC          ; load the accumulator with $CC
    sta test_result   ; store the value in test_result
end:
    rts               ; return from subroutine
    .end
