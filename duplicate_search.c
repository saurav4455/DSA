#include <stdio.h>
#include <stdlib.h>


int main()
{

    int n,p,q,temp;
    scanf("%d%d%d",&n,&p,&q);
    q=q-p;
    int arr[n];
    FILE *fptr;
    fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\fileIO\\duplicate_search.txt","w");
    if(fptr == NULL)
   {
      printf("File Not created!");   
      exit(1);             
   }
    
     for(int i=0; i<n ;i++)
    {
        temp=(rand()%q);
        temp=temp+p;
        printf("%d\n",temp);
        scanf("%d",&arr[i]);
        fprintf(fptr,"%d ",temp);
    }
    fclose(fptr);

    bubble sort
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\fileIO\\duplicate_search.txt","w");
    int dupli=1,num;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            dupli++;
            num=arr[i];
        }
    }
    
    printf("Number: %d repeted %d times in the array\n",num,dupli);
    fprintf(fptr,"\nNumber: %d repeted %d times in the array\n",num,dupli);
    fclose(fptr);
    return 0;
}
/*
12
45
17
12
25
78
12
*/
