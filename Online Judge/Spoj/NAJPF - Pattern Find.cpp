#include <bits/stdc++.h>
using namespace std;

vector<int> rabin_karp(string const& str, string const& ptn) {
    const int base = 31;
    const int mod = 1e9 + 9;
    int ptnlen = ptn.size(), strlen = str.size();

    vector<long long> b_pow(max(strlen, ptnlen));
    b_pow[0] = 1;
    for (int i = 1; i < (int)b_pow.size(); i++)
        b_pow[i] = (b_pow[i-1] * base) % mod;

    vector<long long> hashText(strlen + 1, 0);
    for (int i = 0; i < strlen; i++)
        hashText[i+1] = (hashText[i] + (str[i] - 'a' + 1) * b_pow[i]) % mod;
    long long hashPattern = 0;
    for (int i = 0; i < ptnlen; i++)
        hashPattern = (hashPattern + (ptn[i] - 'a' + 1) * b_pow[i]) % mod;

    vector<int> occurences;
    for (int i = 0; i + ptnlen - 1 < strlen; i++) {
        long long curr_hash = (hashText[i+ptnlen] + mod - hashText[i]) % mod;
        if (curr_hash == hashPattern * b_pow[i] % mod)
            occurences.push_back(i);
    }
    return occurences;
}


int main(){

    int t;
    cin >> t;
    while(t--){
        string str, ptn;
        cin >> str >> ptn;
        vector<int> occurences = rabin_karp(str, ptn);
        if(occurences.empty())
            cout << "Not Found\n";
        else{
            cout << occurences.size() << "\n";
            for(int i=0; i<occurences.size(); i++)
                cout << occurences[i]+1 << " ";
            cout << endl;
        }
        if(t)
            cout << endl;
    }

    return 0;
}

