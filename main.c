#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 5
#define TRUE 1
#define FALSE 0

//Stack Definition in C

typedef int stackEntry;

typedef struct{
     int top;
     stackEntry entry[MAXSTACK];
}Stack;

void creatStack(Stack*s);
int isStackEmpty(Stack*s)
//Implementing Stack Operation
//CreteStack

void creatStack(Stack*s)
{

    s->top = -1;   //eg: ptr->rollno = 43;
    //Assign the value -1 into top
    printf("%d\n",s->top);
    printf("StackCreated\n");
}

//main function
Stack s;
int main()
{
    Stack*s;
    int item[5], oitem[5], i, j;
    creatStack(&s);
}

//Implementing Stack Operations
//IsStackEmpty
int isStackEmpty(Stack*s)
{

    if(s->top==1)
        return(TRUE);
    else return(FALSE);
}

//IsStackFull

int IsStackFull(Stack*s){
if(s->top==MAXSTACK-1)
    return(TRUE);
 else return(FALSE);

}

//PUSH
void push(stackEntry, Stack*s)
{

    if(!IsStackFull(s))
    {
        s->top++;
        s->entry[++s->top]=item;
        printf("Item %d pushed into stack\n", item);
    }
    else{
        printf("--Stack is Full!!--");
        exit(1);
    }
}

void pop(stackEntry*item, Stack*s)
{
    if(!isStackEmpty(s))
    {
        *item = s->entry[s->top--];

        printf("Item %d popped out \n", *item);
    }
    else{
        printf("--Stack is Empty!!--");
        exit(1);
    }

}



