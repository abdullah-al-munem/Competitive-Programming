// C++ implementation of finding
// power of p in n!
#include <bits/stdc++.h>

using namespace std;

// Returns power of p in n!
// number of p = [n/p]+[n/p^2]+[n/p^3]+....+ unless it become zero
int PowerOFPINnfactorial(int n, int p)
{
	// initializing answer
	int ans = 0;

	// initializing
	int temp = p;

	// loop until temp<=n
	while (temp <= n) {

		// add number of numbers divisible by n
		ans += n / temp;

		// each time multiply temp by p
		temp = temp * p;
	}
	return ans;
}

// Function(n, 5) is for finding how many zero have this factorial n
// Driver function
int main()
{
	cout << PowerOFPINnfactorial(100, 5) << endl;

	return 0;
}
