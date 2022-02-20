#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int dis[10005];
int par[10005];

void bfs(int n, vector<int> adj[], int src){
    for(int i=0; i<=n; i++){
        dis[i] = INF;
    }

    dis[src] = 0;
    par[src] = src;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(dis[v] == INF){
                dis[v] = dis[u]+1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void path_print(int src, int dest){
    if(dest == src){
        cout << src;
        return;
    }
    path_print(src, par[dest]);
    cout << " " << dest;
}

int main(){
    vector<int> adj[10005];
    int n, e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin >> s;
    int arr[s];
    for(int i=0; i<s; i++){
        cin >> arr[i];
        adj[0].push_back(arr[i]);
        adj[arr[i]].push_back(0);
    }
    bfs(n, adj, 0);
    int dest;
    cin >> dest;
    path_print(0, dest);
    cout << endl;
    cout << dis[dest] << endl;


    return 0;
}
