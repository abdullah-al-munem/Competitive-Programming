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
    int arr1[n], arr2[n];
    for(int i=1; i<n; i++){
        cin >> arr1[i];
        arr2[arr1[i]] = i;
    }
    for(int i=1; i<n; i++){
        cout << arr2[i];
        if(i!=n-1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
