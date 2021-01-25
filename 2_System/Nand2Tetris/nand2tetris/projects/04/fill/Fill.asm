// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// RAM[16384]-RAM[24575]
// black 1
// white 0
@16384
D=A
@left
M=D
@24575
D=A
@right
M=D

// infinite loop
(INFINITE_LOPP)
    // keyboard RAM[24576]
    @24576
    D=M
    @WHITE
    D;JEQ
    @BLACK
    D;JGT

    (WHITE)
    @FILL_WHITE
    0;JMP

    (BLACK)
    @FILL_BLACK
    0;JMP


(END)
@INFINITE_LOPP
0;JMP


// white loop
(FILL_WHITE)
@left
D=M
@index
M=D
@8191
D=A
@diff
M=D
(FILL_WHITE_LOOP)
    @index
    D=M
    A=D
    M=0
    @index
    M=M+1
    @diff
    M=M-1
    D=M
    @FILL_WHITE_LOOP
    D;JGE

@END
0;JMP


// black loop
(FILL_BLACK)
@left
D=M
@index
M=D
@8191
D=A
@diff
M=D
(FILL_BLACK_LOOP)
    @index
    D=M
    A=D
    M=-1
    @index
    M=M+1
    @diff
    M=M-1
    D=M
    @FILL_BLACK_LOOP
    D;JGE

@END
0;JMP


