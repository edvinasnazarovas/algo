#include <stdio.h>

int myFunction(int n, int a);

int main(void) {
  int n = 4;
  int a = n;
  printf("a: %d\n", myFunction(n, a));
  return 0;
}

int myFunction(int n, int a) {
  if(a == 0)
    return 0;
  
  int k1 = 2;
  int k2 = 2;

  int k1_pow = 1;
  int k2_pow = 1;
  
  for(int i = 0; i < a - 1; i++)
    {
      k1_pow = k1_pow * k1;
      printf("i: %d k1: %d\n", i, k1_pow);
    }
    
  for(int i = 0; i < a; i++)
    {
      k2_pow = k2_pow * k2;
    }
    
  if(k1_pow <= n && k2_pow > n)
  {
    printf("%d  <=  %d  <= %d\n", k1_pow, n, k2_pow);
    return a;
  }
  else 
    return myFunction(n, a - 1);
    
}
