
#include <bits/stdc++.h>
using namespace std;

void findWinner(int n){

    bool *dp = new bool[n+1]; // dp[N] = true -> P1 wins, else P2 wins
    dp[1] = false;
    dp[2] = true;
    dp[3] = true;
    dp[4] = true;
    dp[5] = true;
    for(int i = 6; i <= n; i++) {
        if(dp[i-2] == false || dp[i-3] == false || dp[i-5] == false) {
            dp[i] = true;
        } else {
            dp[i] = false;
        }
    }

    if(dp[n]) {
        cout<<"First\n";
    } else {
        cout<<"Second\n";
    }

}


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        findWinner(n);
    }

	return 0;
}



