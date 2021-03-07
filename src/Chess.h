#ifndef CHESS_H
#define CHESS_H

//Includes

//Pre-Proccesor Definitions
#define GetColour(x) ((x & 1) != 0)
#define GetPeice(x) ((x & 14) >> 1)
#define IsBlank(x) !(((x & 14) >> 1) != 0)
#define SetPeice(x,y) (Board[y] = x)

enum Pieces
{
    Blank = (char)0x0,    //0000 000 0
    King = (char)0x2,     //0000 001 0
    Rook = (char)0x4,     //0000 010 0
    Bishop = (char)0x6,   //0000 011 0
    Queen = (char)0x8,    //0000 100 0
    Knight = (char)0xA,   //0000 101 0
    Pawn = (char)0xC,     //0000 110 0
};

enum Colors
{
    White = 0x1,    //0000 000 1
    Black = 0x0,     //0000 000 0
};

enum Directions
{
    Up = (-8),
    Down = (+8),
    Left = (-1),
    Right = (+1),
    UpLeft = (-9),
    UpRight = (-7),
    DownLeft = (+7),
    DownRight = (+9),
};



//Vairables
const char* StartingFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
char Board[64];

//Functions
void LoadFEN(char* in); //Loads Forsyth–Edwards Notation

#endif