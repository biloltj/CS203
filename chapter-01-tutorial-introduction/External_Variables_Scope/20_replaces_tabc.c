#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int get_line(char line[], int lim);

int main(void)
{
    printf("Enter text (press 'q' and Enter to quit):\n");
    char line[MAXLINE];
    int i, col, spaces;

    while (get_line(line, MAXLINE) > 0) {

        if (line[0] == 'q' && line[1] == '\n')
            break;

        col = 0;

        for (i = 0; line[i] != '\0'; i++) {
            if (line[i] == '\t') {
                spaces = TABSTOP - (col % TABSTOP);
                while (spaces-- > 0) {
                    putchar(' ');
                    col++;
                }
            } else {
                putchar(line[i]);
                if (line[i] == '\n')
                    col = 0;
                else
                    col++;
            }
        }
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 &&
        (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}
