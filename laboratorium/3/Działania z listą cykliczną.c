#include <stdio.h>
#include <stdlib.h>

struct Item {
  float value;
  struct Item *next;
  struct Item *prev;
  int visited;
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
  third->next = head;
  third->prev = second;

  insert(third, 5, head);

  printList(&head);

  // printf("Element found: %s\n", find(4, head) ? "found" : "not found");

  clearVisits(&head);

  void *p = locate(3, head);

  printf("\n%p\n", p);

  // insert(p, 4);
  // insert(p, 9);

  // printf("Pointer is: %p\n", p);

  // printf("Pointer element is: %f\n", retrieve(p, head));

  // removeItem(&head, p);

  // printf("Max element is: %f\n", findMax(&head));

  // printf("Min element is: %f\n", findMin(&head));

  /// printf("\nList\n");

  // printList(head);

  // printf("\nSize of list is: %d\n", size(head));

  // printf("Is list empty: %s\n", isEmpty(head) ? "empty" : "not empty");

  // void *p2 = locate(2, head);

  // printf("Element next to the specified pointer is: %f\n", next(p2, head));

  /*
  Nie dziala dla elemetow dodanych przez funkcje insert
  printf("Element previous to the specified pointer is: %f\n", prev(p2, head));
  */

  return 0;
}

// Funkcii
int find(float value, struct Item *head) {
  struct Item *current = head;
  while (current != NULL) {
    if (current->value == value)
      return 1;
    current = current->next;
  }
  return 0;
}

void *locate(float value, struct Item *head) {

  while (head != NULL && head->visited != 1) {
    printf(".\n");
    if (head->value == value)
      return head;
    head = head->next;
  }
  return 0;
}

float retrieve(void *pointer, struct Item *head) {
  while (head != NULL) {
    if (head == pointer)
      return head->value;
    head = head->next;
  }
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
  while (temp != NULL) {
    if (temp->visited == 1) {
      printf("Cycle restarts at: %f\n", temp->value);
      return 0;
    }
    printf("%f\n", temp->value);
    temp->visited = 1;
    temp = temp->next;
  }
  return 0;
}

void clearVisits(struct Item **head) {
  struct Item *temp = *head;
  temp->visited = 0;
  temp = temp->next;

  while (temp != NULL && temp != *head) {
    temp->visited = 0;
    printf("visited: %d\n", temp->visited);
  }
}

void removeItem(struct Item **head, void *pointer) {
  struct Item *temp = *head, *prev;

  if (temp != NULL && temp == pointer) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp != pointer) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;

  free(temp);
}

float findMax(struct Item **head) {
  struct Item *max, *temp;

  temp = max = *head;

  while (temp != NULL) {
    if (temp->value > max->value)
      max = temp;

    temp = temp->next;
  }
  return max->value;
}

float findMin(struct Item **head) {
  struct Item *min, *temp;

  temp = min = *head;

  while (temp != NULL) {
    if (temp->value < min->value)
      min = temp;

    temp = temp->next;
  }
  return min->value;
}

int size(struct Item *head) {
  struct Item *current = head;
  int i = 0;
  while (current != NULL) {
    i++;
    current = current->next;
  }
  return i;
}

int isEmpty(struct Item *head) {
  if (head == NULL)
    return 1;
  return 0;
}

float next(void *item, struct Item *head) {
  while (head != NULL) {
    if (head == item)
      return head->next->value;
    head = head->next;
  }
  return 0;
}

float prev(void *item, struct Item *head) {
  while (head != NULL) {
    if (head == item)
      return head->prev->value;
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
