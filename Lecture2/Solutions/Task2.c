#include <stdio.h>
#include <math.h>

int main(){
    int n, k;
    printf("Enter number n : ");
    scanf("%d", &n);
    for(int i = 2 ; i <= n; i++){
        k = floor(sqrt(i));
        for (int j = k; j > 0; j--){
            if(i % j == 0 && j != 1){
                break;
            }else if (j == 1){
                printf("%i\n", i);
            }
        }

    }
    return 0;
}