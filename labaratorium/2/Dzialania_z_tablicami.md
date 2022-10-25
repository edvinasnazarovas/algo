# Tablicy
## Dzialanie z tablicami
- Poszukiwanie elementu.
- Dodanie elementa. Na n pozicja tablicy.
- Kasowanie elementu.
- Znajdz maksymalny / minimalny.
- Ile elementow w tablice / Sprawdiz czy pusta tablica
- Wyprowadzić elementy tablicy
```C
int find(int *arr);

void insert(int item, int pos, int *arr);

void rem(int pos, int *arr);

int size(int *arr);

int findMax(int *arr);

int findMin(int *arr);

void printTable(int *arr);

#include <stdio.h>

void main(void) {
  int arr[100];
  // realizacja
  return;
}

    // Funkcii

int find(int *arr){
  
}

void insert(int item, int pos, int *arr){
  int length = sizeof(*arr) / sizeof(int);
  if (pos <= length) {
    arr[pos] = item;
  }
}

void rem(int pos, int *arr){
  int length = sizeof(*arr) / sizeof(int);
  if(pos <= length){
    arr[pos] = 0;
  }
}

/*
int size(int *arr){
  int length = (&arr)[1] - arr;
  return length;
}
*/

int findMax(int *arr){
  int max = arr[0];
  int n = size(arr);

  while(n--){
    if(arr[n] > max) max = arr[n];
  }

  return max;
}

int findMin(int *arr){
  int min = arr[0];
  int n = size(arr);

  while(n--){
    if(arr[n] < min) min = arr[n];
    }
  return min;
}

void printTable(int *arr){
  int n = size(arr);

  while(n--){
    printf("%d %d\n", n, arr[n]);
  }
}
```
