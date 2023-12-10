#include <stdio.h>
#include <stdlib.h>
#define MAXQ 20
#define TRUE 1
#define FALSE 0


//STRUCTER OF QUEUE
typedef int QueueElement;

typedef struct
{
    QueueElement items[MAXQ];
    int count;  //number of element in the queue
    int front;
    int rear;
}Queue;

//END OF STRUCTER OF QUEUE

//CREATE QUEUE
void CreateQueue(Queue *q)
{
    q->count= 0;
    q->front = 0;
    q->rear = -1;
    printf("Queue Create Sucessfull\n\n");
}
//END CREATE QUEUE


//IS QUEUE EMPTY
int IsQueueEmpty(Queue*q)
{
    return (q->count == 0);
}

//END //IS QUEUE EMPTY

//IS QUEUE FULL
int IsQueueFull(Queue*q)
{
    return (q->count == MAXQ);
}


//END IS QUEUE FULL



//APPEND QUEUE
void AppendQueue(Queue *q, QueueElement data)
{
    if(IsQueueFull(q))
    {
        printf("Queue is full\n\n");
        exit(1);
    }
    else
    {
        q->rear = (q->rear+1)%MAXQ;
        q->items[q->rear] = data;
        q->count++;
        printf("Append Item %d in the queue.\n\n", data);
    }
}
//END APPEND QUEUE


//SERVE QUEUE
int ServeQueue(Queue *q, Queue *o)
{
    if(IsQueueEmpty(q))
    {
        printf("Nothing have to serve.\n\n");
        exit(1);
    }
    else
    {
        for(int i=0; i<1; i++){
                     o->items[i] = q->items[q->front];
                     printf("Served item is %d \n\n", o->items[i]);

        }
        q->front = (q->front+1)% MAXQ;
        q->count--;
    }
}

//END SERVE QUEUE

int main()
{

    Queue myQueue, outqueue;
    CreateQueue(&myQueue);
    AppendQueue(&myQueue, 45);
    AppendQueue(&myQueue, 55);

    ServeQueue(&myQueue, &outqueue);
    return 0;
}
