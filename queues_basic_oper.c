// liner queue basic operation

#include <stdio.h>
#include <stdlib.h>
#define max 10


typedef struct queue
{
    int arr[max];
    int rear;
    int front;
}queue;

int full(queue q)
{
    if(q.rear==max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty(queue q)
{
    if(q.front==-1 || q.front>q.rear)
    {
        return 1;    
    }
    else
    {
        return 0;
    }
}

void enqueue(queue *q, int num)
{
    if(full(*q))
    {
        printf("queue is full\n");
        return;
    }
    else
    {
        if(q->front==-1)
        {
            q->front++;
        }
        q->rear++;
        q->arr[q->rear]=num;
        return;
    }
}

void dequeue(queue *q)
{
    if(empty(*q))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        q->front++;
        return;
    }
}

void display(queue *q)
{
    if(empty(*q))
    {
        printf("queue is empty\n");
        return;
    }
    else
    {
        int temp=q->front;
        for(;;)
        {
            printf("%d\n",q->arr[temp]);
            temp++;
            if(temp==q->rear+1)
            {
                break;
            }
        }
    }
    
}


int main()
{
    queue q;
    q.front=-1;
    q.rear=-1;
    int choice,num;
    for(;;)
    {
        printf("1.insert\n2.delete\n3.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data to be inserted\n");
                    scanf("%d",&num);
                    enqueue(&q,num);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3: display(&q);
                    break;
            case 0: printf("exited\n");
                    exit(0);
            default : printf("invalid input\n");
                    break;
        }
    }


    return 0;
}