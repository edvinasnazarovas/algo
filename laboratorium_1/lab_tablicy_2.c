#include <stdio.h>
#include <math.h>

//Obliczyc funkcja y = ax^2 znaczenia, gdy a - stale. x - zmieniase z x0 do xn, krokiem hx

int main(void) {
  double a, x, x0, xn, xh;

  printf("Wprowadz a: ");
  scanf("%lf", &a);

  printf("Wprowadz x0: ");
  scanf("%lf", &x0);

  printf("Wprowadz xn: ");
  scanf("%lf", &xn);

  printf("Wprowadz xh: ");
  scanf("%lf", &xh);

  x = x0;

  while(x <= xn){
    printf("%f = ", (a*x*x));
    printf("%f * ", a);
    printf("%f^2\n", x);
    x = x + xh;
  } 
  
  return 0;
}
