#include <stdio.h>

#define IN 1   
#define OUT 0  

int main()
{
    int c;         
    int nl = 0;     
    int nw = 0;     
    int nc = 0;     
    int state = OUT; 

    printf("Enter text (press 'q' to stop):\n");

    while ((c = getchar()) != EOF) {
        nc++;  

        if (c == '\n')
            nl++;  

        if (c == 'q')  
            break;

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT; 
        } else if (state == OUT) {
            state = IN;  
            nw++;     
        }

        putchar(c); 
    }

    printf("\nLines: %d, Words: %d, Characters: %d\n", nl, nw, nc);

    return 0;
}
