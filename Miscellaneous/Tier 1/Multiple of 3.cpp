#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// with cycle approach
bool multipleOfThree(ll k, ll d0, ll d1)
{

	ll sum = d0 + d1;
    ll totalSum = sum;

	if (k == 2) {
		if (totalSum % 3 == 0)
			return true;
		else
			return false;
	}
	// addition of all digits with cycles
	ll oneCycleSum = (2*sum) % 10 + (4*sum) % 10 + (8*sum) % 10 + (6*sum) % 10;

    totalSum += (sum % 10);

	ll numberofCycles = (k - 3) / 4;
    // total element in a cycle is 4
	ll numberofDigitsLeft = (k - 3) - (numberofCycles*4);

	totalSum += oneCycleSum * numberofCycles;

    int m = 2;
	for (ll i = 0; i < numberofDigitsLeft; i++) {
		totalSum += ((m%10) * (sum%10)) % 10;
		m *= 2;
	}
	if (totalSum % 3 == 0)
		return true;
	else
		return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll k, d0, d1;
        cin >> k >> d0 >> d1;
        if(multipleOfThree(k,d0,d1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
