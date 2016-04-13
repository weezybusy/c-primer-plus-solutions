#include <stdio.h>
#include <string.h>

int main(void) {
    
    char ch[255];
    int i = 0;
    int length;
    
    printf("Please, write a string: ");
    
    scanf("%c", &ch[i]);
    while(ch[i++] != '\n') {
        scanf("%c", &ch[i]);
    }
    
    length = strlen(ch);
    for(i = length-3; i >= 0; i--) {
        printf("%c", ch[i]);
    }
    
    printf("\n");
    return 0;
}
