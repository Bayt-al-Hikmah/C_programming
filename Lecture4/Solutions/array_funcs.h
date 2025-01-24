int largest(int size, int *arr){
    int tmp = *arr;
    for(int i = 0; i< size; i++){
        if(*(arr+i) > tmp){
            tmp = *(arr + i);
        }
        
    }
    return tmp;
}

int smallest(int size, int *arr){
    int tmp = *arr;
    for(int i = 0; i< size; i++){
        if(*(arr+i) < tmp){
            tmp = *(arr + i);
        }
        
    }
    return tmp;
}

float avg(int size, int *arr){
    float tmp = 0;
    for(int i = 0; i< size; i++){
        tmp += (float) *(arr + i) / (float) size;
    }
    return tmp;
}