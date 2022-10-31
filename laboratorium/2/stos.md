# Stos
## Działania z stosem
- Wyśwetlień elementa ze góry stosu.
- Wyberanie elementa ze stosa
- Wyczyść
- Dodaj element do góry stosu.
- Sprawdż czy pusty

### Program w C
```C
struct Item {
        float value;
        struct Item *next;
    };

    /*void top(float value, Item *s)

    void makeNull(Item *s)

    void pop(Item *s)

    void push(float value, Item *s)

    void isEmpty(Item *s)*/

    #include <stdio.h>

  struct Item* newNode(float value){
    struct Item* stackNode = 
      (struct Item*)
      malloc(sizeof(struct Item));
    stackNode->value = value;
    stackNode->next = NULL;
    return stackNode;
  }

int isEmpty(struct Item* root)
{
    return !root;
}

void push(struct Item** root, int data)
{
    struct Item* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct Item** root)
{
    if (isEmpty(*root))
        return -32768;
    struct Item* temp = *root;
    *root = (*root)->next;
    int popped = temp->value;
    free(temp);
  
    return popped;
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
      struct Item* root = NULL;
  
  
      return;
    }
```
https://replit.com/@EdvinasNazarova/Stos#main.c
