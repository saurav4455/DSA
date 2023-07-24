#include <stdio.h>

#include <stdlib.h>
int main()
{
    int n,p,q,temp;
    scanf("%d%d%d",&n,&p,&q);
    q=q-p;

   

    FILE *fptr;
    fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\fileIO\\randomTextOutput.txt","w");
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
        fprintf(fptr,"%d ",temp);
    }
    fclose(fptr);

   

}





