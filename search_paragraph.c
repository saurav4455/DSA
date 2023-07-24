#include <stdio.h>

void read(char str[10][100])
{
    for(int i=0; i<10 ; i++)
    {
        gets(str[i]);
    }
}


int checkPattern(char str[10][100],char key[10])
{
    int checkFlag=0,keyLetter=0,j;
   for(int i=0; i<10 ; i++)
    {
        j=0;
        while(str[i][j]!='\0')
        {
            if(str[i][j]==key[keyLetter])
            {
                j++;
                keyLetter++;
            }
            if(key[keyLetter]=='\0')
            {
                printf("%s\n",str[i]);
                keyLetter=0;
                break;
            }

            if(str[i][j]!=key[keyLetter])
            {
                j++;
                keyLetter=0;
            }

        }
    } 
    
    
}



int main()
{
    char str[10][100];
    read(str);
    char key[10];
    gets(key);
    checkPattern(str,key);

    return 0;
}
/*
The morning sun peeked through the window, casting a warm glow on the room.
The smell of freshly brewed coffee filled the air, awakening my senses.
The sound of laughter echoed in the park, as children played and ran around.
The waves crashed against the shore, creating a calming melody.
The vibrant colors of the sunset painted the sky, leaving me in awe.
The leaves rustled under my feet, as I walked through the forest.
The gentle breeze blew through my hair, as I sat on the porch swing.
The aroma of baking bread wafted from the kitchen, making my mouth water.
The distant sound of thunder warned of an impending storm.
The silence of the night was broken by the chirping of crickets.
*/