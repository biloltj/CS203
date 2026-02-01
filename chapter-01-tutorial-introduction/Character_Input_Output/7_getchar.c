#include <stdio.h>

int main()
{
    int c;
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
        break;
    }
    
    printf("\nThe value of EOF is: %d\n", EOF);
    return 0;
}
