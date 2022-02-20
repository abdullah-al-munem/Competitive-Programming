// C++ program to implement above approach
#include <iostream>
using namespace std;

// Calculating factorial of an integer n.
long long factorial(int n)
{
	// Our base cases of factorial 0! = 1! = 1
	if (n == 0)
		return 1;

	// n can't be less than 0.
	if (n < 0)
		return -1;
	long long res = 1;
	for (int i = 2; i < n + 1; ++i)
		res *= i;
	return res;
}

// Function to compute the number of combination
// of r objects out of n objects.
int nCr(int n, int r)
{
	// r cant be more than n so we'd like the
	// program to crash if the user entered
	// wrong input.
	if (r > n)
		return -1;

	if (n == r)
		return 1;

	if (r == 0)
		return 1;

	// nCr(n, r) = nCr(n - 1, r - 1) + nCr(n - 1, r)
	return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// Function to calculate the Stirling numbers.
// The base cases which were discussed above are handled
// to stop the recursive calls.
long long stirlingNumber(int r, int n)
{

	// n can't be more than
	// r, s(r, 0) = 0.
	if (n > r)
		return -1;

	if (n == 0)
		return 0;

	if (r == n)
		return 1;

	if (n == 1)
		return factorial(r - 1);

	if (r - n == 1)
		return nCr(r, 2);
	else
		return stirlingNumber(r - 1, n - 1) + (r - 1) * stirlingNumber(r - 1, n);
}

// Driver program
int main()
{
	// Calculating the stirling number s(9, 2)
	int n, k;
    cin >> n >> k;
	long long val = stirlingNumber(n, k);
	if (val == -1)
		cout << " No stirling number";
	else
		cout << "The Stirling Number s(" << n
			<< ", " << k << ") is : " << val;
	return 0;
}
