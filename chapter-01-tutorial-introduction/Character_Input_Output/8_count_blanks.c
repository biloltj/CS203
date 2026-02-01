#include <stdio.h>

int main()
{
    int c;
    int blanks = 0, tabs = 0, newlines = 0;

    printf("Enter text (press 'q' to stop):\n");

    while ((c = getchar()) != EOF) {

        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newlines++;
        else if (c == 'q')
            break;
    }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}
