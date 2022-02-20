#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2
const int MAXN = 1e5 + 3;
vector< int > G[MAXN];
vector< int > children[MAXN];
bitset<MAXN> arr;
int color[MAXN];
int count1, bitCount[MAXN] = {0}, maxCount[MAXN] = {0};

int isLeaf(int u){
    if(children[u].size() == 0)
		return 1;
    else
        return 0;
}

void dfsUntil(int u, int par, int n, int e) {

    if(arr[u]==1){
        bitCount[u] = 1 + ((arr[par])? bitCount[par] : 0);
    }
    else
        bitCount[u] = 0;

    maxCount[u] = max(bitCount[u], maxCount[par]);

    bool isLeaf = true;
	color[u] = GREY;
    //int v;
	for(int i = 0; i<(int)G[u].size(); i++) {
		int v = G[u][i];
		//if color[v] is grey, it is a back edge
		//if color[v] is white, it is a tree edge
		if(color[v] == WHITE && v != par) {
			dfsUntil(v,u,n,e);
			isLeaf = false;
		}
	}

    if(isLeaf and maxCount[u] <= e){
        count1++;
        //cout << "Lu: " << u << endl;
    }

    //cout << "u: " << u << endl;
	color[u] = BLACK;

}

void dfs(int n,int e){
    for(int i=1;i<=n;i++){
		color[i] == WHITE;
	}

    dfsUntil(1,0,n,e);
}


int main(){

    int n, e;
	cin>>n>>e;
	for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        //cout << i << " " << arr[i] << endl;
	}

	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		children[u].push_back(v);
	}
	dfs(n,e);

	cout << count1 <<endl;
    return 0;
}


