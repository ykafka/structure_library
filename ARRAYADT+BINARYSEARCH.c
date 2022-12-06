#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void display(struct Array arr) {
    int i;
    printf("\nElements are: \n");
    for (i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
}

void append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i-1];
            arr->length++;
        }
    }
}

int delete(struct Array *arr, int index) {
    int x = 0;
    if (index >= 0 && index <= arr->length-1) {
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

//basic reverse
void reverse(struct Array *arr) {
    int *B;
    int i, j;
    B = (int *)malloc(arr->length*sizeof(int));
    for (i = arr->length-1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for (i = 0; i > arr->length; i++) {
        arr->A[i] = B[i];
    }
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//using swap
void reverse2(struct Array *arr) {
    int i, j;
    for (i = 0, j = arr->length-1; i < j; i++, j++) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

//most basic binary search ever lmao
int binarySearch(struct Array arr, int key) {
    int l = 0, h = arr.length-1, mid;
    while (l <= h) {
        mid = (l+h)/2;
        if (key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

//RECURSIVE BINARY SEARCH
int RbinarySearch(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l+h)/2;
        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            return RbinarySearch (a, l, mid-1, key);
        } else {
            return RbinarySearch(a, mid+1, h, key);
        }
    }
    
    return -1;
}

int main(void) {
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5 };
    
//    printf("%d\n", RbinarySearch(arr.A, 0, arr.length, 3));
    reverse2(&arr);
    display(arr);
    return 0;
}


