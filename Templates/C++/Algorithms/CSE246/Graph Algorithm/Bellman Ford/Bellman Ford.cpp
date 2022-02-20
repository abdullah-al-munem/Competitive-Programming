#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, e;
vector<int> adj[10005];
vector<int> adjw[10005];
int dis[10005];

void init(int s){

    for(int i=1; i<=n; i++)
        dis[i] = INF;
    dis[s] = 0;
}

bool bellmanFord(int s){

    init(s);
    int v, w;
    for(int i=1; i<n; i++){ // Round
        for(int u=1; u<=n; u++){ // for each node
            for(int j=0; j<adj[u].size(); j++){ // for all edges of each node
                v = adj[u][j];
                w = adjw[u][j];
                if(dis[u]+w < dis[v]){ // edge relaxation
                    dis[v] = dis[u]+w;
                }
            }
        }
    }

    bool negCycle = false;
    // additional n-th round for checking negative cycle
    for(int u=1; u<=n; u++){ // for each node
        for(int j=0; j<adj[u].size(); j++){ // for all edges of each node
            v = adj[u][j];
            w = adjw[u][j];
            if(dis[u]+w < dis[v]){ // edge relaxation
                dis[v] = dis[u]+w;
                negCycle = true;
            }
        }
    }

    return negCycle;
}


int main(){

    cin >> n >> e;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        //adj[v].push_back(u); // for undirected graphs only
        adjw[u].push_back(w);
        //adjw[v].push_back(w); // for undirected graphs only
    }

    bool negCycle = bellmanFord(1);

    if(!negCycle)
        cout << dis[n] << endl;
    else
        cout << "Negative cycle found !" << endl;

    return 0;
}


/*
input:
6 8
1 2 2
1 6 8
1 4 5
2 3 2
4 5 10
4 3 -3
3 6 4
5 6 -15




*/
