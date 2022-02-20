#include <bits/stdc++.h>
using namespace std;

string findWinner(int n, int arr[])
{
    if(n == 1){
        return "Second";
    }
	long long int res = 0;
	for (int i = 0; i < n; i++){

        // odd
        if(arr[i]&1){
            res ^= i;
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




