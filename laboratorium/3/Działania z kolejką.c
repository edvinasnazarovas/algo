#include <stdio.h>
#include <stdlib.h>

struct Item {
  float value;
  struct Item *next;
};

// void insert(int item, Item end)

// void remove(int pos, Item begin)

int printList(struct Item *head);

void insert(float item, struct Item** end);

void removeItem(int pos, struct Item **head);

void main(void) {
  // realizacja
  // Item begin, end; // Koniec i poczantek

  struct Item *begin = NULL;
  struct Item *end = NULL;

  begin = (struct Item *)malloc(sizeof(struct Item));
  end = (struct Item *)malloc(sizeof(struct Item));

  begin->value = 1;
  begin->next = end;

  end->value = 2;
  end->next = NULL;

  insert(3, &end);
  insert(4, &end);
  insert(5, &end);
  insert(6, &end);
  
  removeItem(0, &begin);

  printList(begin);

  return;
}

// Funkcii

void insert(float item, struct Item** end)
{
    /* 1. allocate node */
    struct Item* new_node = (struct Item*) malloc(sizeof(struct Item));
  
    struct Item *last = *end;  /* used in step 5*/
   
    /* 2. put in the data  */
    new_node->value  = item;
  
    /* 3. This new node is going to be the last node, so make next 
          of it as NULL*/
    new_node->next = NULL;
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*end == NULL)
    {
       *end = new_node;
       return;
    }  
       
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
   
    /* 6. Change the next of last node */
    last->next = new_node;
    return;    
}

void removeItem(int pos, struct Item **head) {
  struct Item *temp = *head, *prev;

  if (temp != NULL && pos == 0) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && pos--) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;

  free(temp);
}

int printList(struct Item *head) {
  while (head != NULL) {
    printf("|%f|  ", head->value);
    head = head->next;
  }
  return 0;
}
