#include<bits/stdc++.h>
using namespace std;

int dp[1000];

int grundy(int n){

    if(dp[n] != -1)
        return dp[n];

    set<int> s;
    for(int i=1; i<=n/2; i++){ // Which cell to mark
        s.insert(grundy(n-i));
    }

    int mex = 0;
    while(s.find(mex) != s.end())
        mex++;
    s.clear();
    return dp[n] = mex;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<=100; i++)
        cout << i << " -> " << grundy(i) << endl;
	return 0;
}

