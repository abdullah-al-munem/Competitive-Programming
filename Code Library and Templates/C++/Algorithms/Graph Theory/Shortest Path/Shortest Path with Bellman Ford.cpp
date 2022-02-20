#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define infinity 1<<28
#define mx 100

void bellman(vector<int>g[], vector<int>cost[], int n, int source,
             int distance, int parent[], int dist[]){

    for(int i=1;i<=n;i++){
        dist[i] = infinity;
        parent[i] = -1;
    }
    dist[source] = 0;
    bool neg_cycle = false;

    for(int k=1;k<=n;k++){
        bool updated = false;
        for(int u=1;u<=n;u++){
            for(int i=0;i<(int)g[u].size();i++){
                int v = g[u][i];
                //Relaxation
                if(dist[u] + cost[u][i] < dist[v]){
                    updated = true;
                    dist[v] = dist[u] + cost[u][i];
                    parent[g[u][i]] = u;
                }
            }
        }

        if(k==n and updated==true){ //update in the n^th iteration
            neg_cycle = true;
        }
    }
    if(neg_cycle)puts("Negative cycle detected");
    else
    {
        for(int i=1;i<=n;i++){
            cout<<source<<" --> "<<i<<" = "<<dist[i]<<endl;
        }
    }
}

void printShortestDistance(vector<int> adj[], vector<int>cost[], int s, int dest, int v)
{
	int parent[v+1], dist[v+1];

	bellman(adj, cost, v, s, dest, parent, dist);

	vector<int> path;
	int crawl = dest;
	//cout << "crawl: " << crawl <<endl;
	path.push_back(crawl);
	//int i=0;
	while (parent[crawl] != -1) {
		path.push_back(parent[crawl]);
		crawl = parent[crawl];
		//cout << "crawl "<< i << ": " << crawl <<endl;
		//i++;
	}

	cout << "Shortest path length is : " << dist[dest] <<endl;

	cout << "Path is: ";
	for (int i = path.size() - 1; i >= 0; i--){
        cout << path[i];
        if(i!=0){
            cout << " -> ";
        }
	}
    cout << endl;
}

int main(){

    vector<int>g[10000],cost[10000];
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;


    for(int i=0;i<numEdges;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    int source, dist;
    cin>>source>>dist;
    //bellman(numNodes, g, cost, source);
    printShortestDistance(g, cost, source, dist, numNodes);

    return 0;
}

