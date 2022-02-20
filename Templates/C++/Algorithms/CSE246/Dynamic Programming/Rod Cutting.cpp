#include <bits/stdc++.h>
using namespace std;

int p[1005];
int dp[1005];
int sell[1005];

int cutting(int len){

    if(len==0)
        return 0;

    if(dp[len] != -1)
        return dp[len];

    int mx = p[len]; // Not to cut
    int selling_length = len;
    int value;
    for(int i=0; i<len-1; i++){
        value = p[i]+cutting(len-i);
        if(value > mx){
            mx = value;
            selling_length = i;
        }
    }

    sell[len] = selling_length;
    return dp[len] = mx;
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> p[i];

    memset(dp,-1,sizeof(dp));

    cout << "Max outcome: " << cutting(n) << endl;
    cout << "Rods should sold with lengths: ";
    int rem = n;
    while(rem > 0){
        cout << sell[rem] << " ";
        rem -= sell[rem];
    }
    cout << endl;

    return 0;
}


