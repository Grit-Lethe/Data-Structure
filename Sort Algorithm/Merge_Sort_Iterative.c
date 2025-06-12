#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void merge_sort_iterative(float arr[], int len);

int main(){
    float arr[MAX_SIZE];
    int len = 0;
    float num;
    printf("Enter floating-point numbers (enter a non-number to stop):\n");
    while (len<MAX_SIZE && scanf("%f", &num)==1){
        arr[len++] = num;
    }
    merge_sort_iterative(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}

int min(float x, float y){
    return x<y ? x : y;
}

void merge_sort_iterative(float arr[], int len){
    float *a = arr;
    float *b = (float*) malloc(len*sizeof(int));
    if (b==NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int seg=1; seg<len; seg+=seg){
        for (int start=0; start<len; start+=seg+seg){
            int low = start;
            int mid = min(start+seg, len);
            int high = min(start+seg+seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1<end1 && start2<end2){
                b[k++] = a[start1]<a[start2] ? a[start1++] : a[start2++];
            }
            while (start1<end1){
                b[k++] = a[start1++];
            }
            while (start2<end2){
                b[k++] = a[start2++];
            }
        }
        float *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr){
        for (int i=0; i<len; i++){
            b[i] = a[i];
        }
        b = a;
    }
    free(b);
}
