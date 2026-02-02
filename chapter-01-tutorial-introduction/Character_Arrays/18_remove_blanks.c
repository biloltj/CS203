#include <stdio.h>

#define MAXLINE 1000   

int get_line(char line[], int lim);
int trim(char line[]);

int main(void)
{
    char line[MAXLINE];

    printf("Enter text (press 'q' and Enter to quit):\n");

    while (get_line(line, MAXLINE) > 0) {

      
        if (line[0] == 'q' && line[1] == '\n')
            break;

        if (trim(line) > 0) {    
            printf("%s\n", line);
        }
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 &&
        (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}

int trim(char line[])
{
    int i = 0;

    while (line[i] != '\0')
        i++;

    while (i > 0 &&
          (line[i-1] == ' ' || line[i-1] == '\t' || line[i-1] == '\n'))
        i--;

    line[i] = '\0';   
    return i;
}
