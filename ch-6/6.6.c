#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[20];
    int index;

    printf("Please, insert any word you want: ");
    scanf("%s", &word);
    for(index = strlen(word); index >= 0; index--) {
        printf("%c", word[index]);
    }
    printf("\n");
    return 0;
}
