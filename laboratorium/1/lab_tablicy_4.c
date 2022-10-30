#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Obliczenie sumy, ilosci i mnozenia elementow tablicy.

int main(void) {
  double a, x, sum = 0, mnoz = 1;
  int d, n, ilosc;
  srand(time(NULL));

  printf("Wprowadz dlugosc tablicy: ");
  scanf("%d", &d);

  double array[d+1];

  int i = d;
  while (i--) {
    array[i] = rand() % 20;
    printf("%lf\n", array[i]);
  }

  array[d+1] = 0;

  i = d;
  while (i--) {
    sum = sum + array[i];
  }

  i = d;
  while (i--) {
    mnoz = mnoz * array[i];
  }
  
  //printf("Ilosc = %d\n", ilosc);
  printf("suma = %lf\n", sum);
  printf("mnozenia = %lf\n", mnoz);
  //printf("ilolsc elementow = %lf\n", ilosc);
  return 0;
}
