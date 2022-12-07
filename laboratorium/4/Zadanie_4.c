#include <stdio.h>

float geo(float a, float r, int n, float sum);

int main(void) {
  printf("Hello World\n");
  float sum = 0;

  printf("Sum: %f\n", geo(1, 0.5, 10, sum));
  
  return 0;
}

float geo(float a, float r, int n, float sum) {
  sum = sum + a;
  a = a * r;
  
  if(n == 1)
    return sum;
  
  else
    return geo(a, r, n - 1, sum);
}
