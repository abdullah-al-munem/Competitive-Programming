#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<vector>
#include <algorithm>
using namespace std;

int prime[300000], nPrime;
int mark[1000002];

int List[128];
int listSize;

void sieve(int n);

int numberOfDivisors(int n) {
    sieve(n);
    int divisor = 1;
    for (int i = 0; i < nPrime; i++) {
        if (n % prime[i] == 0) {
            // +1 as formula, if we initial it to 0 then we have to add 1 later
            int cnt = 1;
            while (n % prime[i] == 0) {
                n /= prime[i];
                cnt++;
            }
            divisor *= cnt; // formula of NOD
        }
    }
    return divisor;

}

// we can also use " prime[i] <= n " or " n != 1 " in the for loop as condition
// but this is the best approach and more efficient, time complexity __
int SOD( int n ) {
    sieve(n);
    int res = 1;
    int sqrtn = sqrt (n)+1;
    for ( int i = 0; i < nPrime && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); // Need to multiply (p^0+p^1)
    }
    return res;
}

int sumOfDivisors(int n){
    sieve(n);
    int totalSum = 1;
    for (int i = 0; i < nPrime; i++) {
        if (n % prime[i] == 0) {
            int cnt = 1;
            while(n % prime[i] == 0) {
                n /= prime[i];
                cnt++;
            }
            // formula of SOD
            // +.5 for desired output, because sometimes pow() doesn't work properly
            totalSum *= ((pow(prime[i], cnt)+.5)-1) / (prime[i]-1);
            //cout << "prime[i]: " << prime[i] << endl;
            //cout << "cnt: " << cnt << endl;
            //cout << "totalSum: " << totalSum << endl;
        }
    }
    return totalSum;


}

int main()
{
	int a;
    scanf("%d",&a);
	cout << "Total Number Of Divisors divisor for " << a << " is: " << numberOfDivisors(a) << endl;
	//cout << "Sum Of Divisors divisor for " << a << " is: " << SOD(a) << endl;
	cout << "(issue)Sum Of Divisors divisor for " << a << " is: " << sumOfDivisors(a) << endl;

	return 0;
}


void sieve(int n){

    int i, j;
    int limit = sqrt(n)+2;

    // 1 is not prime.
    mark[1] = 1;
    // almost all the evens are not prime.
    for(i=4; i<=n+1; i += 2)
        mark[i] = 1;

    // 2 is prime
    prime[nPrime++] = 2;
    // run loop only for odds
    for(i=3; i<n+1; i+=2){
        //only prime i can be enter
        if(!mark[i]){
            //i is prime
            prime[nPrime++] = i;
            // i*i can be overflow
            if(i <= limit){
                // for cutting all odd multiples of i greater then i*i
                for(j = i*i; j<=n; j += i*2){
                    // mark[j] is not prime
                    mark[j] = 1;
                }
            }
        }
    }

}

