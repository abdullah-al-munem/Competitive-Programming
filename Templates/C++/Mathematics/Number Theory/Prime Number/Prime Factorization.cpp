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

void primeFactorize1(int n){
    // at first generate the prime array
    sieve(n);

	listSize = 0;

	for(int i=0; prime[i] <= n; i++){
        if(n%prime[i] == 0){
            while(n%prime[i] == 0){
                n /= prime[i];
                List[listSize] = prime[i];
                listSize++;
            }
        }

	}

    for(int i=0; i<listSize; i++)
        printf("%d ", List[i]);
    printf("\n");

}


void primeFactorize2(int n){
    // at first generate the prime array
    sieve(n);

    if(prime[nPrime-1] == n){
        cout << "Prime Factor: ";
        cout << n << endl;
        return;
    }

	listSize = 0;
	int limit = sqrt(n)+2;
	// we can also use " prime[i] <= n " or " n != 1 " in this loop as condition
	// but this is the best approach and more efficient, time complexity __
	for(int i=0; prime[i] <= limit; i++){
        if(n%prime[i] == 0){
            while(n%prime[i] == 0){
                n /= prime[i];
                List[listSize] = prime[i];
                listSize++;
            }
        }

	}

    if(n>1){
        List[listSize] = n;
        listSize++;
    }

    cout << "Prime Factors: ";
    for(int i=0; i<listSize; i++)
        printf("%d ", List[i]);
    printf("\n");

}

int main()
{
	int n;
    scanf("%d",&n);
	primeFactorize2(n);
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

