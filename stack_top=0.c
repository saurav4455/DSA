#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack[size],top=0;

void push(int value)
{
    if(top==size)
    {
        printf("stack is full");
    }
    else
    {
        stack[top]=value;
        top++;
    }
}
int pop()
{
    int num;
    if(top==0)
    {
        return 0;
    }
    else
    {
        top--;
        num=stack[top];
    }
    return num;
}
int display()
{
    if(top==0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(int i=0;i<top;i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int i;
    FILE*fptr;
    if ((fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\DATA STRUCTURE\\FILES\\randNum.txt","w")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     } 

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
    
    int choice,num;
    fopen("D:\\COLLEGE\\sem-4\\dsa\\DATA STRUCTURE\\FILES\\randNum.txt","r");
    
    while(1)
    {
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            fscanf(fptr,"%d",&num);
            push(num);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        }
    }
    fclose(fptr);
}