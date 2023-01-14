/*
 * Nazwa pliku: Zadanie_4.c
 * Autor: Edvinas
 * Data: 2022-11-29
 * Opis: Funkcja rekurencyjna do obliczenia n-tej liczby ciągu geomytrecznego
 */

#include <stdio.h>

float geo(float a, float r, int n);

int main(void) {
  printf("Hello World\n");
  float sum = 0;

  geo(1, 0.5, 10)
  
  return 0;
}

float geo(float a, float r, int n) {
  a = a * r;
  
  if(n == 1)
    return 0;
  
  else
    return geo(a, r, n - 1, sum);
}
