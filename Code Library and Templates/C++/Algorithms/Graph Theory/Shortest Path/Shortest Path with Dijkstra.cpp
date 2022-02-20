#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<30  //2^30
struct node{
    int u;
    int cost;
    node(int _u, int _cost){
        u = _u;
        cost = _cost;
    }
    bool operator < ( const node& p ) const {      return cost > p.cost;   } //Operator overloading

};

void dijstkra(vector<int>g[], vector<int>cost[], int n, int source,
              int distance, int parent[], int dist[]){


    for(int i=1;i<=n;i++) {
        dist[i] = infinity;
        parent[i] = -1;
    }

    priority_queue<node>q;
    q.push(node(source,0));
    dist[source] = 0;

    while(!q.empty()){
        node top = q.top();
        q.pop();
        int u=top.u;

        for(int i=0;i<(int)g[u].size();i++){
            int v=g[u][i];

            //Relaxation
            if(dist[u] + cost[u][i] < dist[v]){
                dist[v] = dist[u] + cost[u][i];
                parent[g[u][i]] = u;
                q.push(node(v, dist[v]));

            }

        }
    }
    for(int i=1;i<=n;i++){
        cout<<source<<" --> "<<i<<" = "<<dist[i]<<endl;
    }
}

void printShortestDistance(vector<int> adj[], vector<int>cost[], int s, int dest, int v)
{
	int parent[v+1], dist[v+1];

	dijstkra(adj, cost, v, s, dest, parent, dist);

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

    vector<int>g[10000], cost[10000]; //this code can handle maximum 10000 nodes
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
    cin>>source >> dist;
    //dijstkra(numNodes, g, cost, source);
    printShortestDistance(g, cost, source, dist, numNodes);

    return 0;
}


