#include <stdio.h>
int main()
{
    printf("Celsius to Farenheit Converter\n");
    printf("_______________________________\n");
    printf("Celsius\t Farenheit\n");

    int celsius,farenheit;
    int lower,upper,step;
    
    lower=0;
    upper=300;
    step=20;

    celsius = 0;
    while(celsius <= upper)
    {
        farenheit = (celsius * 1.8) + 32;
        printf("%d C\t%d F\n",celsius,farenheit);
        celsius = celsius + step;
    }
    return 0;


}