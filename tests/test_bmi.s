.data
    testVal1: .byte $00
    testVal2: .byte $80
    testVal3: .byte $81
    testVal4: .byte $7F
    memVal: .byte $00

.text
    .org $8000

    lda #$00
    sta testVal1
    lda #$80
    sta testVal2
    lda #$81
    sta testVal3
    lda #$7F
    sta testVal4
    lda #$00
    sta memVal

; Immediate addressing mode
    lda #$80
    bmi .negative
    lda #$01
    sta memVal
    jmp .end

.negative
    lda #$00
    sta memVal

.end

; Zero Page addressing mode
    lda testVal1
    bmi .negative2
    lda #$01
    sta memVal
    jmp .end2

.negative2
    lda #$00
    sta memVal

.end2

; Zero Page,X addressing mode
    ldx #$01
    lda testVal1,x
    bmi .negative3
    lda #$01
    sta memVal
    jmp .end3

.negative3
    lda #$00
    sta memVal

.end3

; Absolute addressing mode
    lda testVal2
    bmi .negative4
    lda #$01
    sta memVal
    jmp .end4

.negative4
    lda #$00
    sta memVal

.end4

; Absolute,X addressing mode
    ldx #$01
    lda testVal2,x
    bmi .negative5
    lda #$01
    sta memVal
    jmp .end5

.negative5
    lda #$00
    sta memVal

.end5

; Absolute,Y addressing mode
    ldy #$01
    lda testVal2,y
    bmi .negative6
    lda #$01
    sta memVal
    jmp .end6

.negative6
    lda #$00
    sta memVal

.end6

; Indirect,X addressing mode
    ldx #$01
    lda (testVal3,x)
    bmi .negative7
    lda #$01
    sta memVal
    jmp .end7

.negative7
    lda #$00
    sta memVal

.end7

; Indirect,Y addressing mode
    ldy #$01
    lda (testVal3),y
    bmi .negative8
    lda #$01
    sta memVal
    jmp .end8

.negative8
    lda #$00
    sta memVal

.end8

; now we check if the test pass or fail
    lda memVal
    cmp #$01
    bne .fail
    lda #$ff
    sta memVal
    jmp .done
