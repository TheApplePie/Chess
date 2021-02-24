#include "Chess.hpp"
#include <stdio.h>

int main(int argc, char* argv[])
{
    LoadFEN(StartingFEN);

    for (size_t i = 0; i < sizeof(Board); i++)
    {
        printf("%d\n", Board[i]);
    }
    printf("-------");
    printf("%d\n",Board[63]);

    if (GetColour(Board[4]) == Black)
    {
        printf("test");
    }
    


    while(true) {}
}

void LoadFEN(char* in) 
{
    for (unsigned char i = 0; i < sizeof(Board); i++)
    {
        switch(in[i])       
        {
            case 'p':
                Board[i] = (char)(Pawn | Black);
            break;
            case 'P':
                Board[i] = (char)(Pawn | White);
            break;
            case 'n':
                Board[i] = (char)(Knight | Black);
            break;
            case 'N':
                Board[i] = (char)(Knight | White);
            break;
            case 'b':
                Board[i] = (char)(Bishop | Black);
            break;
            case 'B':
                Board[i] = (char)(Bishop | White);
            break;
            case 'r':
                Board[i] = (char)(Rook | Black);
            break;
            case 'R':
                Board[i] = (char)(Rook | White);
            break;
            case 'q':
                Board[i] = (char)(Queen | Black);
            break;
            case 'Q':
                Board[i] = (char)(Queen | White);
            break;
            case 'k':
                Board[i] = (char)(King | Black);
            break;
            case 'K':
                Board[i] = (char)(King | White);
            break;

            default:
            break;
        }
    }
}