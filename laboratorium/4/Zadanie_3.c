#include <stdio.h>

int Arytm(int arr[], int n, int d);

int main(void) {
  printf("Hello World\n");
  int k[] = {1, 4, 7, 10};
  int n = 3;
  int d = k[n] - k[n-1];
  printf("Arytm is: %d\n", Arytm(k, n, d));
  return 0;
}

int Arytm(int arr[], int n, int d) {
  printf("%d\n", n);

  if(n == 1) 
    return d;
  
  if(arr[n] - arr[n-1] != d)
    return 0;
    
  return Arytm(arr, n - 1, d);
}
