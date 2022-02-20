#include <bits/stdc++.h>
using namespace std;

bool isPrime[100105];
void sieve(int n){
    for(int i=2; i<=n; i++){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            for(int j=i*2; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void isPrime1(int a){
    if(isPrime[a])
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
    isPrime1(a);

}


