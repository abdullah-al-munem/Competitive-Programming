#include <bits/stdc++.h>
using namespace std;

int ara[1000005];
int n;

long long int countInversions(int ara[], int sz){
    long long int countInv = 0;
    if(sz==1){
        return 0;
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
    countInv += countInversions(left, leftSize);
    countInv += countInversions(right, rightSize);
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
            countInv = countInv + (leftSize - leftMarker);
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

    return countInv;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &ara[i]);
    }
    long long int total = countInversions(ara, n);
    cout << total << endl;
    return 0;
}


