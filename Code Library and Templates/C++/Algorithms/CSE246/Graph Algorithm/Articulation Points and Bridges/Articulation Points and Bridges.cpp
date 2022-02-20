#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> adj[10005];
int col[10005];
int d[10005];
int low[10005];
int tme;

void dfs(int p, bool isRoot, int parent){
    tme++;
    d[p] = tme;
    low[p] = d[p];
    col[p] = GREY;

    bool isArticulationPoint = false;
    int childCount = 0;
    for(int i=0; i<adj[p].size(); i++){
        int c = adj[p][i];
        if(col[c] == WHITE){
            dfs(c, false, p);
            if(d[p] < low[c])
                cout << p << " -- " << c << " is a bridge\n";
            if(d[p] <= low[c])
                isArticulationPoint = true;
            if(low[c] < low[p])
                low[p] = low[c];
            childCount++;
        }

        if(col[c] == GREY && c != parent){
            if(d[c] < low[p])
                low[p] = d[c];
        }
    }

    if(isRoot){
        if(childCount > 1)
            cout << p << " is an articulation point.\n";
    }
    else if(isArticulationPoint)
        cout << p << " is an articulation point.\n";

    col[p] = BLACK;
}

int main(){

    int n, e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, true, -1);

    return 0;
}
