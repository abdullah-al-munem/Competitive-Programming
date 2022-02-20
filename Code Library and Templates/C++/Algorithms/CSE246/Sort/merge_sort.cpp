#include <bits/stdc++.h>
using namespace std;

int ara[100105];
int n;

void merge_sort(int ara[], int sz){
    if(sz==1){
        return;
    }
    int leftSize=sz/2;
    int rightSize=sz-leftSize;
    int left[leftSize];
    int right[rightSize];
    for(int i=0; i<leftSize; i++){
        left[i]=ara[i];
    }
    for(int i=leftSize; i<sz; i++){
        right[i-leftSize]=ara[i];
    }
    merge_sort(left, leftSize);
    merge_sort(right, rightSize);
    int leftMarker=0;
    int rightMarker=0;
    int ind=0;
    while(leftMarker<leftSize && rightMarker<rightSize){
        if(left[leftMarker]<=right[rightMarker]){
            ara[ind]=left[leftMarker];
            ind++;
            leftMarker++;
        }
        else{
            ara[ind]=right[rightMarker];
            ind++;
            rightMarker++;
        }
    }
    while(leftMarker<leftSize){
        ara[ind]=left[leftMarker];
        ind++;
        leftMarker++;
    }
    while(rightMarker<rightSize){
        ara[ind]=right[rightMarker];
        ind++;
        rightMarker++;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &ara[i]);
    }
    merge_sort(ara, n);
    for(int i=0; i<n; i++){
        printf("%d ", ara[i]);
    }
    return 0;
}
