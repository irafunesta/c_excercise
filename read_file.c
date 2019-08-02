#include<stdio.h>
#include<string.h>

int main()
{
    char c[15];
    
    for(int i = 0; i<10; i++)
    {
        printf("\n");
    }
    
    scanf("%s", c);
    while(strncmp(c, "exit", 4)) //this is 0 then they are equal so false
    {
        for(int i = 0; i<12; i++)
        {
            printf("\n");
        }
        printf("----------------------\n");
        printf("------------%s---------\n", c);
        printf("----------------------\n");
        for(int i = 0; i<10; i++)
        {
            printf("\n");
        }
        scanf("%s", c);
    }

    printf("Bye\n");
}