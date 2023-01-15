/*
 * Nazwa pliku: dzialania_z_tablicami.c
 * Autor: Edvinas
 * Data: 2022-11-02
 * Opis: Działanie z tablicami
 */

#include <stdio.h>
#include <stdlib.h>

// Ile elementow w tablice.
int size;

// Poszukiwanie elementa. Podajemy wartosc i tablica.
int find(int *arr, int item) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == item) {
      return i;
    }
  }
  return -1;
}

// Dodanie elementa. Na n pozicja tablicy. Sprawdzenie czy jest tablica z
// odpowiednia ilością elementów przed dodaniem.
void insert(int item, int pos, int **arr) {
  if (pos < size) {
    *arr = (int *)realloc(*arr, (size + 1) * sizeof(int));
    for (int i = size - 1; i >= pos; i--) {
      (*arr)[i + 1] = (*arr)[i];
    }
    (*arr)[pos] = item;
    size++;
  }
}

// Kasowanie elementa. Sprawdzenie czy jest tablica z odpowiednia ilością
// elementów przed kasowaniem,.
void rem(int pos, int **arr) {
  if (pos < size) {
    for (int i = pos; i < size - 1; i++) {
      (*arr)[i] = (*arr)[i + 1];
    }
    size--;
    *arr = (int *)realloc(*arr, size * sizeof(int));
  }
}

// Sprawdz czy pusta tablica.
int isEmpty(int *arr) { return size == 0; }

// Znajdz maksymalny
int findMax(int *arr) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Znajdz minimalny
int findMin(int *arr) {
  int min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

// Wyprowadzić elementy tablicy
void printTable(int *arr) {
  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("[%d] %d\n", i, arr[i]);
  }
}

int main(void) {
  int *arr = (int *)malloc(sizeof(int));
  size = 1;

  insert(5, 0, &arr);
  insert(1, 1, &arr);
  insert(2, 2, &arr);
  insert(4, 3, &arr);
  insert(5, 4, &arr);
  insert(10, 5, &arr);

  printTable(arr);

  printf("size of the array: %d\n", size);

  rem(2, &arr);

  printTable(arr);

  printf("size of the array: %d\n", size);

  printf("Max: %d\n", findMax(arr));
  printf("Min: %d\n", findMin(arr));

  printf(find(arr, 4) != -1 ? "Found in pos %d\n" : "Not found\n",
         find(arr, 4));

  printf(isEmpty(arr) != 0 ? "\nArray is empty\n" : "\n Array is not empty\n");

  free(arr);

  return 0;
}
