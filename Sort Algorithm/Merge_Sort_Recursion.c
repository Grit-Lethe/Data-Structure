#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void merge_sort_recursion(float arr[], float reg[], int start, int end);
void merge_sort(float arr[], const int len);

int main(){
    float arr[MAX_SIZE];
    int len = 0;
    float num;
    printf("Enter floating-point numbers (enter a non-number to stop):\n");
    while (len<MAX_SIZE && scanf("%f", &num)==1){
        arr[len++] = num;
    }
    merge_sort(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}

void merge_sort_recursion(float arr[],  float reg[], int start, int end){
    if (start >= end){
        return;
    }
    int mid = start + (end - start) / 2;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursion(arr, reg, start1, end1);
    merge_sort_recursion(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2){
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }
    while (start1 <= end1){
        reg[k++] = arr[start1++];
    }
    while (start2 <= end2){
        reg[k++] = arr[start2++];
    }
    memcpy(arr + start, reg + start, (end - start + 1) * sizeof(float));
}

void merge_sort(float arr[], const int len){
    float *reg = (float*) malloc(len * sizeof(int));
    if (reg == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    merge_sort_recursion(arr, reg, 0, len - 1);
    free(reg);
}
