/*
 * Nazwa pliku: lab_tablicy_3.c
 * Autor: Edvinas
 * Data: 2022-10-13
 * Opis: Oblicz funkcja y=ax^2 znaczenia, gdy a - stałe, x jest wybierany z tablicy X(n)
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  double a, x;
  int d, n;
  srand(time(NULL));

  printf("Wprowadz dlugosc tablicy: ");
  scanf("%d", &d);
  
  printf("Wprowadz n: ");
  scanf("%d", &n);
  
  printf("Wprowadz a: ");
  scanf("%lf", &a);

  double array[d];

  int i = d;
  while(i--){
    array[i] = rand() % 20;
  }

  x = array[n];
  printf("%lf = ", (a*pow(x, 2));
  printf("%lf * ", a);
  printf("%lf^2\n", x);
  
  return 0;
}
