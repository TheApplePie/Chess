#ifndef GRAPHICS_H
#define GRAPHICS_H

//Includes
#include <iostream>

#if defined(USE_GUI) && !defined(USE_CONSOLE)
    #include "SDL2/SDL.h"
#endif

//Pre-Proccesor Definitions
//Pieces

#define Blank       0x0

#define King_Char   '\u2654'
#define Queen_Char  '\u2655'
#define Rook_Char   '\u2656'
#define Bishop_Char '\u2657'
#define Knight_Char '\u2658'
#define Pawn_Char   '\u2659'

#define White_Char  0x0
#define Black_Char  0x6

#ifdef _WIN32
#include <windows.h>

void ClearScreen()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
}

#else // !_WIN32
#include <unistd.h>
#include <term.h>

void ClearScreen()
{
  if (!cur_term)
  {
     int result;
     setupterm( NULL, STDOUT_FILENO, &result );
     if (result <= 0) return;
  }

   putp( tigetstr( "clear" ) );
}
#endif

void UpdateScreen() 
{
    ClearScreen();
}

#endif