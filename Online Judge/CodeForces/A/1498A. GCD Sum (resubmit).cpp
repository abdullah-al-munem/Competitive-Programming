#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int sum = 0, p1,p2;
    if(n%m == 0){
        int rm = n/m;
        p1 = rm*b;
        int tmp = n*a;
        p1 = min(tmp,p1);
    }
    else{
        int rm = (n/m)+1;
        p1 = rm*b;
        int tmp = n*a;
        p1 = min(tmp,p1);
    }

    double perRideM = (double)b/m;
    //cout << "perRideM: " << perRideM << endl;
    if(perRideM<=a){
        if(m<=n){
            int rm = n/m;
            //cout << "rm: " << rm << endl;
            int rmp = rm*b;
            //cout << "rmp: " << rmp << endl;
            sum += rmp;
            n -= rm*m;
            //cout << "n: " << n << endl;
            sum += n*a;
            //cout << "sum: " << sum << endl;
        }
        else{
            sum = p1;
        }
    }
    else{
        sum += n*a;
        //cout << "sum: " << sum << endl;
    }

    p2 = min(p1,sum);

    cout << p2 << endl;

    return 0;
}
