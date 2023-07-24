#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int age;
    struct NODE *next;
}*node;

node getnode();
node getdetials();
node insrear(node head, int data);

node getnode()
{
    node temp;
    temp=(node)malloc(sizeof(struct NODE));

    if(temp==NULL)
    {
        printf("memory allocation failed\n");
    } 
    temp->next=NULL;
    return temp;

}

node getdetails(int data)
{
    node temp;
    temp=getnode();
    temp->age=data;
    return temp;

}

node insrear(node head, int data)
{
    node temp;
    node ptr=head;
    temp=getdetails(data);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}




void display(node head)
{
    node ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->age);
        ptr=ptr->next;
    }
}

void selection_sort(node head)
{
    node temp;
    node cur;
    cur = head;
    int swap;

    while(cur!=NULL)
    {
        temp=cur->next;
        while(temp!=NULL)
        {
            if(cur->age > temp->age)
            {
            swap=cur->age;
            cur->age=temp->age;
            temp->age=swap;
            }
            temp=temp->next; 
        }
            cur=cur->next;
    }
    
  

}


int main()
{
    node head=NULL;
    FILE *fptr;
    if ((fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\DATA STRUCTURE\\linkList\\randNum.txt","w")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     } 

    //generating random number
    int lowerLimit,upperLimit,n;
    scanf("%d%d%d",&lowerLimit,&upperLimit,&n);
    upperLimit=upperLimit-lowerLimit;

    int rand_num;
    for(int i=0;i<n;i++)
    {
        rand_num=(rand()%upperLimit);
        rand_num=rand_num+lowerLimit;
        fprintf(fptr,"%d\n",rand_num);
    }
    fclose(fptr);

    fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\DATA STRUCTURE\\linkList\\randNum.txt","r");

    int data;
    for(int i=0;i<n;i++)
    {
        fscanf(fptr,"%d",&data);
        head=insrear(head,data);
    }
    fclose(fptr);

    // display(head);

    //fclose(fptr);

    selection_sort(head);

    FILE *fptr_sorted;
    fptr_sorted = fopen("D:\\COLLEGE\\sem-4\\dsa\\DATA STRUCTURE\\linkList\\sorted_output.txt","w");

    node ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        // printf("%d\n",ptr->age);
        fprintf(fptr_sorted,"%d\n",ptr->age);
        ptr=ptr->next;
    }
    
    fclose(fptr_sorted);
    
    return 0;
}
