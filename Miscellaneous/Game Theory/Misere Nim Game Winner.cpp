#include <bits/stdc++.h>
using namespace std;

string findWinner(int A[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= A[i];

	if (res > 0)
		return "First";
	else
		return "Second";
}

string whoIsTheDaddyNow(int A[], int n)
{
	if(n&1) // odd
        return "Second";
    else // even
        return "First";
}

int main()
{

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int flg = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] == 1)
                flg++;
        }
        if(flg == n)
            cout << whoIsTheDaddyNow(arr, n) << endl;
        else
            cout << findWinner(arr, n) << endl;
    }

	return 0;
}
