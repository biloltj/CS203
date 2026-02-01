#include <stdio.h>

#define MAX_WORD_LEN 20  

int main(void)
{
    int c, i, state, word_len;
    int word_count[MAX_WORD_LEN + 1]; 
    for (i = 0; i <= MAX_WORD_LEN; ++i)
        word_count[i] = 0;

    state = 0;      
    word_len = 0;  

    printf("Enter text (\'q\' to stop ):\n");

    while ((c = getchar()) != EOF) {
        if (c == 'q') {
            break;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == 1) {        
                if (word_len > MAX_WORD_LEN)
                    word_len = MAX_WORD_LEN; 
                ++word_count[word_len];      
                word_len = 0;
            }
            state = 0; 
        } else {
            state = 1;  
            ++word_len;  
        }
    }

    if (state == 1) {
        if (word_len > MAX_WORD_LEN)
            word_len = MAX_WORD_LEN;
        ++word_count[word_len];
    }

    printf("\nWord Length Histogram:\n");
    for (i = 1; i <= MAX_WORD_LEN; ++i) {
        if (word_count[i] > 0) {
            printf("%2d: ", i);
            for (int j = 0; j < word_count[i]; ++j)
                putchar('*');
            printf("\n");
        }
    }

    return 0;
}
