#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n;
    cin >> n;
    if(n<0){
        int tmp = abs(n);
        if(tmp<10)
            cout << "0" << endl;
        else{
            int m1 = tmp%10;
            tmp /= 10;
            int m2 = tmp%10;
            //cout << "m1 m2 -> " << m1 << " " << m2 << endl;
            if(m1>m2){
                n /= 10;
                cout << n << endl;
            }
            else{
                n = n / 100 * 10 + n % 10;;
                cout << n << endl;
            }
        }

    }
    else
        cout << n << endl;

    return 0;
}

