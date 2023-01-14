#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEED_MAX_LIMIT 138573

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++) {

    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    if (min_idx != i)
      swap(&arr[min_idx], &arr[i]);
  }
}

void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)

    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void generate(FILE *fptr, int n) {
  int i = 0;
  while (i < n) {
    int j = -SEED_MAX_LIMIT + rand() % (SEED_MAX_LIMIT - (-SEED_MAX_LIMIT) + 1);
    fprintf(fptr, "%d\n", j);
    i = i + 1;
  }
}

int main() {
  int n = 10;
  int arr[n];
  FILE *fptr;
  clock_t start, end;
  double execution_time;
  
  fptr = fopen("random.dat", "w");
  
  generate(fptr, n);

  fptr = fopen("random.dat", "r");

  for (int i = 0; i < n; i++) {
    fscanf(fptr, "%ld", &arr[i]);
  }

  fclose(fptr);

  int array_size = sizeof(arr) / sizeof(arr[0]);
  
  start = clock();
  bubbleSort(arr, array_size);
  end = clock();
  
  execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Sorted array: \n");
  printArray(arr, array_size);
  printf("\nTime elapsed: %f\n", execution_time);
  return 0;
}
