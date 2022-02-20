#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<vector>
#include <algorithm>
using namespace std;

// O(sqrt(n))
void printDivisors(int n)
{
    // Vector to store half of the divisors
    vector<int> v;
    int limit = sqrt(n+1);
    for (int i = 1; i <= limit; i++) {
        if (n % i == 0) {

            // check if divisors are equal
            if (n / i == i)
                printf("%d ", i);
            else {
                printf("%d ", i);

                // push the second divisor in the vector
                v.push_back(n / i);
            }
        }
    }

    // The vector will be printed in reverse
    for (int i = v.size() - 1; i >= 0; i--)
        printf("%d ", v[i]);

    cout<<endl;
}


// O(n)
int countDivisor1(int n) {
    int divisor = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisor++;
        }
    }
    return divisor;
}

// O(sqrt(n))
int countDivisor2(int n) {
    int divisor = 0;
    int limit = sqrt(n+1);
    for (int i = 1; i <= limit; i++) {
        if (i == sqrt(n)) {
            divisor += 1;
        }
        else if (n % i == 0) {
            divisor += 2;
        }
    }
    return divisor;
}

/*
int countDivisor2(int n) {
  int divisor = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      divisor += 1;
    } else if (n % i == 0) {
      divisor += 2;
    }
  }
  return divisor;
}
*/

int divisorSumOfRangeN(int n)
{
    int sum = 0;

    for(int i = 1; i <= n; ++i)
    {

        // Find all divisors of i and add them
        for(int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                if (i / j == j)
                    sum += j;
                else
                    sum += j + i / j;
            }
        }
    }
    return sum;
}

int divisorSum(int n)
{
    int sum = 0;

    // Find all divisors of i and add them
    for(int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                sum += i;
            else
                sum += i + n / i;
        }
    }

    return sum;
}


int main() {

    int a;
    cin >> a;

    cout << "Total divisor of " << a << " is: " << countDivisor2(a) << endl;

    printDivisors(a);

    cout << "Sum of divisor for " << a << " is: " << divisorSum(a) << endl;

    return 0;
}
