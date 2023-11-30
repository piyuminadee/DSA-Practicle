#include <stdio.h>
#include <stdlib.h>

//DEFINING QUEUE NODE IN C
  typedef int QueueElement;
  typedef struct node
  {
      QueueElement entry;
      struct node *next;
  }QueueNode;
//END DEFINING QUEUE NODE IN C


////DEFINING QUEUE IN C
typedef struct
{
    QueueNode *front;
    QueueNode *rear;
    int count;
    int full;   //whether queue is full = 1 else full =0

}Queue;
//END DEFINING QUEUE

//CREATE QUEUE
void initializedQueue(Queue *q)
{
    q->count = 0;
    q->full = 0;
    q->front = q->rear = NULL;
    printf("Queue Initialized Successfully\n\n");
}

//END CREATE QUEUE

int IsQueueEmpty(Queue *q)
{
    return(q->count==0);
}

//APPEND QUEUE
void AppendQueue(QueueElement item, Queue *q)
{
    QueueNode *np;
    np = (QueueNode*)malloc(sizeof(QueueNode));
    if(np == NULL){
        printf("Not Enough Memory Space");
        q->full = 1;
    }
    else
    {
        np->entry = item;
        np->next = NULL;
        if(IsQueueEmpty(q))
        {
            q->front = q->rear = np;
            printf("Front address is : %p \n\n", np);
            printf("The front value is %d", item);
            //printf("Rear address is : %p\n\n", np);
            //printf("The next address of rear %p\n\n", np->next);

        }
        else{
            q->rear->next = np;
            q->rear = np;
            printf("The rear entry is now %d\n\n", item);
        }
    }
            q->count++;


}
//END OF APPEND QUEUE


//SERVE QUEUE
void ServeQueue(Queue *q)
{
      QueueNode*np;
      int x = q->front->entry;
      np = q->front;
      q->front = q->front->next;
      printf("The serve entry is %d\n\n",np->entry);
}

//END SERVE QUEUE



int main()
{
    Queue queue;
    initializedQueue(&queue);
    AppendQueue(50, &queue);
    AppendQueue(60, &queue);
    AppendQueue(70, &queue);

    ServeQueue(&queue);

}
