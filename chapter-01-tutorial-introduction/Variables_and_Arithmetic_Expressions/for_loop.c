#include <stdio.h>
int main()
{
    printf("Farenheit-Celsius Table\n");
    printf("_______________________________\n");
    printf(" F\t C\n");

    int farenheit;

    

    for  (farenheit = 0; farenheit <= 300; farenheit += 20)
    {
        printf("%3d\t%6.1f\n",farenheit, (farenheit-32)*5.0/9.0);
    }
    return 0;
}