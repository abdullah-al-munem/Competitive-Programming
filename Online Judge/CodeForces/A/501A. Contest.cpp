#include <bits/stdc++.h>
using namespace std;

const int DEBUGGER = 0;
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define Fin freopen("0in.txt","r",stdin);
#define Fout freopen("0out.txt","w",stdout);
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define uset unordered_set<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define r(a) a.begin(),a.end()
#define mset(a,v) memset(a,v,sizeof(a))
#define mset2(a,v) memset(&a,v,sizeof(a))
#define dsort(a) sort(a,a+n,greater<int>())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define dbg(a) if(DEBUGGER)cout<<#a<<" = "<<a<<endl
#define M_PI 3.14159265358979323846
#define Mod 1000000007

int main(){

    int a, b, c, d, a1, a2, ans1, b1, b2, ans2;
	cin >> a >> b >> c >> d;
	a1 = 3*a/10;
	a2 = a-((a/250)*c);
	ans1 = max(a1, a2);
	b1 = 3*b/10;
	b2 = b-((b/250)*d);
	ans2 = max(b1, b2);
	if(ans1 > ans2)
		cout << "Misha\n";
	else if(ans1 < ans2)
		cout << "Vasya\n";
	else
		cout << "Tie\n";


    return 0;
}

