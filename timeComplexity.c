// random number generation and put it into text file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int arr[], int n)
{
    int i, j,temp;
    for(i=0; i<n-1 ;i++)
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
}


int main()
{
    int lowerLimit,upperLimit,n;
    FILE *fptr;
    FILE *fptrLog;
    
    if ((fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\timeComplexityLog\\randomTextOutput.txt","w")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     } 
  
    //generating random number
    scanf("%d%d%d",&lowerLimit,&upperLimit,&n);
    upperLimit=upperLimit-lowerLimit;

     
    for(int i=0;i<n;i++)
    {
        rand_num=(rand()%upperLimit);
        rand_num=rand_num+lowerLimit;
        fprintf(fptr,"%d\n",rand_num);
    }

    fclose(fptr);

    fptr = fopen("D:\\COLLEGE\\sem-4\\dsa\\timeComplexityLog\\randomTextOutput.txt","r");

    int arr[100]; //maximum number it can sort is upto 100
    int temp; // to store the num from the file and the dump it to array
    for(int i=0;i<n;i++)
    {
        fscanf(fptr,"%d",&temp);  
        arr[i]=temp;
    }

    fclose(fptr);


    //sorting starts form here

    //bubble sort
    // fptrLog = fopen("D:\\COLLEGE\\sem-4\\dsa\\timeComplexityLog\\logFile.txt","w");
    clock_t t;
	  t = clock();
      bubbleSort(arr,n);

      t = clock() - t;
	  double time_taken = ((double)t)/CLOCKS_PER_SEC;
    //   printf("it took %f seconds to execute \n", time_taken);
    fprintf(fptrLog,"bubble sort: %f seconds to execute \n", time_taken);
    fclose(fptrLog);


    

    
    return 0;
}



