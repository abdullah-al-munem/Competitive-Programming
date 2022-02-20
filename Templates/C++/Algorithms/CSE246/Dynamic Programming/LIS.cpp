#include <bits/stdc++.h>
using namespace std;
#define mset2(a,v) memset(&a,v,sizeof(a))

int arr[1007];
int n;
int dp[1008][1009];

int lis(int ind, int last){
    if(ind == n)
        return 0;
    if(dp[ind][last+1] != -1)
        return dp[ind][last+1];

    if(last == -1 || arr[ind] > arr[last]){
        int opt1 = 1+lis(ind+1, ind);
        int opt2 = lis(ind+1, last);

        if(opt1 > opt2)
            return dp[ind][last+1] = opt1;

        return dp[ind][last+1] = opt2;
    }

    return dp[ind][last+1] = lis(ind+1, last);

}

int main(){

    mset2(dp, -1);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << lis(0, -1) << endl;

    return 0;
}
