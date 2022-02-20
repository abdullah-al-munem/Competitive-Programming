#include <bits/stdc++.h>
using namespace std;

// naive approach
// O(2^n) -> exponential time complexity
int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}

#define MAX_N 20
#define EMPTY_VALUE -1

// Memoization Technique
int memo[MAX_N + 1];

void init() {
  for (int i = 0; i <= MAX_N; i++) {
      memo[i] = EMPTY_VALUE;
  }
}

// using dynamic programming method (approach)
// O(n) -> polynomial time complexity
// recursive
int fib_2(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // check the n (subproblem) is already in memo or not
    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fib_2(n - 1) + fib_2(n - 2);
    return memo[n];
}

//iterative
/*
int f(int n) {
    memo[0] = 0;
    memo[1] = 1;
    for(int i = 2;i <= n;i++) {
        memo[n] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}
*/

int main()
{
    init();
    //memset(memo, EMPTY_VALUE, MAX_N);
    int n;
    while(cin >> n){
        if(n==-1)
            break;
        cout << fib_2(n) << endl;
    }


	return 0;
}

