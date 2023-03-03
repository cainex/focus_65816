.ORG $C000

; Set up the initial values of the flags and registers
LDX #$00
STX $00

; Execute the BCC instruction
BCC PASS

; If the program reaches here, the BCC instruction failed
LDX #$CC
STX $01
JMP End

PASS:
; If the program reaches here, the BCC instruction succeeded
LDX #$FF
STX $01

End:
JMP End
