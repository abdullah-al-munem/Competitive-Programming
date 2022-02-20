#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

#define NO_OF_EDGES 20
#define NO_OF_NODES 20

struct Edge {
    int to; // current node
    int prevEdge; // index of previous node
  // we can add Weight, Capacity
} edgeList[NO_OF_EDGES]; // NO_OF_EDGES = number of edges

// lastEdge[v] = index of the last edge that add in v node. initially it is -1
//  NO_OF_NODES = number of nodes
int lastEdge[NO_OF_NODES];

int numEdges; // number of edges already added in this graph, initially it is 0

void addEdge(int u, int v) {
    edgeList[numEdges].to = v;
    edgeList[numEdges].prevEdge = lastEdge[u];
    lastEdge[u] = numEdges;
    numEdges++;
}

bool seen[NO_OF_NODES];


void dfs(int u){
    cout << u << " ";
    seen[u] = true;
    for (int e = lastEdge[u]; e != -1; e = edgeList[e].prevEdge) {
        int v = edgeList[e].to;
        if (!seen[v]) {
            dfs(v);
        }
    }
}

int main(){

    memset(lastEdge, -1, NO_OF_NODES);
    memset(seen, false, NO_OF_NODES);

    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,1);
    dfs(1);
    cout << endl;
    return 0;
}

