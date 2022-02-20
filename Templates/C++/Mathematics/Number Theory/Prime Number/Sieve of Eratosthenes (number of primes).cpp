#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;

//n of prime is n/10 of mark (original range n)
int prime[300000], nPrime;
int mark[1000002]; // we can use bitset also

// O(n*log log n)
void sieve(int n){

    int i, j;
    int limit = sqrt(n)+2;

    // 1 is not prime.
    mark[1] = 1;
    // almost all the evens are not prime.
    for(i=4; i<=n; i += 2)
        mark[i] = 1;

    // 2 is prime
    prime[nPrime++] = 2;
    // run loop only for odds
    for(i=3; i<n; i+=2){
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

    printf("The total number of Primes in range %d is: %d\n", n, nPrime);
    // Print all prime numbers
    for (int p = 0; p < nPrime; p++)
        cout << prime[p] << " ";
    cout << endl;


}

void isPrime(int a){
    if(!mark[a])
        cout << "Prime!\n";
    else
        cout << "Not Prime!\n";

}

int main(){

    int a;
    cin >> a;
    sieve(a);
    cout << "Enter a number between 1 to " << a << ": ";
    cin >> a;
    isPrime(a);

    return 0;
}



