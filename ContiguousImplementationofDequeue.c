#include <stdio.h>
#include <stdlib.h>
#define MAXQ 20
#define TRUE 1
#define FALSE 0

typedef int deQueueElement;

typedef struct dequeue
{
    deQueueElement items[MAXQ];
    int front;
    int rear;
    int count;
}deQueue;


//CREATE QUEUE
void creteQueue(deQueue *d)
{
    d->count = 0;
    d->rear = -1;
    d->front = 0;
    printf("Queue Create Successfully\n\n");
}
//END CREATE QUEUE

//CHECK  WHETHER QUEUE IS EMPTY
int IsDequeueEmpty(deQueue*d)
{
    return (d->count == 0);
}

//END CHECK  WHETHER QUEUE IS EMPTY


//CHECK  WHETHER QUEUE IS Full
int IsDqueueFull(deQueue*d)
{
    return (d->count == MAXQ-1);
}

//END CHECK  WHETHER QUEUE IS FULL

//APPEND FRONT
void AppendQueueFront(deQueue *d, deQueueElement x)
{
    if(IsDqueueFull(d))
    {
        printf("Queue Full\n\n");
        exit(1);
    }
    else if(IsDequeueEmpty(d))
    {
        printf("You append item first\n");
        d->items[d->front] = x;
        d->rear++;
    }
    else
    {
        if(d->front==0)
        {
          for(int i = d->rear; i>=d->front; i--)
          {
              d->items[i+1] = d->items[i];
          }
          d->rear++;
          d->items[d->front]  = x;
        }
        else
        {
            d->items[--(d->front)]= x;

        }
    }
    printf("Append Item %d into Front\n\n", x);
    printf("Front Index is %d\n\n", d->front);
    printf("Rear index is %d\n\n", d->rear);
    d->count++;
    //printf("Number of items in the Queue %d\n\n", d->count);
}

//END APPEND FRONT


//APPEND REAR
void AppendQueueRear(deQueue *d, deQueueElement x)
{
  if(IsDqueueFull(d))
  {
      printf("Dequeue is Full\n\n");
      exit(1);
  }
  else
    {
      d->items[++(d->rear)] = x;
      d->count++;
    }
    printf("Append Item %d into Rear\n\n", x);
    printf("Front Index is %d\n\n", d->front);
    printf("Rear index is %d\n\n", d->rear);

}

//END APPEND REAR


//SERVE QUEUE FRONT
void ServeQueueFront(deQueue *d, deQueueElement out)
{
    if(IsDequeueEmpty(d))
    {
        printf("Nothing to Serve\n\n");
        exit(1);
    }
    else
    {
        out = d->items[(d->front)++];
        d->count--;
        printf("Serve Item %d into Front\n\n", out);
    }
}
//END SERVE QUEUE FRONT


//SERVE QUEUE REAR

void ServeQueueRear(deQueue *d, deQueueElement out)
{
    if(IsDequeueEmpty(d))
    {
        printf("Nothing to Serve\n\n");
        exit(1);
    }
    else
    {
       out = d->items[(d->rear)--];
       d->count--;
    }
            printf("Serve Item %d into rear\n\n", out);

}
//END SERVE QUEUE REAR



int main()
{
    deQueue myQueue;
    int out;
    creteQueue(&myQueue);

    AppendQueueFront(&myQueue, 39);
    AppendQueueFront(&myQueue, 59);

    AppendQueueFront(&myQueue, 35);
    AppendQueueRear(&myQueue, 22);


    ServeQueueFront(&myQueue, out);
    ServeQueueRear(&myQueue, out);




    return 0;
}
