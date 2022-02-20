#include <bits/stdc++.h>
using namespace std;

int oddSum(int n){
    return n*n;
}

int evenSum(int n){
    int oddNSum = n*n;
    int a = n*2;
    int evenNSum = (a*(a+1))/2 - oddNSum;
    return evenNSum;
}

int main(){
    int n;
    cin >> n;
    cout << oddSum(n) << endl;
    cout << evenSum(n) << endl;

    return 0;
}
