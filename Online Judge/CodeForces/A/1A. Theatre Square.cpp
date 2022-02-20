#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    long long int n,m, a;
    cin >> n >> m >> a;
    long long int sum = 0;
    if(n%a==0 && m%a == 0){
        sum = (n*m)/(a*a);
    }
    else if(n%a==0 && m%a != 0){
        long long int x = (m/a)+1;
        m = a*x;
        sum = (n*m)/(a*a);
    }
    else if(n%a != 0 && m%a == 0){
        long long int x = (n/a)+1;
        n = a*x;
        sum = (n*m)/(a*a);
    }
    else if(n%a != 0 && m%a != 0){
        long long int x = (n/a)+1;
        long long int x2 = (m/a)+1;
        n = a*x;
        m = a*x2;
        sum = (n*m)/(a*a);

    }
    cout << sum <<endl;

    return 0;
}
