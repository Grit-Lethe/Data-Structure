#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void bubble_sort(float arr[], int len);
void selection_sort(float arr[], int len);
void insertion_sort(float arr[], int len);
void shell_sort(float arr[], int len);
void merge_sort_iterative(float arr[], int len);
void merge_sort_recursion(float arr[], float reg[], int start, int end);
void merge_sort(float arr[], const int len);

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

void shell_sort(float arr[], int len){
    for (int gap=len/2; gap>0; gap/=2){
        for (int i=gap; i<len; i++){
            int temp = arr[i];
            int j = i;
            while (j>=gap&&arr[j-gap]>temp){
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
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
