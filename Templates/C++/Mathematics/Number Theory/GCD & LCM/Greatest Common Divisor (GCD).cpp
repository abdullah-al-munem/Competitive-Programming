#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;

// O(min(a, b))
int gcd1(int a, int b) {
    int ans = 1;
    int minNumber = min(a, b);
    for (int i = 1; i <= minNumber; i++) {
        if (a % i == 0 && b % i == 0) {
            ans = i;
        }
    }
    return ans;
}

//Euclid's Algorithms - GCD(a,b) = GCD(b, a%b)
//O(log(max(a,b)))
int gcd2(int a, int b) { // assuming a >= b
    while (true) {
        int remainder = a % b;
        if (remainder == 0) {
            return b;
        }
        a = b; // a takes the bigger side
        b = remainder; // b takes the smaller side
    }
}

//Euclid's Algorithms with recursive function
int gcd3(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd2(b, a % b);
}

//Euclid's Algorithms in one line
int gcd4(int a, int b) {
    return b == 0 ? a : gcd4(b, a % b);
}

// GCD of more than two (or array) numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd4(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

int main()
{
	int a, b;
    scanf("%d%d", &a, &b);
    int gcd = __gcd(a, b); // we can use this line if we have GNU compiler

	cout << "For a and b: " << gcd << endl;
	//cout << gcd3(a,b) << endl;

	int arr[] = { 2, 4, 6, 8, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "For array: " << findGCD(arr, n) << endl;

	return 0;
}


