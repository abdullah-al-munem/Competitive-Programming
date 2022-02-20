#include <bits/stdc++.h>
using namespace std;

int dp[1000];

int grundy(int n){ // n size board = ? nim pile
    if(n==0){
        dp[0] = 0;
        return dp[0];
    }
    if(dp[n] != -1)
        return dp[n];

    set<int> s;
    for(int i=0; i<n; i++){ // Which cell to mark
        if(i == 0 || i == n-1)
            s.insert(grundy(n-2));
        else
            s.insert(grundy(i-1)^grundy(n-1-2));
    }

    int mex = 0;
    while(s.find(mex) != s.end())
        mex++;
    s.clear();
    dp[n] = mex;
    return dp[n];
}

int main(){
    memset(dp, -1, 1000);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << grundy(n) << endl;
    }


}
