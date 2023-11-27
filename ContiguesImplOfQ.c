#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 20

typedef int QueuElement;
typedef struct queue
{
    QueuElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
}Queue;

//INITIALIZE THE QUEUE
void initializQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    printf("Queue Initialized Successfull...\n\n");
}
//END INITIALIZE THE QUEUE

//IS QUEUE FULL
int IsQueueFull(Queue *q)
{
    return(q->rear ==  MAXQUEUE-1);
}
//END IS QUEUE FULL

//IS QUEUE EMPETY
int IsQueueEmpty(Queue* q)
{
    return(q->front==0 && q->rear==-1);
}
//END IS QUEUE EMPETY

//PUSH ELEMNT INTO STACK
void pushElement(Queue *q, QueuElement entry)
{
   if(IsQueueFull(q))
   {
       printf("Unable to Append, Queue is full\n\n");
   }
   else
   {
      q->items[++(q->rear)] = entry;
      q->count++;
      printf("The Item %d Append The Queue\n\n", entry);
      printf("Now Rear index is = %d\n\n", q->rear);
      printf("Number of Element Append the Queue = %d\n\n", q->count);
   }
}
//END PUSH ELEMNT INTO STACK

void removeEement(Queue *queue, int outq)
{
    if(IsQueueEmpty(queue))
    {
        printf("Queue is Empty\n\n");
    }
    else
    {
        outq = queue->items[queue->front];
        queue->front++;
        queue->count--;
        printf("Serve the Item %d In the Queue\n\n\n", outq);
        printf("Now fron Element value is %d\n\n",queue->front);
        printf("Number of Element in the Queue %d\n\n",queue->count);
    }
}

int main()
{
    Queue queue;
    int outq;
    initializQueue(&queue);
    pushElement(&queue, 30);
    pushElement(&queue, 60);
    removeEement(&queue, outq);

}
