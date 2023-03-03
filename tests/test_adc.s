* Test program for ADC instruction

* Set up initial values
LDA #$05          ; load accumulator with value 5
LDX #$03          ; load X register with value 3

* Test ADC with immediate addressing mode
ADC #$02          ; add 2 to accumulator
CMP #$07          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* Test ADC with zero-page addressing mode
STA $00           ; store accumulator in zero-page address 0
ADC $00           ; add value at zero-page address 0 to accumulator
CMP #$0A          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* Test ADC with zero-page,X addressing mode
STX $01           ; store X register in zero-page address 1
ADC $01,X         ; add value at zero-page,X address 1+X to accumulator
CMP #$0D          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* Test ADC with absolute addressing mode
STA $1000         ; store accumulator in absolute address 1000
ADC $1000         ; add value at absolute address 1000 to accumulator
CMP #$10          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* Test ADC with absolute,X addressing mode
STX $1001         ; store X register in absolute address 1001
ADC $1000,X       ; add value at absolute,X address 1000+X to accumulator
CMP #$13          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* Test ADC with absolute,Y addressing mode
STY $1002         ; store Y register in absolute address 1002
ADC $1000,Y       ; add value at absolute,Y address 1000+Y to accumulator
CMP #$16          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* Test ADC with indexed indirect addressing mode
STX $03           ; store X register in zero-page address 3
ADC ($03,X)       ; add value at indexed indirect address 3+X to accumulator
CMP #$19          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* Test ADC with indirect indexed addressing mode
STY $04           ; store Y register in zero-page address 4
ADC ($04),Y       ; add value at indirect indexed address 4+Y to accumulator
CMP #$1C          ; compare result to expected value
BNE FAIL          ; branch to fail label if not equal

* All tests passed
LDX #$FF          ; load X register with value FF
STX $0500         ; store X register in address 0500 to indicate pass

* Test failed
FAIL:
LDX #$CC          ; load X register with value CC
STX $0500         ; store X register in address 0500 to indicate fail
JMP $FFFF         ; infinite loop

