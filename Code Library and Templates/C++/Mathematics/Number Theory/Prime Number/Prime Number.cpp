#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;


// O(n)
isPrime1(int n){
    if(n<=1)
        return 0;

    for(int i=2; i<n; i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

// O(sqrt(n))
isPrime2(int n){
    if(n<=1)
        return 0;

    int limit = sqrt(n+1);
    for(int i=2; i<=limit; i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main(){

    int a;
    cin >> a;
    if(isPrime2(a))
        cout << "Prime!\n";
    else
        cout << "Not Prime!\n";
    return 0;
}


