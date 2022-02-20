#include <bits/stdc++.h>
using namespace std;

int  mex[10004];
int grundyMex(int n){
    // base case
    if(n == 0){
        mex[0] = 0;
        return mex[0];
    }
    if(n == 1){
        mex[1] = 1;
        return mex[1];
    }

    if(grundyMex(n-1) == 0 || grundyMex(n-2) == 0){
        mex[n] = 1;
        return mex[n];
    }

    mex[n] = 0;
    return mex[n];

}

string findWinner(int n, int arr[])
{
	int res = 0;
	for (int i = 0; i < n; i++){

        // odd
        if(arr[i]&1){
            int m = grundyMex(arr[i]);
            res ^= m;
        }
	}


	if (res > 0)
		return "First";
	else
		return "Second";
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        cout << findWinner(n, arr) << endl;
    }

	return 0;
}

