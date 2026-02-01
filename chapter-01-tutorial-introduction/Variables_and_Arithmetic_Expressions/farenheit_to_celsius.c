#include <stdio.h>
int main()
{
    printf("Celsius to Farenheit Converter\n");
    printf("_______________________________\n");
    printf("Farenheit\tCelsius\n");

    float celsius,farenheit;
    int lower,upper,step;
    
    lower=0;
    upper=300;
    step=20;

    farenheit = 0;
    while(farenheit <= upper)
    {
        celsius = (farenheit - 32)/1.8;
        printf("%f F\t%f C\n",farenheit,celsius);
        farenheit = farenheit + step;
    }
    return 0;
    
}