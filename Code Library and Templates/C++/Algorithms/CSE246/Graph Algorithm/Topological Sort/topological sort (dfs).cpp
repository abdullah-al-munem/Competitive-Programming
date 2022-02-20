#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> adj[10005];
vector<int> topOrder;
int col[10005];
int dfs(int u){
    col[u] = GREY;
    int v;
    for(int i=0; i<adj[u].size(); i++){
        v = adj[u][i];
        if(col[v] == WHITE)
            dfs(v);
    }
    col[u] = BLACK;
    topOrder.push_back(u);
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

    reverse(topOrder.begin(),topOrder.end());
    for(int i=0; i<n; i++)
        cout << topOrder[i] << " ";
    cout << endl;

    return 0;
}
