//Obliczyc funkcja y = ax^2 znaczenia, gdy a ir x zmeniajan sie jednoczesnie: a z 1 krokiem 0.5, x - z 2 do 6 krokiem 2

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
