#include <stdio.h>
#define MAX_SIZE 100

void selection_sort(float arr[], int len);

int main(){
    float arr[MAX_SIZE];
    int len = 0;
    float num;
    printf("Enter floating-point numbers (enter a non-number to stop):\n");
    while (len<MAX_SIZE&&scanf("%f", &num)==1){
        arr[len++] = num;
    }
    selection_sort(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}

void selection_sort(float arr[], int len){
    for (int i=0; i<len-1; i++){
        int min = i;
        for (int j=i+1; j<len; j++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
        if (min!=i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}