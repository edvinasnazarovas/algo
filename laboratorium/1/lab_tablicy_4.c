/*
 * Nazwa pliku: lab_tablicy_4.c
 * Autor: Edvinas
 * Data: 2022-10-30
 * Opis: Obliczenie sumy, ilosci i mnozenia elementow tablicy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  double sum = 0, mnoz = 1;
  int d, i;
  srand(time(NULL));

  printf("Wprowadz dlugosc tablicy: ");
  scanf("%d", &d);

  double array[d];

  for (i = 0; i < d; i++) {
    array[i] = rand() % 20;
    printf("%lf\n", array[i]);
    sum += array[i];
    mnoz *= array[i];
  }

  printf("suma = %lf\n", sum);
  printf("mnozenia = %lf\n", mnoz);
  printf("ilosc = %d\n", d);
  return 0;
}
