// 

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}*node;

node getnode()
{
    node new;
    new=(node)malloc(sizeof(struct NODE));
    if(new == NULL)
    {
        printf("node is not created\n");
        exit(0);
    }
    printf("Enter the data\n");
    scanf("%d",&new->data);
    new->next=NULL;
}

node insert_rear(node head)
{
    node new,cur;
    if(head==NULL)
    {
        return new;
    }
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=new;
    return head;
}


