#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN 20
#define EMPTY_VALUE -1

int memo[MAX_LEN+1][MAX_LEN+1];

void init() {
    for (int i = 0; i <= MAX_LEN; i++) {
        for(int j=0; j<= MAX_LEN; j++)
            memo[i][j] = EMPTY_VALUE;
    }
}

// O(n*m) -> O(n^2)
int lcs(string &S, string &W, int i = 0,int j = 0) {

    if(i == S.size() || j == W.size()) return 0;
    //cout << "1" <<endl;
    if(memo[i][j] != EMPTY_VALUE) {
        return memo[i][j];
    }
    //cout << "2" <<endl;
    int ans=0;
    if(S[i] == W[j]) {
        ans = 1 + lcs(S, W, i + 1,j + 1);
    }
    else{
        int val1 = lcs(S, W, i + 1, j);
        int val2 = lcs(S, W, i,j + 1);

        ans=max(val1,val2);
    }
    //cout << "3" <<endl;
    memo[i][j] = ans;
    return memo[i][j];
}

int lcsIterative(string S, string W) {
    int n = S.size();
    int m = W.size();

    for (int i = 0;i < n;i++) memo[i][m] = 0;
    for (int j = 0;j < m;j++) memo[n][j] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (S[i] == W[j]) {
                memo[i][j] = memo[i + 1][j + 1] + 1;
            } else {
                memo[i][j] = max(memo[i + 1][j], memo[i][j + 1]);
            }
        }
    }

    return memo[0][0];
}

int main(){

    string S = "HELLOM";
    string W = "HMRLL";

    init();

    cout << lcs(S, W) <<endl;
    //cout << lcsIterative(S, W) <<endl;

    return 0;
}

