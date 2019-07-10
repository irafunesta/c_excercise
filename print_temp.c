#include <stdio.h>

/*
print the table of Fahrenheit-celsius table
from 0 to 300
*/

int main ()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      //Lower limit of temprature scale
    upper = 300;    //upper limit
    step = 20;      //step size

    fahr = lower;
    while(fahr <= upper) 
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d %5d\n", fahr, celsius);
        fahr = fahr + step;
    }
}