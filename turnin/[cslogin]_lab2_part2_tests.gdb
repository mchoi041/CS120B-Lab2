# Test file for Lab2_introToAVR


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n



# Add tests below
test “PINA: 0x28 PINB: 0x21 PINC: 0x31 PORTD: 0x78”
setPINA 0x28
setPINB 0x21
setPINC 0x31
continue 5
expectPORTD 0x78
checkResult

test “PINA: 0x14 PINB: 0x22 PINC: 0x5A PORTD: 0x91”
setPINA 0x14
setPINB 0x22
setPINC 0x5A
continue 5
expectPORTD 0x91
checkResult

test “PINA: 0x5A PINB: 0x22 PINC: 0x14 PORTD: 0x91”
setPINA 0x5A
setPINB 0x22
setPINC 0x14
continue 5
expectPORTD 0x91
checkResult

test “PINA: 0x22 PINB: 0x42 PINC: 0x34 PORTD: 0x99”
setPINA 0x22
setPINB 0x42
setPINC 0x34
continue 5
expectPORTD 0x99
checkResult

test “PINA: 0x25 PINB: 0x21 PINC: 0x7F PORTD: 0xC7”
setPINA 0x25
setPINB 0x21
setPINC 0x7F
continue 5
expectPORTD 0xC7
checkResult



# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
