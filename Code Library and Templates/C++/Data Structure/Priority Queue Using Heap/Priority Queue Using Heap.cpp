#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

int n = 15, i = -1;

int parent(int i);
int left_child(int i);
int right_child(int i);
void swap(int *x, int *y);
void max_heapify(int a[], int i, int n);
void build_max_heap(int a[], int n);
int get_max(int a[]);

void insert(int a[], int x, int n);
int extract_max(int a[], int n);
void increase_key(int a[], int i, int x);
void decrease_key(int a[], int i, int x, int n);

void print_heap(int a[], int n);


int main(){

    //printf("Enter the value of n: ");
    //scanf("%d",&n);

    int arr[n];

    //int n = sizeof(arr) / sizeof(arr[0]);
    for(i = 0; i < n; i++)
      arr[i]=(rand()%100)+1;

    i = i-1;

    insert(arr, 20, i);
    insert(arr, 15, i);
    insert(arr, 8, i);
    insert(arr, 10, i);
    insert(arr, 5, i);
    insert(arr, 7, i);
    insert(arr, 6, i);
    insert(arr, 2, i);
    insert(arr, 9, i);
    insert(arr, 1, i);

    build_max_heap(arr,i);
    print_heap(arr, i);

    printf("increase the value of element 5, %d to 22\n", arr[4]);
    increase_key(arr, 4, 22);
    print_heap(arr,i);

    printf("increase the value of element 1, %d to 13\n", arr[0]);
    decrease_key(arr, 0, 13, i);
    print_heap(arr,i);

    printf("extract_max 1: %d\n", extract_max(arr, i));
    printf("extract_max 2: %d\n", extract_max(arr, i));
    printf("extract_max 3: %d\n", extract_max(arr, i));
    printf("extract_max 4: %d\n", extract_max(arr, i));
    printf("extract_max 5: %d\n", extract_max(arr, i));

    print_heap(arr, i);
    printf("\n");

    return 0;
}

int parent(int i){
    return (i-1)/2;
}

int left_child(int i){
    return 2*i+1;
}

int right_child(int i){
    return 2*i+2;
}

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void max_heapify(int a[], int i, int n){

    int left = left_child(i);
    int right = right_child(i);
    int largest = i;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    if(largest != i){
        swap(&a[i],&a[largest]);
        max_heapify(a, largest, n);
    }

}

void build_max_heap(int a[], int n){
    int i;
    for(i = n/2-1; i >= 0; i--){
        max_heapify(a, i, n);
    }
}

int get_max(int a[]){
    return a[0];
}

void heap_sort(int a[], int n){
    int i;
    build_max_heap(a,n);
    for(i = n-1; i>0; i--){
        swap(&a[0],&a[i]);

        //n = n-1;
        max_heapify(a,0,i);
    }

}

void insert(int a[], int x, int n) {
    n++;
    a[n] = x;
    //increase_key(a, n, x);

    int i = n;
    while(i>0 &&  a[i] > a[parent(i)]) {
        swap(&a[i], &a[parent(i)]);
        i = parent(i);
    }

    //return n;
}

int extract_max(int a[], int n) {
    int maxm = a[0];
    a[0] = a[n];
    n--;
    max_heapify(a, 0, n);
    return maxm;
}


void increase_key(int a[], int i, int x) {
    a[i] = x;

    while(i>0 &&  a[i] > a[parent(i)]) {
        swap(&a[i], &a[parent(i)]);
        i = parent(i);
    }
}

void decrease_key(int a[], int i, int x, int n) {
    a[i] = x;
    max_heapify(a, i, n);
}

void print_heap(int a[], int n){
    printf("Printing Heap Elements...\n");
    int i;
    for(i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}


