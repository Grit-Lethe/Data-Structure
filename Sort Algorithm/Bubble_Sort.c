#include <stdio.h>
#define MAX_SIZE 100

void bubble_sort(float arr[], int len);

int main(){
    float arr[MAX_SIZE];
    int len = 0;
    float num;
    printf("Enter floating-point numbers (enter a non-number to stop):\n");
    while (len<MAX_SIZE&&scanf("%f", &num)==1){
        arr[len++] = num;
    }
    bubble_sort(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}

void bubble_sort(float arr[], int len){
    for (int i=0; i<len-1; i++){
        for (int j=0; j<len-1; j++){
            if (arr[j]>arr[j+1]){
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
