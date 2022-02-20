#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Mod 1000000007

ll fastExp(int n, int k){
    if(k==0){
        return 1;
    }
    if(k==1){
        return n;
    }
    ll val = fastExp(n, k/2);
    if(k%2 == 0)
        return ((val%Mod)*(val%Mod))%Mod;
    return ((val%Mod)*(val%Mod)*(n%Mod))%Mod;

}
/*
int fastExp(int n, int k){
    if(k==0){
        return 1;
    }
    if(k==1){
        return n;
    }
    int val = fastExp(n, k/2);
    if(k%2 == 0)
        return val*val;
    return val*val*n;

}
*/
int main(){
    int n, k;
    cin >> n >> k;
    cout << fastExp(n,k) << endl;

    return 0;
}
