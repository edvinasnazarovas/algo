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
  printf("%lf = ", (a*x*x));
  printf("%lf * ", a);
  printf("%lf^2\n", x);
  
  return 0;
}
