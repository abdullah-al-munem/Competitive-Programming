#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int arr[], int l, int r){

    int pivot = arr[r];
    int i = l - 1;

    for(int j = l; j < r; j++){

        if(arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i+1, r);
    return i+1;

}

void quickSort(int arr[], int l, int r){

    if(l < r){

        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }


}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n+1];       //create an array with given number of elements
    cout << "Enter elements:" << endl;
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    //int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    cout << "Array after Sorting: ";
    printArray(arr, n);

    return 0;
}


