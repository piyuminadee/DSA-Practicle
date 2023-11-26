#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef stackEntry;

typedef struct node
{
    stackEntry entry;
    struct node* next;
}Node;

typedef struct
{
    int no_ele;
    int full;
    Node*top;
}Stack;

  //CREATE STACK
void initializedStack(Stack *LS)
{
    LS->no_ele = 0;
    LS->full = FALSE;
    LS->top = NULL;
    printf(".....................Stack Create Successfully...............................\n\n");
}
// END OF CREATE STACK


//PUSH ITEM
void pushStack(Stack *LP,stackEntry item)
{
    Node*nd;
    nd = (Node*)malloc(sizeof(Node));
    if(nd==NULL)       //Whether either can create or not node inside the stack
    {
        printf("Not Memory Allocated");
        LP->full = TRUE;
    }
    else
    {
        nd->entry = item;
        nd->next = LP->top;
        LP->top = nd;
        LP->no_ele++;
        printf("The Item %d Pushed Successfully\n\n", item);
        printf("The Node Address Is %p\n\n", LP->top);
        printf("The Node next address is %p\n\n", nd->next);
    }
}
//END PUSH ITEM

//POP ITEM
int PopStack(Stack *LP, stackEntry *outStack)
{
   Node *np;  // Tempory Variable
   *outStack = LP->top->entry;
   LP->top = LP->top->next;

   printf("Out to the Element %d\n\n", *outStack);
   printf("Now Top most nODE Address is : %p\n\n", LP->top);


}

int main()
{
    Stack myStack, outStack;
    initializedStack(&myStack);  //CREATE STACK

    pushStack(&myStack, 50);    //PUSH STACK
    pushStack(&myStack, 70);


    PopStack(&myStack, &outStack);

    return 0;
}



