#include <stdio.h>
#include <stdlib.h>

struct Item {
  float value;
  struct Item *next;
  struct Item *prev;
};

int find(float value, struct Item *head);

int printList(struct Item *head);

void insert(struct Item *head, int item);

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
  third->next = NULL;
  third->prev = second;

  printf("Element found: %s\n", find(4, head) ? "found" : "not found");

  void *p = locate(3, head);

  insert(p, 4);
  insert(p, 9);

  printf("Pointer is: %p\n", p);

  printf("Pointer element is: %f\n", retrieve(p, head));

  removeItem(&head, p);

  printf("Max element is: %f\n", findMax(&head));

  printf("Min element is: %f\n", findMin(&head));

  printf("\nList\n");

  printList(head);

  printf("\nSize of list is: %d\n", size(head));

  printf("Is list empty: %s\n", isEmpty(head) ? "empty" : "not empty");

  void *p2 = locate(2, head);

  printf("Element next to the specified pointer is: %f\n", next(p2, head));

  /*
  Nie dziala dla elemetow dodanych przez funkcje insert

  printf("Element previous to the specified pointer is: %f\n", prev(p2, head));
  */

  makeNull(head);

  return 0;
}

// Funkcii

/*Pseudocode
  find(value, struct head pointer) {
    declare and set current pointer to head
    while(current != null) do
      if(current value == value)
        return 1
      set current to current next
    end
  }
*/
int find(float value, struct Item *head) {
  struct Item *current = head;
  while (current != NULL) {
    if (current->value == value)
      return 1;
    current = current->next;
  }
  return 0;
}

/*Pseudocode
  locate(value, struct head pointer) {
    while(head != null) do
      if(head value == value)
        return head
      set head to head next
    end
  }
*/

void *locate(float value, struct Item *head) {

  while (head != NULL) {
    if (head->value == value)
      return head;
    head = head->next;
  }
  return 0;
}

/*Pseudocode
  retrieve(pointer, struct head pointer) {
    while(head != null) do
      if(head == pointer)
        return head value
      set head to head next
    end
  }
*/

float retrieve(void *pointer, struct Item *head) {
  while (head != NULL) {
    if (head == pointer)
      return head->value;
    head = head->next;
  }
  return 0;
}

/*Pseudocode
  insert(struct head pointer, item) {
    if(head == null)
      end
    allocate new_node
    set new_node value to item
    set new_node next to head next
    set head next to new_node
    set new_node prev to head
    if(new_node prev != null)
      set new_node next prev to new_node
    end
  }
*/

void insert(struct Item *head, int item) {
  if (head == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Item *new_node = (struct Item *)malloc(sizeof(struct Item));

  new_node->value = item;

  new_node->next = head->next;

  head->next = new_node;

  new_node->prev = head;

  if (new_node->next != NULL)
    new_node->next->prev = new_node;
}

/*Pseudocode
  printList(struct head pointer) {
    while(head != null) do
      print head value
      set head to next node
    end
  }
*/

int printList(struct Item *head) {
  while (head != NULL) {
    printf("%f\n", head->value);
    head = head->next;
  }
  return 0;
}

/*Pseudocode
  removeItem(struct head, pointer) {
    declare and set temp pointer to head and prev pointer
    if(temp != null and temp == pointer)
      set head pointer to temp next
      free temp
      end
    while(temp != null and temp != pointer) do
      set prev to temp
      set temp to temp next
    if(temp == null)
      end
    set prev next to temp next
    free temp
    end
  }
*/

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

/*Pseudocode
  findMax(struct head) {
    declare max pointer and temp pointer
    set temp to max to head pointer
    while(temp != null) do
      if(temp value > max value)
        set max to temp
      set temp to temp next
    return max value
  }
*/

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

/*Pseudocode
  findMin(struct head) {
    declare struct min pointer and temp pointer
    set temp to min to head pointer
    while(temp != null) do
      if(temp value < min value)
        set min to temp
      set temp to temp next
    return min value
  }
*/

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

/*Pseudocode
  size(struct head pointer) {
    declare and set current pointer to head
    declare and set i to 0
    while(current != null) do
      i++
      set current to current next
    return i
  }
*/

int size(struct Item *head) {
  struct Item *current = head;
  int i = 0;
  while (current != NULL) {
    i++;
    current = current->next;
  }
  return i;
}

/*Pseudocode
  isEmpty(struct head pointer) {
    if(head == null)
      return 1
    return 0
  }
*/

int isEmpty(struct Item *head) {
  return head == NULL;
}

/*Pseudocode
  next(item pointer, struct head pointer) {
    while(head != null) do
      if(head == null)
        return head next value
      set head to head next
    end
  }
*/

float next(void *item, struct Item *head) {
  while (head != NULL) {
    if (head == item)
      return head->next->value;
    head = head->next;
  }
  return 0;
}

/*Pseudocode
  prev(item pointer, struct head pointer) {
    while(head != null) do
      if(head == item)
        return head prev value
      set head to head next
    end
  }
*/

float prev(void *item, struct Item *head) {
  while (head != NULL) {
    if (head == item)
      return head->prev->value;
    head = head->next;
  }
  return 0;
}

/*Pseudocode
  makeNull(struct head pointer) {
    declare struct temp pointer
    while(head != null) do
      set temp to head
      set head to head next
      free temp
    end
  }
*/

void makeNull(struct Item *head) {
  struct Item *temp;

  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
