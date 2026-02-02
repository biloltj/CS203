#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE];
    printf("Enter text (press 'q' and Enter to quit):\n");

    while (get_line(line, MAXLINE) > 0) {

        if (line[0] == 'q' && line[1] == '\n')
            break;

        reverse(line);
        printf("%s", line);
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

void reverse(char s[])
{
    int i, j;
    char temp;

    for (j = 0; s[j] != '\0'; j++)
        ;

    j--;

    for (i = 0; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
