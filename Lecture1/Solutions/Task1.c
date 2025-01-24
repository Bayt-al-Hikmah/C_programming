#include <stdio.h>

const float PI = 3.14;

int main(){
    float s, r;
    printf("Enter circle radius : ");
    scanf("%f", &r);
    s = r * r * PI;
    printf("The surface of the circle is %f\n", s);
    return 0;
}