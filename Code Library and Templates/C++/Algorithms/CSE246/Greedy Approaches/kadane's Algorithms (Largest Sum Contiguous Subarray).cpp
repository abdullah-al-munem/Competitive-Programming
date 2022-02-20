#include <bits/stdc++.h>
using namespace std;

int range1, range2;

int kadaneAlgorith(int arr[], int n){

    int isAllNegative = 1;
    int mx = arr[0];

    for(int i=0; i<n; i++){
        if(arr[i] >= 0)
            isAllNegative = 0;

        if(arr[i] > mx){
            range1 = range2 = i+1;
            mx = arr[i];
        }
    }

    if(isAllNegative)
        return mx;

    int sum = 0;
    range1 = 1;
    for(int i=0; i<n; i++){

        sum += arr[i];
        if(sum < 0){
            range1 = i+2;
            sum = 0;
        }

        if(sum > mx){
            range2 = i+1;
            mx = sum;
        }

    }

    return mx;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int maxSum = kadaneAlgorith(arr, n);

    cout << "SubArray Range from " << range1 << " to " << range2 << " is: " << "( " << arr[range1-1] ;
    for(int i=range1; i<range2; i++)
        cout << ", " << arr[i];
    //cout << endl;
    cout << ") => " << maxSum << endl;

    return 0;
}
