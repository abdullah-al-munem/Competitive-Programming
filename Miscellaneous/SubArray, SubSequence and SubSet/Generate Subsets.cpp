#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n;
vector<int> v, v2;

void printV(vector<int> v){
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void generateSubsets(int p){
    if(p==n){
        printV(v2);
        return;
    }

    v2.pb(v[p]);
    generateSubsets(p+1);
    v2.pop_back();
    generateSubsets(p+1);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.pb(a);
    }
    generateSubsets(0);

    return 0;
}
