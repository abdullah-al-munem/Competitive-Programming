// CPP program to count the
// number of numbers between
// 1 and 1000, including both,
// that are divisible by 3 or 4
#include <bits/stdc++.h>
using namespace std;

// function to count the divisors (for two numbers)
int countDivisors(int N, int a, int b)
{
	// Counts of numbers
	// divisible by a and b
	int count1 = N / a;
	int count2 = N / b;

	// inclusion-exclusion
	// principle applied
	int count3 = (N / (a * b));

	return count1 + count2 - count3;
}

// function to count the number
// of numbers in range 1-M that
// are divisible by given N (more than two)
// prime numbers
int count(int a[], int m, int n)
{
    int odd = 0, even = 0;
    int counter, i, j, p = 1;
    int pow_set_size = (1 << n);

    // Run from counter 000..0 to 111..1
    for (counter = 1; counter < pow_set_size; counter++) {
        p = 1;
        for (j = 0; j < n; j++) {

            // Check if j th bit in the
            // counter is set If set
            /// then pront j th element from set
            if (counter & (1 << j)) {
                p *= a[j];
            }
        }

        // if set bits is odd, then add to
        // the number of multiples
        // __builtin_popcount is a function of GCC.
        // __builtin_popcount(int) function is used to count the number of one’s(set bits) in an integer.
        //It returns the numbers of set bits in an integer
        //(the number of ones in the binary representation of the integer).
        if (__builtin_popcount(counter) & 1)
            odd += (m / p);
        else
            even += (m / p);
    }

    return odd - even;
}


// Driver Code
int main()
{
	int N = 1000, a = 3, b = 4;
	cout << countDivisors(N, a, b) << endl;

	int arr[] = { 2, 3, 5, 7 };
    int m = 100;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << count(arr, m, n) << endl;
	return 0;
}

