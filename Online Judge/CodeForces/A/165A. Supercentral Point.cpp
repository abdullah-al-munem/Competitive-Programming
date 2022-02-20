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

	int n;
	cin>>n;
	int arr[n][2];
	for(int i=0;i<n;i++){
	    for(int j=0;j<2;j++){
	        cin>>arr[i][j];
	    }
	}
	int ct=0;
	for(int i=0;i<n;i++){
	    int x=arr[i][0], y=arr[i][1];
	    int left=0,right=0,up=0,below=0;
	    for(int j=0;j<n;j++){
	        if(x<arr[j][0] && y==arr[j][1])
	            right++;
	        else if(x>arr[j][0] && y==arr[j][1])
	            left++;
	        else if(x==arr[j][0] && y<arr[j][1])
	            up++;
	        else if(x==arr[j][0] && y>arr[j][1])
	            below++;

	        if(right>0 && left>0 && up>0 && below>0){
                ct++;
                break;
	        }
	    }
	}
	cout<< ct << endl;
    return 0;
}
