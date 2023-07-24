// #include <stdio.h>

// void read(int mat[5][5], int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             scanf("%d",&mat[i][j]);
//         }
//     }
// }

// void display(int mat[5][5], int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             printf("%d ",mat[i][j]);
//         }
//         printf("\n");
//     }
// }

// void multi(int mat1[5][5], int mat2[5][5], int resultMat[5][5], int n)
// {
//     int sum=0,temp;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             for(int k=0;k<n;k++)
//             {
                
//             }

//         }

//     }
//     printf("\n\n");

// }

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int mat1[n][n],mat2[n][n];
//     read(mat1,n);
//     read(mat2,n);
//     int resultMat[n][n];
//     multi(mat1,mat2,resultMat,n);
    
    


//     display(mat1,n);
//     printf("\n\n");
//     display(mat2,n);



// }




#include<stdio.h>

void input(int a[100][100],int m,int n);
void output(int a[100][100],int m,int n);
void mul(int a[100][100],int b[100][100],int m,int n,int l,int o);

int main()
{
    int a1[100][100],b1[100][100];
int a[100][100],b[100][100],m ,n,l,o;

printf("Enter number of row and column size for mat 1\n");
scanf("%d\n%d",&m,&n);

printf("Enter number of row and column size for mat 2\n");
scanf("%d\n%d",&l,&o);

printf("mat1\n");
input(a,m,n);
printf("mat2\n");
input(b,l,o);
printf("mat1\n");
output(a,m,n);
    printf("\t\t\n");
    printf("mat2\n");
     output(b,l,o);
    printf("\t\t\n");
mul(a,b,m,n,l,o);
}

void input(int a[100][100],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void output(int a[100][100],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {

            printf("%d\t",a[i][j]);
    }
    printf("\n");
}
}

void mul(int a[100][100],int b[100][100],int m,int n,int l,int o)
{
    int i,j,k,sum,res[100][100];

    for(i=0;i<m;i++)
    {
        for(j=0;j<o;j++)
        {
            sum=0;
            for(k=0;k<l;k++)
            {
                sum=sum+(*(*(a+i)+k))*(*(*(b+k)+j));
            }

            *(*(res+i)+j) = sum;
        }
    }
   output(res,m,n);
}
