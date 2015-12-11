#include <math.h>
#include <stdio.h>

int main (int argc, const char * argv[])
{

    float fahr,
          cels;

    printf("Please input the temperature you want to convert from Fahrenheit to Celsius: ");
    scanf("%g", &fahr);
    cels = ((fahr - 32) / 1.8);
    printf("Your result is: %g\n\n", cels);

    printf("Please input the temperature you want to convert from Celsius to Fahrenheit: ");
    scanf("%g", &cels);
    fahr = ((cels * 9/5) +32);
    printf("Your result is: %g\n\n", fahr);

    return 0;

}
