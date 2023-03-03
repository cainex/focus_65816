; Test program for 6502 BIT instruction
; Writes FF to memory address 0x1000 if the instruction passes
; Writes CC to memory address 0x1000 if the instruction fails

.org $8000

; Define the memory address to check for pass/fail
.define PASS_FAIL_ADDR $1000

; Define the values to use for the test
.define TEST_VALUE_A $01
.define TEST_VALUE_B $02
.define TEST_VALUE_C $03

; Test BIT immediate addressing mode
ldx #TEST_VALUE_A
ldy #TEST_VALUE_B
bit #TEST_VALUE_C
bne fail
jmp pass

; Test BIT zero page addressing mode
ldx #TEST_VALUE_A
ldy #TEST_VALUE_B
sta $00
ldx #TEST_VALUE_C
bit $00
bne fail
jmp pass

; Test BIT absolute addressing mode
ldx #TEST_VALUE_A
ldy #TEST_VALUE_B
sta $0100
ldx #TEST_VALUE_C
bit $0100
bne fail
jmp pass

; Pass label
pass:
    lda #$FF
    sta PASS_FAIL_ADDR
    jmp end

; Fail label
fail:
    lda #$CC
    sta PASS_FAIL_ADDR

; End label
end:
    brk

