#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr1[n], arr2[n];

    for(int i=0; i<n; i++){
        cin >> arr1[i];
        cin >> arr2[i];
    }

    int ct = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr1[i] == arr2[j])
                ct++;
        }
    }

    cout << ct << endl;

    return 0;
}
