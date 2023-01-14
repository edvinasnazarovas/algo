#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEED_MAX_LIMIT 138573

void binarySearchRecursive(int arr[], int lo, int hi, int key);
void merge(int arr[], int l, int mid, int r);
void mergeSort(int arr[], int l, int r);
void binarySearch(int arr[], int f, int l, int n);
int kroki = 0, kroki1 = 0;

int main(void) {
  FILE *fptr;
  clock_t start, end;
  double execution_time;

  fptr = fopen("random.dat", "w");

  int n = 0, i = 0;
  srand((unsigned)time(NULL));

  if (fptr != NULL) {
    printf("File created successfully!\n");
  } else {
    printf("Failed to create the file.\n");
    return -1;
  }

  do {
    printf("Wprowadzenie n. Musi byc != 0 \n");
    scanf("%d", &n);
  } while (n <= 0);

  start = clock();
  
  while (i < n) {
    int j = 1 + rand() % SEED_MAX_LIMIT;
    fprintf(fptr, "%d\n", j);
    i = i + 1;
  }
  
  end = clock();
  execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("\n\nGenerowanie liczb zajmilo %f sek. \n", execution_time);
  
  fclose(fptr);

  fptr = fopen("random.dat", "r");

  int arr[n];

  for (i = 0; i < n; i++) {
    fscanf(fptr, "%d", &arr[i]);
  }

  start = clock();

  mergeSort(arr, 0, n - 1);

  end = clock();

  execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("\n\n\n\nMerge sort zajmil %f sek.\n\n\n\n", execution_time);

  fptr = fopen("sorted.dat", "w");

  for (int i = 0; i < n; i++) {
    fprintf(fptr, "%d\n", arr[i]);
  }
  fclose(fptr);

  int key = arr[3];

  start = clock();
  binarySearchRecursive(arr, 0, n, key);
  end = clock();
  execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("\nBinary search recursive zajmil %f sekund\n\n", execution_time);

  start = clock();
  binarySearch(arr, 0, n, key);
  end = clock();
  execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("\nBinary search zajmil %f sekund\n\n", execution_time);
}

void merge(int arr[], int l, int mid, int r) {
  int i, j, k;
  int size1 = mid - l + 1;
  int size2 = r - mid;

  int Left[size1], Right[size2];

  for (i = 0; i < size1; i++)
    Left[i] = arr[l + i];

  for (j = 0; j < size2; j++)
    Right[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < size1 && j < size2) {
    if (Left[i] <= Right[j]) {
      arr[k] = Left[i];
      i++;
    } else {
      arr[k] = Right[j];
      j++;
    }
    k++;
  }

  while (i < size1) {
    arr[k] = Left[i];
    i++;
    k++;
  }

  while (j < size2) {
    arr[k] = Right[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
  }
}

void binarySearchRecursive(int arr[], int lo, int hi, int key) {
  int mid;
  kroki++;

  if (lo > hi) {
    printf("|Key nie znajdziony|\n");
    return;
  }
  mid = (lo + hi) / 2;
  if (arr[mid] == key) {
    printf("|Key znajdziony w %d krokach|\n", kroki);
  } else if (arr[mid] > key) {
    binarySearchRecursive(arr, lo, mid - 1, key);
  } else if (arr[mid] < key) {
    binarySearchRecursive(arr, mid + 1, hi, key);
  }
}

void binarySearch(int arr[], int f, int l, int n) {
  int i, mid;
  kroki1++;
  mid = (f + l) / 2;

  while (f <= l) {
    if (arr[mid] < n)
      f = mid + 1;
    else if (arr[mid] == n) {
      printf("|%d znajdziony na pos %d w %d krokach.|\n", n, mid + 1, kroki1);
      break;
    } else
      l = mid - 1;

    mid = (f + l) / 2;
  }
  if (f > l)
    printf("|%d nie znajdziony.|\n", n);
}
