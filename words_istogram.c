#include<stdio.h>

/*
    K&R Ex.1-13
    Write a program to print a histogram of the lengths of words in its input. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging

1 ###
2 ##
4 #######
  1234567

 */

#define MAX_LENGTH 10

int main()
{
    int histogram[MAX_LENGTH]; //histogram 0-10 are words of lenght 0-10
    int c, in_words, word_length, max_lenght, words_num;

    in_words = word_length = max_lenght = words_num = 0;

    for(int j = 0; j<MAX_LENGTH; ++j)
    {
        histogram[j]=0;
    }

    while((c = getchar()) != EOF)
    {        
        if(c == ' ' || c == '\t' || c == '\n') // i have reached a special char, the word end
        {
            if(in_words == 1)
            {
                ++histogram[word_length];
                if(histogram[word_length] > max_lenght && histogram[word_length] < MAX_LENGTH)
                {
                    max_lenght = word_length;
                }
                word_length = 0;
                in_words = 0;
            }
        }    
        else // c is a char
        {
            if(in_words == 0)
            {
                ++words_num;
                in_words = 1;
            }
            ++word_length;
        }
    }
    if(in_words == 1)
    {
        ++histogram[word_length];
        word_length = 0;
        in_words = 0;
    }

    printf("----------------------------\n");

    for(int i=1; i< MAX_LENGTH; ++i)
    {
        //Print histogram bars
        printf("%d ", i); // Number
        for(int j = 0; j<histogram[i]; ++j)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("x ");
    for(int j = 1; j < max_lenght; ++j)
    {
        printf("%d", j);
    }
    printf("\n");
    printf("----------------------------\n");
    printf("total words:%d\n", words_num);
}