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

        cout << findWinner(arr, n) << endl;
    }

	return 0;
}
