#include <stdio.h>

int main(void)
{
    int c;
        printf("Enter text (press 'q' to stop):\n");
    
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            printf("\\n\n"); 
        if (c == '\t')
            printf("\\t");   
        else if (c == '\b')
            printf("\\b");   
        else if (c == '\\')
            printf("\\\\");  
        else if( c == ' ')
            printf("space");
        else if (c == 'q')
            break;    
        
        putchar(c);
    }

    return 0;
}
