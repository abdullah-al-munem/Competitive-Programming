#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
vector<bool> isPrime(N+1, true);
vector<int> primes;

void sieve(int n){

    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=2; i<n; i++){
        if(isPrime[i])
            primes.push_back(i);
    }
    for (int p = 0; p < primes.size(); p+=100)
        cout << primes[p] << endl;

}

int main(){
    sieve(N);
    return 0;
}

