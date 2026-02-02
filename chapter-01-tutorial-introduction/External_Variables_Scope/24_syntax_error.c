#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim);

int main(void)
{
    printf("Enter text (press 'q' and Enter to quit):\n");
    printf("This program checks for syntax errors in C code.\n");
    char line[MAXLINE];
    int i, par=0, brace=0, bracket=0, state=0;

    while (get_line(line, MAXLINE) > 0) {

        if (line[0] == 'q' && line[1] == '\n')
            break;

        for (i = 0; line[i] != '\0'; i++) {
            if (state == 0) {
                if (line[i] == '"' || line[i] == '\'') {
                    char quote = line[i];
                    i++;
                    while (line[i] != '\0' && line[i] != quote) {
                        if (line[i] == '\\' && line[i+1] != '\0')
                            i++;
                        i++;
                    }
                } else if (line[i] == '/' && line[i+1] == '*') {
                    state = 1;
                    i++;
                } else if (line[i] == '/' && line[i+1] == '/') {
                    break;
                } else if (line[i] == '(') par++;
                else if (line[i] == ')') par--;
                else if (line[i] == '{') brace++;
                else if (line[i] == '}') brace--;
                else if (line[i] == '[') bracket++;
                else if (line[i] == ']') bracket--;
            } else if (state == 1) {
                if (line[i] == '*' && line[i+1] == '/') {
                    state = 0;
                    i++;
                }
            }
        }
    }

    if (par != 0) printf("Unmatched parentheses: %d\n", par);
    if (brace != 0) printf("Unmatched braces: %d\n", brace);
    if (bracket != 0) printf("Unmatched brackets: %d\n", bracket);

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
