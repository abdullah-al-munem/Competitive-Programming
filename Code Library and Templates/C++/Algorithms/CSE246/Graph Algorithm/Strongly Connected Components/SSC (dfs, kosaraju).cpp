#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> adj[10005];
vector<int> rev[10005];

vector<int> topOrder;
int col[10005];
int flg;
int dfs(int u, vector<int> adj[]){
    if(flg)
        cout << u << " ";
    col[u] = GREY;
    int v;
    for(int i=0; i<adj[u].size(); i++){
        v = adj[u][i];
        if(col[v] == WHITE)
            dfs(v, adj);
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
        rev[v].push_back(u);
        //adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(col[i] == WHITE)
            dfs(i, adj);
    }

    reverse(topOrder.begin(),topOrder.end());
    memset(col,WHITE,sizeof(col));
    int ct=0;
    cout<<"Strongly Connected Components are:\n";
    flg=1;
    for(int i=0; i<n; i++){
        int u = topOrder[i];
        if(col[u] == WHITE){
            dfs(u, rev);
            ct++;
            cout << endl;
        }
    }
    cout<<"Total SSCs: " << ct << endl;
    //cout << ct << endl;

    return 0;
}

