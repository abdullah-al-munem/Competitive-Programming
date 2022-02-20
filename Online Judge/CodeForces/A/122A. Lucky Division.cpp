#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n;
    cin >> n;
    int tmp = n, ct = 0, tn = 0;

    while(tmp){
        int m = tmp%10;
        if(m == 4 || m == 7)
            ct++;
        tn++;
        tmp /= 10;
    }

    int flg = 0;
    if(ct == tn){
        cout << "YES\n";
    }
    else{
        int arr[] = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 744, 747, 774, 777 };
        int len = sizeof(arr)/sizeof(arr[0]);
        for(int i=0; i<len; i++){
            if(n%arr[i] == 0){
                flg = 1;
                break;
            }
        }
        if(flg)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
