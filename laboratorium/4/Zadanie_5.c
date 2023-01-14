/*
 * Nazwa pliku: Zadanie_5.c
 * Autor: Edvinas
 * Data: 2022-11-29
 * Opis: Funkcja rekurencyjna do wyprowadzenia n-tej liczby trojkatu Paskalia
 */

#include <stdio.h>
 
long Factorial(int);
 
int main()
{
  printf("%d", pascal(7, 4));
  return 0;
}

int pascal(int row, int col) {
   if(col == 0)
     return 1;

  if(row == 0)
    return col;

  return (row * pascal(row - 1, col - 1)) / col;
}
