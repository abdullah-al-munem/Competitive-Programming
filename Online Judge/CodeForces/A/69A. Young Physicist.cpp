#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n][3];
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    int flg = 1;
    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            sum += arr[j][i];
        }
        if(sum != 0){
            flg = 0;
            break;
        }
    }

    if(flg)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

