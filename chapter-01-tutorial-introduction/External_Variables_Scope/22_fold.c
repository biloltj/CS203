#include <stdio.h>

#define MAXLINE 1000
#define FOLD 40

int get_line(char line[], int lim);

int main()
{
    printf("Enter text (press 'q' and Enter to quit):\n");
    char line[MAXLINE];
    int i, last_blank, col, start;

    while (get_line(line, MAXLINE) > 0) {

        if (line[0] == 'q' && line[1] == '\n')
            break;

        start = 0;
        col = 0;
        last_blank = -1;

        for (i = 0; line[i] != '\0'; i++, col++) {
            if (line[i] == ' ' || line[i] == '\t')
                last_blank = i;

            if (line[i] == '\n') {
                putchar('\n');
                col = 0;
                last_blank = -1;
            }

            if (col >= FOLD) {
                int fold_at = (last_blank >= start) ? last_blank : i;
                for (int j = start; j <= fold_at; j++)
                    putchar(line[j]);
                putchar('\n');
                start = fold_at + 1;
                col = i - fold_at;
                last_blank = -1;
            }
        }

        for (int j = start; j < i; j++)
            putchar(line[j]);
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
