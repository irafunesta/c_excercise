#include<stdio.h>

/*
    Write a program to print a histogram of the lengths of words in its input. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging

1 ###
2 ##
4 #######
  1234567

 */

int main()
{
    int histogram[10]; //histogram 0-10 are words of lenght 0-10
    int c;

    int in_words = 1;
    int word_length = 0;
    int max_lenght = 0;

    for(int j = 0; j<10; ++j)
    {
        histogram[j]=0;
    }

    while((c = getchar()) != EOF)
    {
        if(c != ' ' || c != '\t' || c != '\n')
        {
            ++word_length;
            if(word_length > max_lenght && word_length <= 10)
            {
                max_lenght = word_length;
            }
        }        
        else
        {
            //Out of words
            if(word_length < 10)
            {
                ++histogram[word_length];
            }            
        }
    }

    for(int i=0; i< 10; ++i)
    {
        //Print histogram bars
        printf("%d ", i); // Number
        for(int j = 0; j<histogram[i]; ++j)
        {
            printf("#");
        }
        //End line
        printf("\n");
    }
    for(int j = 0; j<max_lenght; ++j)
    {
        printf("%d", j);
    }
    printf("\n");
}