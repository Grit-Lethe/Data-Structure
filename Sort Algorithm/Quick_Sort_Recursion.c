#include <stdio.h>
#define MAX_SIZE 100

void swap(float *a, float *b){
    float t = *a;
    *a = *b;
    *b = t;
}

void quick_sort_recursion(float arr[], int start, int end){
    if (start >= end)
        return;
    float mid = arr[end];
    int left = start, right = end - 1;
    while (left < right){
        while (left < right && arr[left] < mid)
            left++;
        while (left < right && arr[right] >= mid)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    quick_sort_recursion(arr, start, left - 1);
    quick_sort_recursion(arr, left + 1, end);
}

void quick_sort(float arr[], const int len){
    quick_sort_recursion(arr, 0, len - 1);
}

int main(){
    float arr[MAX_SIZE];
    int len = 0;
    float num;
    printf("Enter floating-point numbers (enter a non-number to stop):\n");
    while (len<MAX_SIZE&&scanf("%f", &num)==1){
        arr[len++] = num;
    }
    quick_sort(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}
