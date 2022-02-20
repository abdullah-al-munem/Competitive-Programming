#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
    // Base cases
    if (n == 1) return 0;
    if (n == 2) return 1;

    // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
    // d(n)=(n - 1)*(d(n-1)+d(n-2)) -> formula
    return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}


int main()
{
	int n;
    cin >> n;
	cout << "Count of Derangements is " << countDer(n) <<endl;
	return 0;
}

