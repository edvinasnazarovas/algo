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

  printf("Next: %f\n", next(p2, head));

  printf("Prev: %f\n", prev(p2, head));

  removeItem(&head, p);

  printf("\n\n-------Print List--------\n");
  printList(&head);
  printf("--------------------\n\n");

  return 0;
}

//Funkcii

/* Pseudocode
  clearVisits(structure head){
    set structure temp pointer to head pointer
  
    while(temp != null and temp->visited == 1) do
      set visited member in temp to 0
      set temp to the next node
  end
  }
  */
void clearVisits(struct Item **head){
  struct Item *temp = *head;

  while(temp != NULL && temp->visited == 1) {
    temp->visited = 0;
    temp = temp->next;
    }
  return;
}
/*Pseudocode
  find(value, structure head){
    set current pointer to head

    while(current != null and current->visited != 1) do
      set visited member in current to 1

      if(value member in current == value)
        clear all visits in nodes
        return 1

      set current to the next node
  clear all visits in nodes
  end
  }
*/
    
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

/*Pseudocode
  locate(value, structure head){
    while(head != null and visited member in head != 1) do
      set visited member in head to 1

      if(value member in head == value)
        clear all visits in nodes
        return head

      set head to the next node
    clear all visits in nodes
    end
  }
*/

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

/* Pseudocode
  retrieve(pointer, structure head) {
    clear all visits in nodes
  
    while(head != null and visited member in head != 1) do
      set visited member in head to 1

      if(head == pointer)
        clear all visits in nodes
        return value member in head

      set head to the next node

    clear all visits in nodes
    end
  }
*/

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

/*Pseudocode
  insert(position pointer, value, next pointer){
    if(position pointer == null)
      print "the previous node cannot be NULL"
      end

    allocate new structure called new_node
    set value member in new_node to value
    set new_node next node pointer to position pointer next node pointer
    set position pointer next node pointer to new_node
    set new_node previous node pointer to position pointer

    if(new_node next node pointer != null)
      set new_node next node previous node pointer to new_node
    elseif(new_node next node pointer == null)
      set new_node next node pointer to next pointer
  end
  }
*/

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

/* Pseudocode
  printList(structure head){
    set struct temp pointer to head pointer
    while(temp!=null and visited member in temp != 1)
      print value member in temp
      set visited member in temp to 1
      set temp to next node
    clear all visits in nodes
    end
  }
*/

int printList(struct Item **head) {
  struct Item *temp = *head;
  while (temp != NULL && temp->visited != 1) {
    printf("%f\n", temp->value);
    temp->visited = 1;
    temp = temp->next;
  }
  printf("Cycle detected\n");
  clearVisits(head);
  return 0;
}

/*Pseudocode
  removeItem(struct head, pointer){
    set struct temp pointer to head pointer and prev pointer
    clear all visits in nodes
    if(temp != null and temp == pointer)
      set head pointer to next member in temp
      free temp
      end
    while(temp != null and temp != pointer and visited member in temp != 1) do
      set visited member in temp to 1
      set prev to temp
      set temp to next node
    if(temp == null)
      clear all visits in nodes
      end
    set next member in prev to to next member in temp
    clear all visits in nodes
    free temp
  }
*/

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

/*Pseudocode
  findMax(structure head){
    declare struct max pointer and temp pointer
    set temp to max to head pointer
    clear all visits in nodes
    while(temp != null and visited member in temp != 1) do
      if(value member in temp > value member in max)
        set max to temp
      set visited member in temp to 1
      set temp to next member in temp
    clear all visits in nodes
    return max value
  }
*/
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

/*Pseudocode
  findMin(struct head){
    declare struct min pointer and temp pointer
    set temp to min to head pointer
    clear all visits in nodes
    while(temp != null and temp visited != 1) do
      if(temp value < min value)
        set min to temp
      set temp visited to 1
      set temp to next node
    clear all visits in nodes
    return min value
  }
*/

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

/*Pseudocode
  size(struct head){
  declare struct current pointer and set to head
  declare and set i to 0
  while(current != null and current visited != 1) do
    i++
    set current visited to 1
    set current to next node
  clear all visits in nodes
  return i
  }
*/

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

/*Pseudocode
  isEmpty(struct head) {
    if(head == null)
      return 1
    return 0    
  }
*/

int isEmpty(struct Item *head) {
  return head == NULL;
}

/*Pseudocode
  next(item pointer, struct head) {
    clear all visits in nodes
    while(head != null and head visited != 1) do
      if(head == item)
        clear all visits in nodes
        return head next value
      set head to head next
    clear all visits in nodes
    end
  }
*/

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

/*Pseudocode
  prev(item pointer, struct head pointer){
    clear all visits in nodes
    while(head != null and head visited != 1) do
      if(head == item)
        clear all visits in nodes
        return head prev value
    end
  }
*/

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
