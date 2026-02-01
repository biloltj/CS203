#include <stdio.h>
#include <stdbool.h>
int main(){
char c;

    c = getchar();
    while (c != EOF) 
    {
    printf(" getchar() != EOF: %d\n", c != EOF);
    putchar(c);
    c = getchar();
    
    }
      printf(" getchar() != EOF after EOF: %d\n", getchar() != EOF);
    return 0;
}