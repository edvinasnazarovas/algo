#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//Obliczyc funkcja y = ax^2 znaczenia, gdy a - stale, x jest wybierany z tablicy X(n)

int main(void) {
  double a, x;
  int d, n;
  srand(time(NULL));

  printf("Wprowadz dlugosc tablicy: ");
  scanf("%d", &d);
  
  printf("Wprowadz n: ")
  scanf("%d", &n);
  
  printf("Wprowadz a: ");
  scanf("%lf", &a);

  double array[d];

  int i = d + 1;
  while(i--){
    array[i] = rand() % 20;
  }
    x = array[n];
    printf("%lf = ", (a*x*x));
    printf("%lf * ", a);
    printf("%lf^2\n", x);
  
  return 0;
}
