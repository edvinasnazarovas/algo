#include <stdio.h>
#include <math.h>

int main(void) {
  double a, x, y;

  a = 1;
  x = 2;

  while(x <= 6){
    printf("%f = ", (a*x*x));
    printf("%f * ", a);
    printf("%f^2\n", x);
    a = a + 0.5;
    x = x + 2;
  } 
  
  return 0;
}
