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

  // Wydrukowanie pseudolosowych liczb
  for (int i = 0; i < noOfRandomNums; i++) {
    printf("%d \n", randomNums[i]);
  }

  cipher(Xo, m, a, c, s);

  printf("%s\n", s);

  decipher(Xo, m, a, c, s);

  printf("%s\n", s);

  DoubleLinkedList *list = createDoubleLinkedList();
  insertNode(list, 5);
  insertNode(list, 8);
  insertNode(list, 3);
  insertNode(list, 6);
  insertNode(list, 2);
  insertNode(list, 5);
  insertNode(list, 3);
  insertNode(list, 6);

  printf("%p\n", searchNode(list, 5));

  printDoubleLinkedList(list);

  removeDuplicates(list);

  printDoubleLinkedList(list);

  return 0;
}
