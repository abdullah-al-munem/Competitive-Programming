// Super fast & Memory-tight Sieve by Yarin
// Memory Efficient Sieve
// http://saifsust.blogspot.com/2012/01/super-fast-memory-tight-sieve-by-yarin.html
// https://github.com/mejibyte/competitive_programming/blob/master/lib/Documentation/9thinksYouNeed-ACMSolver/sieve%20by%20yarin.cpp

#include <bits/stdc++.h>
#include<math.h>
#include <algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MAXSIEVE 100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

long long int prime[MAXSIEVE/16+2], nPrime;

//have to check for even numbers
void sieve(int n)
{
    // for even
	int i,j;
	memset(a,255,sizeof(a));
	a[0]=0xFE;
	for(i=1;i<MAXSQRT;i++)
		if (a[i>>3]&(1<<(i&7)))
			for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
				a[j>>3]&=~(1<<(j&7));


    prime[nPrime++]=2;
    // for odd
    for(i=3;i<n;i+=2)
    {
        if(isprime(i))
        {
            prime[nPrime++]=i;
            //printf("Total prime:%d %d\n",nPrime,prime[nPrime-1]);
        }
    }

    printf("The total number of Primes in range %d is: %d\n", n, nPrime);
    // Print all prime numbers
    for (int p = 0; p < nPrime; p++)
        cout << prime[p] << " ";
    cout << endl;

}

int main(){

    int a;
    cin >> a;
    sieve(a);
    return 0;
}


