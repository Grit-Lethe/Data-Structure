#include <stdio.h>
#define MAX_SIZE 100

typedef struct _Rnge{
    int start, end;
} Range;

Range new_Range(int s, int e){
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

void swap(float *a, float *b){
    float t = *a;
    *a = *b;
    *b = t;
}

void quick_sort_iterative(float arr[], const int len){
    if (len <= 0){
        return;
    }
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p > 0){
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        float mid = arr[(range.start + range.end) / 2];
        int left = range.start, right = range.end;
        do{
            while (arr[left] < mid) ++left;
            while (arr[right] > mid) --right;
            if (left <= right){
                swap(&arr[left], &arr[right]);
                left++;
                right--;
            }
        }while (left <= right);
        if (range.start < right) r[p++] = new_Range(range.start, right);
        if (range.end > left) r[p++] = new_Range(left, range.end);
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
    quick_sort_iterative(arr, len);
    for (int i=0; i<len; i++){
        printf("%f\n", arr[i]);
    }
    return 0;
}
