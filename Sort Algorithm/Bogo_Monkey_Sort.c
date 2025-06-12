#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX_SIZE 100

void swap(float *a, float *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void randomize(float arr[], int len){
    for (int i=0; i<len; i++){
        srand(time(NULL)+i);
        if (rand()%2){
            swap(&arr[i], &arr[i+1]);
        }
    }
}

bool is_sorted(float arr[], int len){
    for (int i=0; i<len; i++){
        if (arr[i]>arr[i+1])
            return false;
        else
            return true;
    }
}

void bogo_sort(float arr[], int len){
    while (!is_sorted(arr, len)){
        randomize(arr, len);
    }
}

int main(){
    float arr[MAX_SIZE];
    int len = 0;
    float num;
    printf("Enter floating-point numbers (enter a non-number to stop):\n");
    while (len<MAX_SIZE&&scanf("%f", &num)==1){
        arr[len++] = num;
    }
    bogo_sort(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}
