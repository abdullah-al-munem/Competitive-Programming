#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll totalComma(ll num){
    ll m, count = 0, i=1, total = 0;
    ll tmp = num;
    if(num <= 999)
        return total;

    /*
    while(num >= 999){
        i++;
        if(i%3==0)
            count++;

        num /= 1000;

    }*/

    if(num <= 999999){
        total = num - 999;
    }
    else if(num <= 999999999){
        total += 999000;
        total += (num - 999999) * 2;
    }
    else if(num <= 999999999999) {
        total += 999000;
        total += 999000000 * 2;
        total += (num - 999999999) * 3;
    }
    else if(num <= 999999999999999){
        total += 999000;
        total += 999000000 * 2;
        total += 999000000000 * 3;
        total += (num - 999999999999) * 4;
    }
    else {
        total += 999000;
        total += 999000000 * 2;
        total += 999000000000 * 3;
        total += 999000000000000 * 4;
        total += (num - 999999999999999) * 5;
    }


    return total;
}


int main()
{
	ll n;
	cin >> n;

	ll total = totalComma(n);

	cout << total << endl;

	return 0;
}

