#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> adj[10005];
bool hasCycle = false;
int col[10005];
int dfs(int u){
    col[u] = GREY;
    int v;
    for(int i=0; i<adj[u].size(); i++){
        v = adj[u][i];
        if(col[v] == WHITE)
            dfs(v);
        if(col[v] == GREY)
            hasCycle = true;
    }
    col[u] = BLACK;
}

int main(){

    int n, e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(col[i] == WHITE)
            dfs(i);
    }

    if(hasCycle)
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}
