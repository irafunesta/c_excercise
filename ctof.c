#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      //Lower limit of temprature scale
    upper = 300;    //upper limit
    step = 20;      //step size

    celsius = lower;
    printf("%10s %s\n", "Celsius", "Fahrenheit");
    while(celsius <= upper) 
    {
        fahr = celsius * 33.8;
        printf("%10.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}