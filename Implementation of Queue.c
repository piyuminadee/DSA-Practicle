#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 20
#define TRUE 1
#define FALSE 0

typedef int QueueElement;

typedef struct queue
{
    QueueElement item[MAXQUEUE];
    int front;
    int rear;
    int count;
}Queue;
void createQueue(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q,QueueElement item);
void dequeue(Queue *q,QueueElement *item);

int isQueueFull(Queue *q)
{
    if(q->rear==MAXQUEUE-1)
        return (TRUE);
    else return FALSE;
}

int isQueueEmpty(Queue *q)
{
    if(q->rear < q->front)
      return (TRUE);
    else return FALSE;
}

void enqueue(Queue *q,QueueElement item)
{
    if(isQueueFull(q))
    {
        printf("Queue Full\n");
        exit(1);
    }
    else
    {
        q->item[++(q->rear)] = item;
        q->count++;
        printf("%d", item);
        printf("Enqueue is successfully\n");
    }
}

void dequeue(Queue *q,QueueElement *item){
  if(isQueueEmpty(q))
  {
    printf("\nQueue is Empty");
    exit(1);
  }
  else
  {
      *item = q->item[(q->front)++];
      q->count--;
      printf("\n%d", *item);
      printf("\nDequeue is successfully\n");
  }
}

void createQueue(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = -1;
    printf("--Queue create sucessfully--");
}

int main()
{
    Queue myqueue;
    Queue outQueue;

    createQueue(&myqueue);

    enqueue(&myqueue, 45);
    dequeue(&myqueue, &outQueue);

}
