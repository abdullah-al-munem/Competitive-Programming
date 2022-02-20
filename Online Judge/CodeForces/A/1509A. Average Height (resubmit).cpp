#include <bits/stdc++.h>
using namespace std;
#define pb push_back

bool cmp(int a, int b){
    return (a&1) > (b&1);
}

int main(){

    int t, cs = 1;
    cin >> t;
    while(t--){
        int n;
        cin>> n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v.pb(a);
        }
        sort(v.begin(), v.end(), cmp);

        for(int i=0; i<n; i++)
            cout << v[i] << " ";
        cout << endl;
    }


    return 0;
}
