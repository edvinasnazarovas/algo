/*
 * Nazwa pliku: Zadanie_1.c
 * Autor: Edvinas
 * Data: 2022-11-29
 * Opis: Dana calkowita liczba n >=1. Napisz rekurencyjna funkcja takiej liczby , ktora wypelnia taki warunek 2^a-1 <= n < 2^a
 */

#include <stdio.h>
#include <math.h>

int myFunction(int n);

int main(void) {
  int n = 4;
  printf("a: %d\n", myFunction(n));
  return 0;
}

int myFunction(int n) {
  if(n == 0)
    return 0;
  if(pow(2, n-1) <= n && n < pow(2, n))
    return n;
  else 
    return myFunction(n - 1);
}

