/*
 * Nazwa pliku: Zadanie_3.c
 * Autor: Edvinas
 * Data: 2022-11-22
 * Opis: Napisz funkcja rekurencyjna do obliczenia n-tej liczby ciągu arytmcznego
 */

#include <stdio.h>

int arytm(int a, int d, int n);

int main(void) {
  printf("Hello World\n");
  int a = 1;
  int d = 3;
  int n = 7;
  printf("Arytm is: %d\n", arytm(a, d, n));
  return 0;
}

int arytm(int a, int d, int n) {
  if (n == 1) {
    return a;
  }
  return arytm(a, d, n - 1) + d;
}
