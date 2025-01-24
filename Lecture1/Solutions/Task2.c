#include <stdio.h>

int main(){
    char name[10];
    float grades[3], avg;
    printf("Enter student name : ");
    scanf("%[^\n]%*c", &name);
    printf("Enter first grade : ");
    scanf("%f", &grades[0]);
    printf("Enter second grade : ");
    scanf("%f", &grades[1]);
    printf("Enter third grade : ");
    scanf("%f", &grades[2]);
    avg = (grades[0] + grades[1] + grades[2]) / 3.0;
    printf("%s have those marks %f, %f, %f \n And this is his average %f", name, grades[0], grades[1], grades[2], avg);
    return 0;
}