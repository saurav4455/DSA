#include <stdio.h>

void read(char str[10][100])
{
    for(int i=0; i<3 ; i++)
    {
        gets(str[i]);
    }
}


int checkLen(char str[10][100])
{
    int maxLen,count=0;
   for(int i=0; i<3 ; i++)
    {
        for(int j=0; str[i][j]!='\0'; j++)
        {
            count++;   
        }
        if(count>maxLen)
        {
            maxLen=count;
        }
        count=0;
    } 
    printf("%d",maxLen);
    return maxLen;
}



int main()
{
    char str[10][100];
    read(str);
    int maxLen;
    maxLen=checkLen(str);
    //printf("(%d)",maxLen);
    return 0;
}