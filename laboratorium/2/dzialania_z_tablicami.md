# Tablicy
## Dzialanie z tablicami
- Poszukiwanie elementu.
- Dodanie elementa. Na n pozicja tablicy.
- Kasowanie elementu.
- Znajdz maksymalny / minimalny.
- Ile elementow w tablice / Sprawdiz czy pusta tablica
- Wyprowadzić elementy tablicy
```C
int find(int item, int *arr);

void insert(int item, int pos, int *arr);

void rem(int pos, int *arr);

int size(int *arr);

int findMax(int *arr);

int findMin(int *arr);

void printTable(int *arr);

#include <stdio.h>
#include <stdlib.h>

void main(void) {
  int n = 10;
  int *arr = calloc(n, sizeof(int));

  for(int i = 0; i < n; i++)
    scanf("%d", arr + i);
  
  // realizacja

  return;
}

    // Funkcii

int find(int item, int *arr){
  int n = size(arr);
  
  while(n--)
    if(arr[n] == item)
      return n;
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


int size(int *arr){
  int length = 0;
  while(arr[length] != 0)
    length++;
  return length - 1;
}


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
https://replit.com/@EdvinasNazarova/Tablicy-2#main.c
