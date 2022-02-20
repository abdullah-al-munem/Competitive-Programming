#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n,m;
    cin >> n >> m;
    int arr[m];
    for(int i=0; i<m; i++)
        cin >> arr[i];

    sort(arr, arr+m);

    int mn = INT_MAX;
    for(int i=0; i+n<=m; i++){
        int sub = 0, sum = 0;
        int k = i;
        for(int j=1; j<n; j++){
            sub = arr[k+1] - arr[k];
            sum += sub;
            k++;
            //cout << "sum: " << sum << endl;
        }
        if(sum < mn)
            mn = sum;
    }

    cout << mn << endl;

    return 0;
}
