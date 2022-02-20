#include <bits/stdc++.h>
#define Fin freopen("0in.txt","r",stdin);
#define Fout freopen("0out.txt","w",stdout);
#define ll long long int
#define pii pair<int, int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mset(a,v) memset(a,v,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define M_PI 3.14159265358979323846
#define Mod 1000000007
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int posi[2], posj[2], p1=0, p2=0;
        char str[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> str[i][j];
                if(str[i][j] == '*'){
                    posi[p1++] = i;
                    posj[p2++] = j;
                }
            }
        }

        if(posi[0] == posi[1]){
            if(posi[0] < n-1){
                str[posi[0]+1][posj[0]] = '*';
                str[posi[1]+1][posj[1]] = '*';
            }
            else{
                str[posi[0]-1][posj[0]] = '*';
                str[posi[1]-1][posj[1]] = '*';
            }
        }
        else if(posj[0] == posj[1]){
            if(posj[0] < n-1){
                str[posi[0]][posj[0]+1] = '*';
                str[posi[1]][posj[1]+1] = '*';
            }
            else{
                str[posi[0]][posj[0]-1] = '*';
                str[posi[1]][posj[1]-1] = '*';
            }
        }
        else{
            str[posi[1]][posj[0]] = '*';
            str[posi[0]][posj[1]] = '*';
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << str[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

