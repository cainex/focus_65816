    * = $0000

!al
!rl

.test_adc
        lda #$1010
        adc .data
        sta .out_data

    * = $50
.data
        !16 $0a0b
.out_data
        !16 $1122
