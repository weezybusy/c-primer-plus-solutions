#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int spaces = 0;
    int new_lines = 0;
    int other = 0;

    printf("Please, enter characters or '#' to quit):\n");
    while((ch = getchar()) != '#')
    {
        if (ch == ' ')
            spaces++;
        else if (ch == '\n')
            new_lines++;
        else
            other++;
    }
    printf("Spaces = %d, new lines = %d, other characters = %d\n",
            spaces, new_lines, other);
    return 0;
}
