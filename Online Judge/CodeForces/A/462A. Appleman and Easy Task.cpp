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

    int n;
    cin >> n;
    char board[n][n];
    bool even = true;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - 1 >= 0 and board[i - 1][j] == 'o')
                c++;
            if (i + 1 < n and board[i + 1][j] == 'o')
                c++;
            if(j - 1 >= 0 and board[i][j - 1] == 'o')
                c++;
            if(j + 1 < n and board[i][j + 1] == 'o')
                c++;
            if (c % 2 == 1){
                even = false;
                break;
            }
        }
        if(!even)
            break;
    }

    if (even)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

