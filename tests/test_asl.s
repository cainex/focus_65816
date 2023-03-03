.origin $8000

.data
    PASS .byte $FF
    FAIL .byte $CC

.text

main:
    ; Test ASL with immediate addressing mode
    lda #$01
    asl
    cmp #$02
    bne fail_immediate

    ; Test ASL with zero page addressing mode
    ldx #$02
    lda $03
    asl $03
    cmp $03
    bne fail_zero_page

    ; Test ASL with absolute addressing mode
    ldx #$04
    lda $05
    asl $05
    cmp $05
    bne fail_absolute

    ; Test ASL with accumulator addressing mode
    lda #$08
    asl
    cmp #$10
    bne fail_accumulator

    jmp pass

fail_immediate:
    jmp fail

fail_zero_page:
    jmp fail

fail_absolute:
    jmp fail

fail_accumulator:
    jmp fail

fail:
    lda #FAIL
    sta $0600
    jmp end

pass:
    lda #PASS
    sta $0600

end:
    brk
