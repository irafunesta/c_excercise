#include<stdio.h>

/*
    K&R Ex.1-13 v2
    Write a program to print a histogram of the lengths of words in its input. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging

1 ###
2 ##
4 #######
  1234567

histogram goes from 0 - (MAX_LENGHT - 1)
so 0-5 six slots, but the 0 is not used so there are 5 slot
if a word is of lenght 6 it need to go in the last one
so 5 = MAX_LENGHT

need to use the 0 slot to save words of lenght 1

so if word_lenght = 1 -> 0
so if word_lenght = 2 -> 1
so if word_lenght = 3 -> 2
so if word_lenght = n -> n - 1

then 
0 -> 1
1 -> 2
2 -> 3
3 -> 4
4 -> 5
5 -> >5
 */

#define MAX_LENGTH 15

int main()
{
    int histogram[MAX_LENGTH + 1]; //histogram 0-10 are words of lenght 0-10
    int c, in_words, word_length, max_lenght, words_num;
    in_words = word_length = max_lenght = words_num = 0;

    for(int j = 0; j<=MAX_LENGTH + 1; ++j)
    {
        histogram[j]=0;
    }

    while((c = getchar()) != EOF)
    {
        if(c != ' ' && c != '\t' && c != '\n')
        {
            ++word_length;
            in_words = 1;
        }
        else
        {
            if(word_length > MAX_LENGTH)
            {
                word_length = MAX_LENGTH + 1; //Lenght 6 to go on slot 5
            }

            if(in_words == 1)
            {
                //Save in istogram
                ++histogram[word_length - 1];
                if(histogram[word_length - 1] > max_lenght)
                {
                    max_lenght = histogram[word_length - 1];
                }
                word_length = in_words = 0;
                ++words_num;
            }
        }
    }

    printf("----------------------------\n");

    for(int i=0; i <= MAX_LENGTH; ++i)
    {
        //Print histogram bars
        if(i == MAX_LENGTH)
        {
            printf("%2d+ ", MAX_LENGTH); // Number
        }
        else
        {
            printf("%3d ", i + 1); // Number
        }
        
        for(int j = 0; j<histogram[i]; ++j)
        {
            printf("#");
        }
        printf("\n");
    }

    printf("  x ");

    for(int j = 1; j <= max_lenght; ++j)
    {
        printf("%d", j);
    }
    printf("\n");
    printf("----------------------------\n");
    printf("total words:%d\n", words_num);
}