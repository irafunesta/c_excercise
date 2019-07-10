#include <stdio.h>

/*
print the table of Fahrenheit-celsius table
from 0 to 300
*/
#define LOWER 0
#define UPPER 300
#define STEP 20

int main ()
{
    float fahr;
    
    printf("%10s %s\n", "Fahrenheit", "Celsius");
    // fahr = upper;
    for (fahr = UPPER; fahr >= 0; fahr = fahr - STEP)
    {
        printf("%10.0f %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
    }
}