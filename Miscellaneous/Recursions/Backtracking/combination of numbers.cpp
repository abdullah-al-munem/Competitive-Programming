#include <bits/stdc++.h>
using namespace std;

void comb(int n, int curr[], int num, int rem, int k){
    if(rem == 0){
        for(int i=0; i<k; i++)
            cout << curr[i] << " ";
        cout << endl;
        return;
    }

    if(num>n){
        return;
    }

    //comb(n, curr, num+1, rem, k); //don't take the number
    curr[k-rem] = num;
    comb(n, curr, num+1, rem-1, k); // take the number
    comb(n, curr, num+1, rem, k); //don't take the number

}

int main(){

    int n, k;
    cin >> n >> k;
    int arr[k];
    comb(n, arr, 1, k, k);
    return 0;
}
