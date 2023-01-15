#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct DoubleLinkedList {
  Node *head;
  Node *tail;
  size_t size;
} DoubleLinkedList;

// Tworzy nową listę dwóch kierunkową i zwraca pointer do niej.
DoubleLinkedList *createDoubleLinkedList();

// Tworzy nowy node z podaną liczbą i zwraca pointer do niej.
Node *createNode(int data);

// Dobawia nowy node z integer'em na końcu listy.
void insertNode(DoubleLinkedList *list, int data);

// Kasuje node na podanej pozycji.
void deleteNode(DoubleLinkedList *list, Node *nodeToDelete);

// Szuka node o wskazanej wartości. Jeżeli nie znachodzi, zwraca NULL.
Node *searchNode(DoubleLinkedList *list, int data);

// Kasuje powtarzające się dane.
void removeDuplicates(DoubleLinkedList *list);

// Drukuje listę dwóch kierunkową.
void printDoubleLinkedList(DoubleLinkedList *list);

DoubleLinkedList *createDoubleLinkedList() {
  DoubleLinkedList *list = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

Node *createNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void insertNode(DoubleLinkedList *list, int data) {
  Node *node = createNode(data);
  if (list->size == 0) {
    list->head = node;
    list->tail = node;
  } else {
    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

void deleteNode(DoubleLinkedList *list, Node *nodeToDelete) {
  if (list == NULL || nodeToDelete == NULL)
    return;

  if (nodeToDelete->prev != NULL) {
    nodeToDelete->prev->next = nodeToDelete->next;
  }
  if (nodeToDelete->next != NULL) {
    nodeToDelete->next->prev = nodeToDelete->prev;
  }

  if (nodeToDelete == list->head) {
    list->head = nodeToDelete->next;
  }

  if (nodeToDelete == list->tail) {
    list->tail = nodeToDelete->prev;
  }

  free(nodeToDelete);
  list->size--;
}

Node *searchNode(DoubleLinkedList *list, int data) {
  Node *current = list->head;
  while (current != NULL) {
    if (current->data == data) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void removeDuplicates(DoubleLinkedList *list) {
  if (list == NULL || list->size == 0)
    return;

  Node *current = list->head;
  while (current != NULL) {

    Node *next = current->next;

    Node *duplicate = current->next;
    while (duplicate != NULL) {

      if (duplicate->data == current->data) {

        Node *duplicateNext = duplicate->next;

        deleteNode(list, duplicate);

        duplicate = duplicateNext;
      } else {

        duplicate = duplicate->next;
      }
    }

    current = next;
  }
}

void printDoubleLinkedList(DoubleLinkedList *list) {
  Node *current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

#endif
