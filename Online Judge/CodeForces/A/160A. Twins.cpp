#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;


int main(){

    int n;
    cin >> n;
    int arr[n], sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n, greater<int>());

    int sum2 = 0, ct = 0;
    for(int i=0; i<n; i++){
        sum2 += arr[i];
        ct++;
        if(sum2 > sum/2)
            break;
    }
    cout << ct << endl;

    return 0;
}
