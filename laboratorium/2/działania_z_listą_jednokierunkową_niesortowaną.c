/*
 * Nazwa pliku: działania_z_listą_jednokierunkową_niesortowaną.c
 * Autor: Edvinas
 * Data: 2022-11-02
 * Opis: Działania z listą jednokierunkową niesortowaną
 */

#include <stdio.h>
#include <stdlib.h>

struct Item {
  float value;
  struct Item *next;
};

// Poszukiwanie elementu.
int find(struct Item *head, float x);

// Dodanie elementa.
void insert(struct Item **head, float value);

// Wyprowadzić lista elementów
void printList(struct Item *head);

// Kasowanie elementa za wskazanym pointerem
void delete (struct Item **head, struct Item *pointer);

// Zwraca element listy za wskazanym pointerem
float retrieve(struct Item *head, struct Item *pointer);

// Znachodzenie pointera o wskazanej wartości
struct Item *locate(struct Item *head, float value);

// Następny element listy po wskazanym pointerze
int next(struct Item *head, struct Item *pointer);

// Znajdź maksymalny element listy
float findMax(struct Item *p);

// Znajdż minimalny element listy
float findMin(struct Item *p);

// Wyczyść lista
void makeNull(struct Item **head);

// Ile elementów w liście
int size(struct Item *head);

// Sprawdź czy pusta lista
int isEmpty(struct Item *head);

void makeNull(struct Item **head) {
  struct Item *current = *head;
  struct Item *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  *head = NULL;
}

void insert(struct Item **head, float value) {
  struct Item *newnode;
  newnode = (struct Item *)malloc(sizeof(struct Item));

  newnode->value = value;
  newnode->next = NULL;

  if (*head == NULL) {
    *head = newnode;
  } else {
    struct Item *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void delete (struct Item **head, struct Item *pointer) {
  struct Item *temp = *head;

  if (temp == pointer) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->next != pointer) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("\nPointer not found in the list.\n");
    return;
  }

  struct Item *del = temp->next;
  temp->next = del->next;
  printf("\nDeleted element : %f\n", del->value);
  free(del);
}

void printList(struct Item *head) {
  struct Item *temp;

  temp = head;
  while (temp != NULL) {
    printf(" |%f| ", temp->value);
    temp = temp->next;
  }
  printf("\n");
  return;
}

int find(struct Item *head, float x) {
  if (head == NULL)
    return 0;
  struct Item *current = head;
  while (current != NULL) {
    if (current->value == x)
      return 1;
    current = current->next;
  }
  return 0;
}

float retrieve(struct Item *head, struct Item *pointer) {
  struct Item *current = head;
  int i = 0;
  while (current != NULL) {
    if (current == pointer)
      return current->value;
    current = current->next;
    i++;
  }
  return -1;
}

struct Item *locate(struct Item *head, float value) {
  struct Item *current = head;
  while (current != NULL) {
    if (current->value == value)
      return current;
    current = current->next;
  }
  return NULL;
}

float findMax(struct Item *p) {
  if (p == NULL)
    return -32768;
  float max = -32768;

  while (p) {
    if (p->value > max)
      max = p->value;
    p = p->next;
  }
  return max;
}

float findMin(struct Item *p) {
  if (p == NULL)
    return 32768;
  float min = 32768;

  while (p) {
    if (p->value < min)
      min = p->value;
    p = p->next;
  }
  return min;
}

int size(struct Item *head) {
  if (head == NULL)
    return 0;
  int i = 0;
  struct Item *current = head;
  while (current != NULL) {
    i++;
    current = current->next;
  }
  return i;
}

int next(struct Item *head, struct Item *pointer) {
  struct Item *current = head;
  while (current != NULL && current->next != pointer) {
    current = current->next;
  }

  if (current == NULL) {
    printf("\nPointer not found in the list or it is the last element in the "
           "list.\n");
    return -1;
  }

  return current->next->value;
}

int isEmpty(struct Item *head) {
  if (head == NULL)
    return 1;
  return 0;
}

int main() {
  struct Item *head = NULL;

  insert(&head, 1.1);
  insert(&head, 2.2);
  insert(&head, 3.3);
  insert(&head, 4.4);

  printf("Original list: ");
  printList(head);

  printf(isEmpty(head) != 1 ? "\nThe list is not empty.\n"
                            : "\n The list is empty\n");

  printf(find(head, 3.3) != 0 ? "\n3.3 Found\n" : "\n3.3 Not Found\n");

  struct Item *pointer = locate(head, 2.2);

  printf(locate(head, 2.2) != NULL ? "\nValue of the pointer is: %f\n"
                                   : "\nNot found\n",
         retrieve(head, locate(head, 2.2)));

  delete (&head, pointer);
  printf("\nList after deletion: ");
  printList(head);

  printf("\nMax value: %f\n", findMax(head));
  printf("Min value: %f\n", findMin(head));
  printf("List size: %d\n", size(head));

  makeNull(&head);
  printf("\nList after makeNull:\n");
  printList(head);

  printf(isEmpty(head) != 1 ? "\nThe list is not empty.\n"
                            : "\nThe list is empty\n");

  return 0;
}
