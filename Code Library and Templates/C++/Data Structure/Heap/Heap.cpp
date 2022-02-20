#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

int parent(int i);
int left_child(int i);
int right_child(int i);
void swap(int *x, int *y);
void max_heapify(int a[], int i, int n);
void build_max_heap(int a[], int n);
int get_max(int a[]);
void heap_sort(int a[], int n);
void print_heap(int a[], int n);


int main(){

    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int arr[n],i;
    //int n = sizeof(arr) / sizeof(arr[0]);
    for(i = 0; i < n; i++)
      arr[i]=(rand()%100)+1;

    //build_max_heap(arr,n);
    print_heap(arr, n);
    heap_sort(arr,n);
    printf("After sorting...\n");
    print_heap(arr, n);
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


void print_heap(int a[], int n){
    printf("Printing Heap Elements...\n");
    int i;
    for(i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

