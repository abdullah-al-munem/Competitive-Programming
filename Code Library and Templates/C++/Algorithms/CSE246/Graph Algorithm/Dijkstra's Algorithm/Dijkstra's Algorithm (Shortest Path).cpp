#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, e;
vector<int> adj[10005];
vector<int> adjw[10005];
int dis[10005];
int vis[10005];

struct Element{
    int nd;
    int path_cost;

    Element(int _nd, int _path_cost){
        nd = _nd;
        path_cost = _path_cost;
    }

    bool operator <(const Element &a)const{
        return path_cost < a.path_cost;
    }
    bool operator >(const Element &a)const{
        return path_cost > a.path_cost;
    }


};

priority_queue< Element, vector<Element>, greater<Element> > pq;


void init(int s){
    for(int i=1; i<=n; i++){
        dis[i] = INF;
        vis[i] = 0;
    }

    dis[s] = 0;
    pq.push(Element(s, 0));

}

void dijkstra(int src){
    init(src);
    int u, v, w;
    while(!pq.empty()){
        Element node = pq.top();
        pq.pop();
        u = node.nd;
        if(vis[u] == 1)
            continue;
        vis[u] = 1;
        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i];
            w = adjw[u][i];
            if((dis[u]+w)<dis[v]){
                dis[v] = dis[u]+w;
                pq.push(Element(v, dis[v]));
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<< src <<" --> " << i << " = " << dis[i] << endl;
    }
}

int main(){

    cin >> n >> e;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graphs only
        adjw[u].push_back(w);
        adjw[v].push_back(w); // for undirected graphs only
    }

    dijkstra(1);
    cout << dis[n] << endl;
    return 0;
}
