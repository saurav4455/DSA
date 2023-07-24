#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,num;
    scanf("%d",&x);
    FILE *fptr;

    if ((fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\fileIO\\randomTextOutput.txt","r")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     } 

    int arr[x];
   
   for(int i=0;i<x;i++)
   {
        
        fscanf(fptr,"%d", &num);
        arr[i]=num;
   }
   printf("\n\n");
   for(int i=0; i<x ;i++)
   {
        printf("%d\t",arr[i]);
   }
   printf("\n\n");


int temp;
   for(int i=0; i<x-1 ;i++)
   {
        for(int j=i; j<x-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
   }

   for(int i=0; i<x ;i++)
   {
        printf("%d\t",arr[i]);
   }

   
   
   fclose(fptr);
}