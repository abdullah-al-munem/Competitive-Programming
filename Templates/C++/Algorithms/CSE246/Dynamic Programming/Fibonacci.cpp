#include <bits/stdc++.h>
using namespace std;

int dp[105];

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}


int main()
{
    memset(dp, -1, 105);
    int n;
    while(cin >> n){
        if(n==-1)
            break;
        cout << fib(n) << endl;
    }


	return 0;
}

