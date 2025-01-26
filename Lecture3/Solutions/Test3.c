#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    char author[20];
    int number_of_pages;
} Book;

int main(){
    Book *Library;
    int n;
    printf("Enter number of Books you have : ");
    scanf("%d", &n);
    Library = calloc(n, sizeof(Book));
    for(int i = 0; i < n; i++){
        printf("Enter Book %d name : ", i + 1);
        scanf("%s", (Library + i)->name);
        printf("Enter Book %d author : ", i + 1);
        scanf("%s", (Library + i)->author);
        printf("Enter Book %d pages numbers : ", i + 1);
        scanf("%d", &(Library + i)->number_of_pages);
    }
    printf("You have saved %d Books\n", n);
    for(int i = 0; i < n; i++){
        printf("Book %d %s : by %s have %d pages \n", i + 1, (Library + i)->name, (Library + i)->author, (Library + i)->number_of_pages);
    }
    free(Library);
    return 0;

}
