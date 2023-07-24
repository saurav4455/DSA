#include <stdio.h>
#include <stdlib.h>

void read(int arr[10][10], int m, int n)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n ;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

void display(int arr[10][10], int m, int n)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n ;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    int m,n;
    printf("Enter number of row and column for the matrix\n");
    scanf("%d",&m);
    scanf("%d",&n);
    
    printf("Enter the elements of the matrix\n");
    int arr[m][n];
    read(arr,m,n);
    display(arr,m,n);


    if(m!=n)
    {
        printf("The matrix is not symmetric\n");
    }
    else
    {
        int i,j,flag=1;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n ;j++)
            {
                if(arr[i][j]!=arr[j][i])
                {
                    flag=0;
                }
            }
        }  
        if(flag==0)
        {
            printf("The matrix is not symmetric\n");
        }
        else
        {
            printf("The matrix is a symmetric\n");
        }
    }


    return 0;
}

