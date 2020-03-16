#pragma once
#include "common.h"

int coordinateToNumber(char *input)
{
  int convertString, column;
  char row, columnChar;

  row = input[0];             // Ex: "D"
  columnChar = input[1];      // Ex: "5"
  column = (int)columnChar - 48; // Converte ASCII para inteiro

  switch (row)
  {
  case 'A':
  case 'a':
    convertString = 28 + (((column + 1) / 2) - 1);
    break;
  case 'B':
  case 'b':
    convertString = 24 + ((column / 2) - 1);
    break;
  case 'C':
  case 'c':
    convertString = 20 + (((column + 1) / 2) - 1);
    break;
  case 'D':
  case 'd':
    convertString = 16 + ((column / 2) - 1);
    break;
  case 'E':
  case 'e':
    convertString = 12 + (((column + 1) / 2) - 1);
    break;
  case 'F':
  case 'f':
    convertString = 8 + ((column / 2) - 1);
    break;
  case 'G':
  case 'g':
    convertString = 4 + (((column + 1) / 2) - 1);
    break;
  case 'H':
  case 'h':
    convertString = 0 + ((column / 2) - 1);
    break;
  };
  return convertString;
};
