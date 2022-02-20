#include <stdio.h>
#include <string.h>
#include <iostream>
#include<map>
using namespace std;
#define ll long long int

#define BASE 27
#define M 1000000007
int pHashing(string s){

    long long int val = 0;
    for(int i = 0; s[i] != '\0'; i++){

        val *= BASE;
        val %= M;
        val += s[i]-'a'+1;
        val %= M;
    }
    return val;

}

#define BASE1 27
#define BASE2 31
#define M1 1000000007
#define M2 500000003

pair<long long int, long long int> doubleHashing(string s){

    long long int val1 = 0;
    long long int val2 = 0;
    for(int i = 0; s[i] != '\0' ; i++){

        val1 *= BASE1;
        val1 %= M1;
        val1 += s[i]-'a'+1;
        val1 %= M1;

        val2 *= BASE2;
        val2 %= M2;
        val2 += s[i]-'a'+1;
        val2 %= M2;
    }

    return {val1, val2};

}



int main(){

    int i;
    string s;
    cin >> s;

    ll a = pHashing(s);
    pair<ll, ll> b = doubleHashing(s);

    cout << a << endl;
    cout << b.first << " " << b.second << endl;


    map<ll, string> mp;
    map<ll, string>::iterator itr;

    mp[a] = s;

    for(auto itr: mp){
        cout << itr.first << " " << itr.second << endl;
    }


    return 0;
}
