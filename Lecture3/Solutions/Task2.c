#include <stdio.h>
#include <stdlib.h>

int main(){
    float **subjects,sum = 0,avg = 0 ;
    int l, k;
    int *subjects_tests_number;
    int total_test_numbers = 0;
    printf("Enter number of subjects : ");
    scanf("%d", &l);
    subjects = calloc(l, sizeof(float *));
    subjects_tests_number = calloc(l, sizeof(int));
    for (int i = 0; i < l; i++){
        printf("Enter How many test subject %d have: ", i + 1);
        scanf("%d", &k);
        *(subjects + i) = calloc(k, sizeof(int));
        *(subjects_tests_number + i) = k;
        for (int j = 0; j < k; j++){
            printf("Enter test %d of subject %d grade: ", j + 1, i + 1);
            scanf("%f", *(subjects + i) + j);
        }
    }
    for (int i = 0; i < l; i++){
        avg = 0;
        printf("Subject %d tests marks and average :\n", i + 1);
        for (int j = 0; j < *(subjects_tests_number + i); j++){
            printf("Test %d grade : %f \n", j + 1, *(*(subjects + i) + j));
            avg +=  *(*(subjects + i) + j) / *(subjects_tests_number + i);
            sum += *(*(subjects + i) + j);
            total_test_numbers++; 
        }
        free(*(subjects + i));
        printf("The average of subject %d is %f\n", i + 1, avg);
    }
    avg = sum / total_test_numbers;
    printf("The total average is %f\n", avg);
    free(subjects_tests_number);
    free(subjects);
    return 0;
}