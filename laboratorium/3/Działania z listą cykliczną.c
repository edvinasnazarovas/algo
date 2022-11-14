#include <stdio.h>
#include <stdlib.h>

struct Item {
  float value;
  struct Item *next;
  struct Item *prev;
  int visited;
};

struct counter { 
  struct Item *item;
};

int find(float value, struct Item *head);

void clearVisits(struct Item **head);

int printList(struct Item **head);

void insert(struct Item *item, int value, struct Item *head);

float findMax(struct Item **head);

float findMin(struct Item **head);

int size(struct Item *head);

int isEmpty(struct Item *head);

float next(void *item, struct Item *head);

float prev(void *item, struct Item *head);

void makeNull(struct Item *head);

void *locate(float value, struct Item *head);

float retrieve(void *pointer, struct Item *head);

void removeItem(struct Item **head, void *pointer);


int main(void) {
  // realizacja
  struct counter count[9999];
  
  struct Item *head = NULL;
  struct Item *second = NULL;
  struct Item *third = NULL;

  head = (struct Item *)malloc(sizeof(struct Item));
  second = (struct Item *)malloc(sizeof(struct Item));
  third = (struct Item *)malloc(sizeof(struct Item));

  head->value = 1;
  head->next = second;
  head->prev = NULL;

  second->value = 2;
  second->next = third;
  second->prev = head;

  third->value = 3;
  third->next = NULL;
  third->prev = second;

  insert(third, 5, head);

  printf("\n\n-------Print List--------\n");
  printList(&head);
  printf("--------------------\n\n");

  printf("find: %s\n", find(5, head) ? "found" : "not found");

  void *p = locate(5, head);

  printf("Retrieve: %f\n", retrieve(p, head));

  struct Item *pointer1 = p;

  printf("Max element is: %f\n", findMax(&head));

  printf("Min element is: %f\n", findMin(&head));

  printf("Size of list is: %d\n", size(head));

  printf("Is list empty: %s\n", isEmpty(head) ? "empty" : "not empty");

  void *p2 = locate(3, head);
  
  /* BUG: Next czy Prev na wytarty element zamraza program. Nie wiem jak naprawic. */

  printf("Next: %f\n", next(p2, head));

  printf("Prev: %f\n", prev(p2, head));

  removeItem(&head, p);

  printf("\n\n-------Print List--------\n");
  printList(&head);
  printf("--------------------\n\n");

  return 0;
}

void clearVisits(struct Item **head){
  struct Item *temp = *head;

  while(temp != NULL && temp->visited == 1) {
    temp->visited = 0;
    temp = temp->next;
    }
}

// Funkcii
int find(float value, struct Item *head) {
  struct Item *current = head;
  while (current != NULL && current->visited != 1) {
    current->visited = 1;
    if (current->value == value){
      clearVisits(&head);
      return 1;
      }
    current = current->next;
  }
  clearVisits(&head);
  return 0;
}

void *locate(float value, struct Item *head) {

  while (head != NULL && head->visited != 1) {
    head->visited = 1;
    if (head->value == value){
      clearVisits(&head);
      return head;
    }
    head = head->next;
  }
  clearVisits(&head);
  return 0;
}

float retrieve(void *pointer, struct Item *head) {
  clearVisits(&head);
  while (head != NULL && head->visited != 1) {
    head->visited = 1;
    if (head == pointer){
      clearVisits(&head);
      return head->value;
    }
    head = head->next;
  }
  clearVisits(&head);
  return 0;
}

void insert(struct Item *item, int value, struct Item *head) {
  if (item == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Item *new_node = (struct Item *)malloc(sizeof(struct Item));

  new_node->value = value;

  new_node->next = item->next;

  item->next = new_node;

  new_node->prev = item;

  if (new_node->next != NULL)
    new_node->next->prev = new_node;
  else if (new_node->next == NULL)
    new_node->next = head;
}

int printList(struct Item **head) {
  struct Item *temp = *head;
  while (temp != NULL && temp->visited != 1) {
    printf("%f\n", temp->value);
    temp->visited = 1;
    temp = temp->next;
  }
  clearVisits(head);
  return 0;
}

void removeItem(struct Item **head, void *pointer) {
  struct Item *temp = *head, *prev;
  clearVisits(head);
  if (temp != NULL && temp == pointer) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp != pointer && temp->visited != 1) {
    temp->visited = 1;
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL){
    clearVisits(head);
    return;
  }

  prev->next = temp->next;

  clearVisits(head);

  free(temp);
}

float findMax(struct Item **head) {
  struct Item *max, *temp;

  temp = max = *head;

  clearVisits(head);

  while (temp != NULL && temp->visited != 1) {
    if (temp->value > max->value)
      max = temp;
    
    temp->visited = 1;
    temp = temp->next;
  }
  clearVisits(head);
  return max->value;
}

float findMin(struct Item **head) {
  struct Item *min, *temp;

  temp = min = *head;

  clearVisits(head);

  while (temp != NULL && temp->visited != 1) {
    if (temp->value < min->value)
      min = temp;

    temp->visited = 1;
    temp = temp->next;
  }
  clearVisits(head);
  return min->value;
}

int size(struct Item *head) {
  struct Item *current = head;
  int i = 0;
  while (current != NULL && current->visited != 1) {
    i++;
    current->visited = 1;
    current = current->next;
  }
  clearVisits(&head);
  return i;
}

int isEmpty(struct Item *head) {
  if (head == NULL)
    return 1;
  return 0;
}

float next(void *item, struct Item *head) {
  clearVisits(&head);
  while (head != NULL && head->visited != 1) {
    if (head == item){
      clearVisits(&head);
      return head->next->value;
      }
    head = head->next;
  }
  clearVisits(&head);
  return 0;
}

float prev(void *item, struct Item *head) {
  clearVisits(&head);
  while (head != NULL && head->visited != 1) {
    if (head == item){
      clearVisits(&head);
      return head->prev->value;
      }
    head = head->next;
  }
  return 0;
}

void makeNull(struct Item *head) {
  struct Item *temp;

  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
