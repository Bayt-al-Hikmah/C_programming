#include <stdio.h>
#include <stdlib.h>
#include "array_funcs.h"


int main(){
    int size;
    int *arr;
    printf("Enter Number of Element : ");
    scanf("%d", &size);
    arr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++){
        printf("Enter the %d  Element : ", i + 1);
        scanf("%d", arr + i);
    }
    printf("The Biggest Element is %d\n", largest(size, arr));
    printf("The Smallest Element is %d\n", smallest(size, arr));
    printf("The Average of The Element is %f\n", avg(size, arr));
    free(arr);
    return 0;
}