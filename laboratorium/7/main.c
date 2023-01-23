/*
 * Nazwa pliku: main.c
 * Autor: Edvinas
 * Data: 2023-01-23
 * Opis: Realizacja pseudokodu z cwiczen i algorytmów dopasowania wzorców z wykładu 6
 */

#include "match.h"
#include <stdio.h>
#include <string.h>

int main() {
  char text[] = "Molestiae22 occaecati cupiditate magni. Qui iusto et. Iusto voluptas rem 34itaque quisquam aspernatur vero. Quia voluptatem minus eaque illum 57quidem. Suscipit deleniti ipsum autem debitis iure et et corrupti eligendi. Repellat placeat vel eum amet.";
  char text2[] = "Molestiae magni placeat";

  findCommonLetters(text, text2);
  printf("\n");
  
  deleteLongestWord(text);
  printf("\n");
  
  printf("%d\n\n", countNumbers(text));
  
  extractNonRepeatingWords(text);
  printf("\n");

  printf(isAnagram(text, text2) ? "Jest anagram" : "Nie jest anagram");

  char txt[] = "ABAAAABAABAAAAB";
  char pat[] = "AAAAB";

  printf("\n");
  boyerMoore(txt, pat);
  printf("\n");
  
  KMPSearch(pat, txt);
  printf("\n");
  
  rabin_karp(txt, pat);
  printf("\n");
  
  naive_search(txt, pat);
  
  return 0;
}
