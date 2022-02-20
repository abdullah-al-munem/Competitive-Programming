#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main(){

    vector<int>graph[10000],cost[10000];
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;

    // Add Edges
    for(int i=0;i<numEdges;i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    // print the graph
    for (int d = 1; d <= numEdges; ++d) {
        cout << "\nVertex " << d << ":";
        int i = 0;
        for (auto x : graph[d]){
            cout << " -> " << x << " (w:" << cost[d].at(i) << ")";
            i++;
        }
    }
    printf("\n");

    // Remove Edges
    int src, dist;
    cout << "Input source and distance for removing the edge: ";
    cin >> src >> dist;

    auto itr = graph[src].begin();
    while (itr != graph[src].end()) {
        if((*itr) == dist){
            graph[src].erase(itr);
            break;
        }
        ++itr;
    }
    auto itr2 = graph[dist].begin();
    while (itr2 != graph[dist].end()) {
        if((*itr2) == src){
            graph[dist].erase(itr2);
            break;
        }
        ++itr2;
    }

    return 0;
}
