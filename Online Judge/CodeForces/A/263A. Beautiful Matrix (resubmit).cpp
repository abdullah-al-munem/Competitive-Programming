#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){
    int arr[6][6];
    int r,c;
    for(int i=1; i<6; i++){
        for(int j=1; j<6; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0){
                r = i;
                c = j;
            }
        }
    }

    int sum = abs(3-r) + abs(3-c);
    cout << sum << endl;

    return 0;
}

