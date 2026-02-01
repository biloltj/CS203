#include <stdio.h>

#define MAX_BUFFER 1000  

int main(void)
{
    printf("Enter text (press q to quit):\n");
    int c;
    int len = 0;        
    int max_len = 0;    
    char line[MAX_BUFFER];   
    char longest[MAX_BUFFER]; 
    int i = 0;          
    while ((c = getchar()) != EOF) {
        if (c == 'q') {
            break;
        }
        if (c != '\n') {
            len++;
          
            if (i < MAX_BUFFER - 1) {
                line[i++] = c;
            }
        } else {
           
            line[i] = '\0'; 
            if (len > max_len) {
                max_len = len;
                int j;
                for (j = 0; j <= i; j++)
                    longest[j] = line[j];
            }
            len = 0;
            i = 0;
        }
    }

    if (len > max_len) {
        max_len = len;
        for (int j = 0; j <= i; j++)
            longest[j] = line[j];
    }

    if (max_len > 0) {
        printf("Longest line length: %d\n", max_len);
        printf("Text (partial if too long):\n%s\n", longest);
    } else {
        printf("No input provided.\n");
    }

    return 0;
}
