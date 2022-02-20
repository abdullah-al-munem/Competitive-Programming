#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> adj[10005];
int col[10005];
int d[10005];
int f[10005];
int tme;

int dfs(int u){
    col[u] = GREY;
    tme++;
    d[u] = tme;
    int v;
    for(int i=0; i<adj[u].size(); i++){
        v = adj[u][i];
        if(col[v] == WHITE){
            cout << u << " -> " << v << " -- Tree edge\n";
            dfs(v);
        }
        else if(col[v] == GREY)
            cout << u << " -> " << v << " -- Back edge\n";
        else{
            if(d[u]<d[v])
                cout << u << " -> " << v << " -- Forward edge\n";
            else
                cout << u << " -> " << v << " -- Cross edge\n";
        }
    }
    col[u] = BLACK;
    tme++;
    f[u] = tme;
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

    dfs(1);


    return 0;
}
