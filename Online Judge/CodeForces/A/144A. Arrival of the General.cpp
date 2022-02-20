#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    n++;
    int arr[n];
    int mx = INT_MIN, mn = INT_MAX, locMx, locMn;

    for(int i=1; i<n; i++){
        cin >> arr[i];
        if(arr[i] > mx){
            //cout << "mx & arr[i]: " << mx << " " << arr[i] << endl;
            mx = arr[i];
            locMx = i;
        }
        if(arr[i] <= mn){
            mn = arr[i];
            locMn = i;
        }
    }

    n--;
    if(locMx>locMn)
        locMn++;

    //cout << "locMx: " << locMx << endl;
    //cout << "locMn: " << locMn << endl;

    int sum = (n-locMn) + (locMx-1);

    cout << sum << endl;

    return 0;
}


