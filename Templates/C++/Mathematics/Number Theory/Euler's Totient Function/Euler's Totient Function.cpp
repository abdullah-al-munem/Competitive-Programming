//https://primefan.tripod.com/Phi500.html - check phi value and divisors

#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <bitset>
#include<vector>
#include <algorithm>
using namespace std;

#define Freed freopen ("0in.txt","r",stdin);
#define Fout freopen ("0out.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define MAXLIMIT 1000008
#define ll long long int

ll phiArr[1000008];

//sieve O(n*log n)
bool mark[1000008];
void sieve(int n);

// O(n*log n) without sieve
// O(n log log n) total runtime
void sievePhi(int n){

    sieve(n);
    //initialization
    for(int i=2; i<=n; i++) phiArr[i]=i;

    phiArr[1] = 1;
    for(int i=2; i<=n; i++)
    {
        if(!mark[i])
            for(int j=i; j<=n; j+=i){
                // phi(n) = n*(1-(1/p)) -> as the formula of phi
                phiArr[j] = (phiArr[j]*(i-1))/i;
            }

    }

    printf("Phi of the numbers in range %d is: \n", n);
    for(int i=1; i<=n; i++){
        //cout << phi[i] << " ";
        printf("Phi(%d) = %d\n",i,phiArr[i]);
    }

}

void checkPhi(int a){
    printf("Phi(%d) = %d\n",a,phiArr[a]);
}

// O(sqrt(n))
int phiOfN(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // i is a prime divisor of n
            while (n % i == 0){
                // divide all the factors of i
                n /= i;
            }
            // same as: result * (1-1/p)
            result -= result / i;
        }
    }
    if (n > 1){
        //the last prime divisor
        result -= result / n;
    }

    return result;
}

int gcd(int a, int b);
//normal (bad) approach, O(n Log n)
int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}


int main()
{
	int n;
    //scanf("%d",&n);
    //sievePhi(2);
    cout << phiOfN(100) << endl;
    sievePhi(100);
    checkPhi(4);
    checkPhi(69);
    //cout << phi[4] << endl;
	return 0;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void sieve(int n)
{
    mark[0]=mark[1]=1;
    for(int i=4; i<=n; i+=2) mark[i] = 1;


    for(int i=3; i*i<=n; i+=2)
    {
        if(mark[i]) continue;
        for(int j=i*i; j<=n; j+=2*i)
        {
            mark[j] = 1;
        }
    }

}

