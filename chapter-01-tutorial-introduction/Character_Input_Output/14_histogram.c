#include <stdio.h>

#define ASCII_SIZE 128  

int main()
{
    int c, i;
    int freq[ASCII_SIZE]; 

    for (i = 0; i < ASCII_SIZE; ++i)
        freq[i] = 0;

    printf("Enter text (q to stop ):\n");

   
    while ((c = getchar()) != EOF) {
        if (c == 'q') {
            break;
        }
        if (c >= 0 && c < ASCII_SIZE)
            ++freq[c];  

    printf("\nCharacter Frequency Histogram:\n");
    for (i = 0; i < ASCII_SIZE; ++i) {
        if (freq[i] > 0) {
            if (i == '\n')
                printf("\\n: ");
            else if (i == '\t')
                printf("\\t: ");
            else if (i == ' ')
                printf("space: ");
            else
                printf("%c: ", i);

            for (int j = 0; j < freq[i]; ++j)
                putchar('*');
            printf("\n");
        }
    }

    return 0;
}
}
