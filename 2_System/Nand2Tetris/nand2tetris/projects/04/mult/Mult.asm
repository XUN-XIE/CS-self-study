// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

    @0
    D=M
    @i
    M=D
    @result
    M=0
    @STORE
    D;JLE
(LOOP)
    @1
    D=M
    @result
    M=M+D
    @i
    M=M-1
    D=M
    @LOOP
    D;JGT
(STORE)
    @result
    D=M
    @2
    M=D
(END)
    @END
    0;JMP
