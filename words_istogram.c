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
    int c, in_words, word_length, max_lenght, words_num;

    in_words = word_length = max_lenght = words_num = 0;

    for(int j = 0; j<10; ++j)
    {
        histogram[j]=0;
    }

    while((c = getchar()) != EOF)
    {
        // printf("---------------------------\n");
        // printf("c:%c\n", c);
        // printf("in_words:%d\n", in_words);
        // printf("word_length:%d\n", word_length);
        
        if(c == ' ' || c == '\t' || c == '\n') // i have reached a special char, the word end
        {
            if(in_words == 1)
            {
                ++histogram[word_length];
                if(histogram[word_length] > max_lenght && histogram[word_length] < 10)
                {
                    max_lenght = word_length;
                }
                word_length = 0;
                in_words = 0;
            }
        }    
        else // c is a char
        {
            // printf("normal char\n");
            if(in_words == 0)
            {
                // printf("next word\n");
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

    for(int i=1; i< 10; ++i)
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
    printf("w:%d\n", words_num);
}