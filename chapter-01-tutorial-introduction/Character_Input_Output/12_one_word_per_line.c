#include <stdio.h>

#define IN 1   
#define OUT 0  

int main(void)
{
    int c;            
    int state = OUT;  

    printf("Enter text (press \'q\' to stop):\n");

    while ((c = getchar()) != EOF) {
        if (c == 'q') {
            break;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar(c);      
            state = IN;     
        }
    }

    if (state == IN)
        putchar('\n');

    return 0;
}
