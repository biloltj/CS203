#include <stdio.h>

#define MAXLINE 1000
#define THRESHOLD 80

int getline_custom(char line[], int maxline);

int main(void)
{
    printf("Enter text (press q to quit):\n");  
    int len;
    char line[MAXLINE];

    while ((len = getline_custom(line, MAXLINE)) > 0)
        if (len > THRESHOLD)
            printf("%s", line);

    return 0;
}

int getline_custom(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    while (c != '\n' && c != EOF)
        
        c = getchar();
    return i;
}
