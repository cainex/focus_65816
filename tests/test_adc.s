.P816
.ORG $0000
.CODE
test_adc:
    lda #$0010
    adc data
    sta out_data
.ORG $2000
.DATA
data:
    .DWORD $0a0b0c0d
out_data:
    .DWORD $11223344
