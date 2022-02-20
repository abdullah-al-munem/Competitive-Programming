#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;

//normal (bad) approach
int lcm1(int a, int b) {
    for (int i = 1; ; i++) {
        if (i % a == 0 && i % b == 0) {
            return i;
        }
    }
}

int gcd(int a, int b);

// https://en.wikipedia.org/wiki/Least_common_multiple#Fundamental_theorem_of_arithmetic

// formula - gcd(a,b) * lcm(a,b) = a*b
int lcm2(int a, int b) {
    return a * b / gcd(a, b);
}

// for avoiding overflow, because a*b can be a large number
int lcm3(int a, int b) {
    return (a / gcd(a, b)) * b;
}

typedef long long int ll;
// LCM of more than two (or array) numbers
ll findLCM(int arr[], int n)
{
    // Initialize result
    ll ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++){
        ans = lcm3(arr[i], ans);
        //ans = ((arr[i] / (gcd(arr[i], ans))) * ans);
    }

    return ans;
}

int main()
{
	int a, b;
    scanf("%d%d", &a, &b);

	cout << "For a and b: " << lcm3(a,b) << endl;

	int arr[] = { 2, 7, 3, 9, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "For array: " << findLCM(arr, n) << endl;

	return 0;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
