/*
 * Nazwa pliku: stos.c
 * Autor: Edvinas
 * Data: 2022-11-02
 * Opis: Działania z stosem
 */

struct Item {
  int value;
  struct Item *next;
};

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Item *newNode(int data);

// Sprawdz czy pusty
int isEmpty(struct Item *root);

// Dodaj element do gory stosu.
void push(struct Item **root, int data);

// Wyberanie elementa ze stosa
int pop(struct Item **root);

// Wyswetlien elementa ze gory stosu.
int peek(struct Item *root);

// Wyczysc
void makeNull(struct Item **root);

void makeNull(struct Item **root) {
  struct Item *temp, *current = *root;
  while (current) {
    temp = current->next;
    free(current);
    current = temp;
  }
  *root = NULL;
}

int main() {
  struct Item *root = NULL;

  push(&root, 10);
  push(&root, 20);
  push(&root, 30);

  printf("%d popped from stack\n", pop(&root));

  printf("Top element is %d\n", peek(root));

  makeNull(&root);

  printf(isEmpty(root) != 0 ? "Stack is empty\n" : "Stack is not empty\n");

  return 0;
}

// Funkcii

/*Pseudocode
  newNode(data){
    allocate stackNode
    set stackNode value to data
    set stackNode next to null
    return stackNode
  }
*/

struct Item *newNode(int data) {
  struct Item *stackNode = (struct Item *)malloc(sizeof(struct Item));
  stackNode->value = data;
  stackNode->next = NULL;
  return stackNode;
}

/*Pseudocode
  isEmpty(struct root pointer) {
    return !root
  }
*/

int isEmpty(struct Item *root) { return !root; }

/*Pseudocode
  push(struct root, data) {
    set stackNode to newNode(data)
    set stackNode next to root pointer
    set root pointer to stackNode
    print data
    end
  }
*/

void push(struct Item **root, int data) {
  struct Item *stackNode = newNode(data);
  stackNode->next = *root;
  *root = stackNode;
  printf("%d pushed to stack\n", data);
}

/*Pseudocode
  pop(struct root) {
    if(isEmpty(root pointer))
      return INT_MIN
    set temp pointer to root pointer
    set root pointer to (*root) next
    set popped to temp value
    free temp
    return popped
  }
*/

int pop(struct Item **root) {
  if (isEmpty(*root))
    return INT_MIN;
  struct Item *temp = *root;
  *root = (*root)->next;
  int popped = temp->value;
  free(temp);

  return popped;
}

/*Pseudocode
  peek(root pointer) {
    if(isEmpty(root))
      return INT_MIN
    return root value
  }
*/

int peek(struct Item *root) {
  if (isEmpty(root))
    return INT_MIN;
  return root->value;
}
