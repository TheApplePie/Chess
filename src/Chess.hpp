#ifndef CHESS_H
#define CHESS_H

//Includes


//Pieces
#define Blank       0x0//0000 000 0
#define King        0x2//0000 001 0
#define Rook        0x4//0000 010 0
#define Bishop      0x6//0000 011 0
#define Queen       0x8//0000 100 0
#define Knight      0xA//0000 101 0
#define Pawn        0xC//0000 110 0

//Colours
#define White       0x1//0000 000 1
#define Black       0x0//0000 000 0

//Offsets
#define U           (-8)//Up
#define D           (+8)//Down
#define L           (-1)//Left
#define R           (+1)//Right
#define UL          (-9)//Up-Left
#define UR          (-7)//Up-Right
#define DL          (+7)//Down-Left
#define DR          (+9)//Down-Right

//FEN
#define StartingFEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

//Vairables

char Board[64];

//Functions

#define GetColour(x) ((x & 1) != 0)
#define GetPeice(x) ((x & 14) >> 1)
#define IsBlank(x) !(((x & 14) >> 1) != 0)
#define SetPeice(x,y) (Board[y] = x)

void LoadFEN(char* in); //Loads Forsyth–Edwards Notation

#endif