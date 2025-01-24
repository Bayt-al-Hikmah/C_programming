#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, x, x1, x2, delta;
    printf("Enter the value of a : ");
    scanf("%f", &a);
    printf("Enter the value of b : ");
    scanf("%f", &b);
    printf("Enter the value of c : ");
    scanf("%f", &c);
    if (a == 0 && b == 0){
        printf("There is no equation");
    }else if(a == 0 && b != 0){
        x = -c / b;
        printf("Solution is :\n");
        printf("x = %f", x);
    }else{
        delta = b * b - 4 * a * c;
        if(delta < 0){
            printf("No solution ");

        }else if(delta == 0){
            x = -b / (2 * a);
            printf("Solution is :\n");
            printf("x = %f", x);
        }else{
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("Solutions are :\n");
            printf("x1 = %f", x1);
            printf("x2 = %f", x2);
        }
    }
    return 0;
}