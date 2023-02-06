#include "cipher.h"
#include "doubleLinkedList.h"
#include "lcg.h"
#include <stdio.h>

int main() {
  int Xo = 5;
  int m = 7;  
  int a = 3;
  int c = 3;
  char s[256] = "Testing Testing Testing";

  // N losowych liczb do generowania
  int noOfRandomNums = 10;

  // Zachowanie losowych liczb
  int randomNums[noOfRandomNums];

  linearCongruentialMethod(Xo, m, a, c, randomNums, noOfRandomNums);

  printf("                    LCG\n-------------------------------------------\n");
  
  // Wydrukowanie pseudolosowych liczb
  printf("Generujemy pseudolosowe liczby za pomocą LCG: \n");
  for (int i = 0; i < noOfRandomNums; i++) {
    printf("%d \n", randomNums[i]);
  }

  printf("-------------------------------------------\n");

  printf("\n\n\n                 Szyfrowanie\n-------------------------------------------\n");
  printf("Słowo - '%s'\n\n", s);
  
  printf("Szyfrowanie tekstu:\n");
  cipher(Xo, m, a, c, s);

  printf("%s\n", s);

  printf("\nDeszyfrowanie tekstu:\n");
  decipher(Xo, m, a, c, s);

  printf("%s\n", s);

  printf("-------------------------------------------\n");

  DoubleLinkedList *list = createDoubleLinkedList();
  insertNode(list, 5);
  insertNode(list, 8);
  insertNode(list, 3);
  insertNode(list, 6);
  insertNode(list, 2);
  insertNode(list, 5);
  insertNode(list, 3);
  insertNode(list, 6);

  printf("\n\n\n       Usunięcie duplikatów w liście\n-------------------------------------------\n");

  printf("Lista: \n");
  printDoubleLinkedList(list);

  removeDuplicates(list);

  printf("\nLista po usunięciu duplikatów:\n");
  printDoubleLinkedList(list);

  printf("-------------------------------------------\n");

  return 0;
}
