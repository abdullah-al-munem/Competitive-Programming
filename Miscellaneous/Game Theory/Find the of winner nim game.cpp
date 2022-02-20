#include <bits/stdc++.h>
using namespace std;

int findWinner1(int A[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= A[i];

	if (res > 0)
		return 1;
	else
		return 0;
}

string findWinner(int A[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= A[i];

	// Alice is the winner if XOR sum is not equal to Zero
	if (res > 0)
		return "Alice";

	// Bob is the winner if XOR sum is equal to Zero
	else
		return "Bob";
}

int main()
{

	int A[] = { 3, 4, 5 };
	int n = sizeof(A) / sizeof(A[0]);

	int B[] = { 3, 4, 7 };
	int n2 = sizeof(B) / sizeof(B[0]);

	// Alice == 1st player
	// Bob == 2nd player
	cout << "Winner: " << findWinner(A, n) << endl;
	cout << "After playing ones again...\n";
	cout << "Winner: " << findWinner(B, n2) << endl;

	return 0;
}
