#include <bits/stdc++.h>
using namespace std;

#define mset(a,v) memset(a,v,sizeof(a))
bitset<20> remaining;
void permute(int n, int pos, int fixed[]){
    if(pos == n){
        for(int i=0; i<n; i++)
            cout << fixed[i] << " ";
        cout << endl;
        return;
    }

    for(int i=1; i<=n; i++){
        if(!remaining[i]){
            fixed[pos] = i;
            //cout << "pos: " << pos << endl;
            remaining[i] = 1;
            permute(n, pos+1, fixed);
            remaining[i] = 0;
        }
    }

}

int main(){
    int n;
    cin >> n;
    int fixed[n];
    permute(n, 0, fixed);
    return 0;
}
