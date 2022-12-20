#include "metody.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n = 10;
  int arr[n];
  FILE *fptr;
  clock_t start, end;
  double execution_time;
  char fileName[] = "random.dat";

  // Generujemy random.dat
  fptr = fopen(fileName, "w");
  generate(fptr, n);
  fclose(fptr);

  // File values to array
  fptr = fopen(fileName, "r");

  for (int i = 0; i < n; i++) {
    fscanf(fptr, "%u", &arr[i]);
  }

  fclose(fptr);

  int array_size = sizeof(arr) / sizeof(arr[0]);

  start = clock();
  selectionSort(arr, array_size);
  end = clock();

  execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Sorted array: \n");
  printArray(arr, array_size);
  printf("\nTime elapsed: %f\n", execution_time);
  return 0;
}
