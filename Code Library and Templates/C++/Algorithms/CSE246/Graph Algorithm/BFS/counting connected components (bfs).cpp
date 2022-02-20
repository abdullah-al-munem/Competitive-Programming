#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

vector<int> adj[10005];
int dis[10005];

void bfs(int src){

    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(dis[v] == INF){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
}

int connectedComponents(int n){
    for(int i=1; i<=n; i++){
        dis[i] = INF;
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] == INF){
            bfs(i);
            cnt++;
        }
    }
    return cnt;
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

    cout << connectedComponents(n) << endl;

    return 0;
}
