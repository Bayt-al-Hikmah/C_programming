#include <stdio.h>
#include <stdlib.h>

int main(){
    char *string = calloc(100, sizeof(char));
    printf("Enter string : ");
    scanf("%[^\n]%*c", string);
    for (int i = 0 ; ; i++){
        if(*(string + i) == '\0'){
            printf("The length of the string is %d", i);
            break;
        }
    } 
    free(string);
    return 0;
}