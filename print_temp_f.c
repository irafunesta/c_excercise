#include <stdio.h>

/*
print the table of Fahrenheit-celsius table
from 0 to 300
*/

int main ()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      //Lower limit of temprature scale
    upper = 300;    //upper limit
    step = 20;      //step size
    
    printf("%10s %s\n", "Fahrenheit", "Celsius");
    int i;
    // fahr = upper;
    for (fahr = upper; fahr >= 0; fahr -= step)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%10.0f %6.1f\n", fahr, celsius);
    }
}