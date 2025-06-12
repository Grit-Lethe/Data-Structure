#include <stdio.h>
#define MAX_SIZE 100

void insertion_sort(float arr[], int len);

int main(){
    float arr[MAX_SIZE];
    int len = 0;
    float num;
    printf("Enter floating-point numbers (enter a non-number to stop):\n");
    while (len<MAX_SIZE&&scanf("%f", &num)==1){
        arr[len++] = num;
    }
    insertion_sort(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}

void insertion_sort(float arr[], int len){
    for (int i=1; i<len; i++){
        int temp = arr[i];
        int j = i;
        while (j>0&&arr[j-1]>temp){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}
