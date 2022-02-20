#include <bits/stdc++.h>
using namespace std;

int nod[100105];
int sod[100105];
int pod[100105];
void sieve(int n){
    for(int i=2; i<=n; i++){
        nod[i] = 0;
        sod[i] = 0;
        pod[i] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            nod[j]++;
            sod[j] += i;
            pod[j] *= i;
        }
    }
}

int findNOD(int a){
    return nod[a];
}

int findSOD(int a){
    return sod[a];
}

int findPOD(int a){
    return pod[a];
}

int main(){

    int a;
    cin >> a;
    sieve(a);
    cout << "Enter a number between 1 to " << a << ": ";
    cin >> a;
    cout << "NOD: " << findNOD(a) << endl;
    cout << "SOD: " << findSOD(a) << endl;
    cout << "POD: " << findPOD(a) << endl;

}


