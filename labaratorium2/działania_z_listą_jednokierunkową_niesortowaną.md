# Działania z listą jednokierunkową niesortowaną
- Poszukiwanie elementu.
- Znachodzenie pointera o wskazanej wartości
- Zwraca element listy zza wskazany pointerem
- Dodanie elementa.
- Kasowanie element za wskazanym pointerem
- Znajdź maksymalny / minimalny element listy
- Wyprowadzić lista elementów
- Ile elementów w liście
- Sprawdź czy pusta lista
- Następny element listy po wskazanym pointerze
- Poprzedni element listy po wskazanym pointerze
- Wyczyść lista
```C
#include <stdio.h>
#include <stdlib.h>

struct Item {
        float value;
        struct Item* next;
    }* head = NULL,
   *tail
   = NULL;

    int find(int *head, float x);

    void insert(int);
void printList();
void delete (int);

    /*int locate(float value, int *head);

    int retrieve(Item *item, int *head);

    void insert(Item *item, float value, Item *head);

    void remove(Item *item, Item *head);

    int size(int *head);

    Item findMax(int *head);

    Item findMin(int *head);

    int printList(int *head);

    int isEmpty(int *head);

    void next(Item *item, Item *head);

    void previous(Item *item, Item *head);

    int makeNull(int *head);*/

    // Funkcii
void delete(int pos){
  struct Item* temp = head;

  int i;

  if (pos == 0) {
        printf("\nWytarty element : %f\n", temp->value);
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
  else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        struct Item* del
            = temp->next;

        temp->next = temp->next->next;
        printf("\nElement wytarty : %f\n", del->value);
        del->next = NULL;
        free(del);
    }

    return;
}

void insert(int value)
{
    struct Item* newnode;
    newnode = (struct Item*)malloc(
        sizeof(struct Item));

    newnode->value = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;

    }
    return;
}

void printList()
{
    struct Item* temp;

    temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf(" %f NULL", temp->value);
        }
        else {
            printf(" %f ", temp->value);
        }
        temp = temp->next;
    }
    printf("\n");
    return;
}

int find(int *head, float x){
  struct Item* current = head;
    while (current != NULL) {
        if (current->value == x)
            return 1;
        current = current->next;
    }
    return 0;
}

int retrieve(int *head, int n){
  struct Item* current = head;
  int i = 0;
  while(current != NULL){
    if(i == n)
      return current->value;

  current = current->next;
  i++;
    }
  return 0;
}

int locate(int *head, float value){
  struct Item* current = head;
  int i = 0;
  while(current != NULL){
    if(current->value == value)
      return i;
    current = current->next;
    i++;
  }
  return 0;
}

float findMax(struct Item * p){
  float max = -32768;

  while (p) {
        if (p->value > max)
         max = p->value;
        p = p->next;
    }
    return (max);
}

float findMin(struct Item * p){
  float min = 32768;

  while (p) {
        if (p->value < min)
         min = p->value;
        p = p->next;
    }
    return (min);
}

int size(int *head){
  int i = 0;
  struct Item* current = head;
  while(current != NULL){
    i++;
    current= current->next;
  }
  return i;
}

int isEmpty(int *head){
  int i = 0;
    if(head == NULL)
      return 1;
  return 0;
}

struct Item* next(struct Item *head, struct Item *item){
  struct Item* current = item;
  current = current->next;
  return current;
}

int makeNull(int *head){
  struct Item* current = *head;
   struct Item* next;

  while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
  *head = NULL;

}

void main(void) {
        // realizacja
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    printList();
    delete (1);
    delete (3);
    printList();
    printf ("\nMax %f\nMin %f\nretrieve %d\nlocate %d\nsize %d\n", findMax(head), findMin(head), retrieve(head, 1), locate(head, 60), size(head));
    makeNull(&head);
    printList();

      return;
    }
```

https://replit.com/@EdvinasNazarova/Dzialania-z-lista-jednokierunkowa-niesortowana#main.c
