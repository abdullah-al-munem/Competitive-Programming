#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include<vector>
#include <list>
using namespace std;

//undirected graph
#define MAX 100000 //maximum node
vector <int> edges[MAX];
vector <int> cost[MAX]; //parallel vector to store costs;
// unweighted graph
void addEdge(int s, int d) {
    edges[s].push_back(d);
    edges[d].push_back(s);
    cost[s].push_back(1);
    cost[d].push_back(1);
}
// weighted graph
void addEdge(int s, int d, int weight) {
    edges[s].push_back(d);
    edges[d].push_back(s);
    cost[s].push_back(weight);
    cost[d].push_back(weight);

}

void removeEdge2(int s, int d) {

    auto itr = edges[s].begin();
    while (itr != edges[s].end()) {
        if((*itr) == d){
            edges[s].erase(itr);
            break;
        }
        ++itr;
    }
    auto itr2 = edges[d].begin();
    while (itr2 != edges[d].end()) {
        if((*itr2) == s){
            edges[d].erase(itr2);
            break;
        }
        ++itr2;
    }

}

void isEdge(int u, int v){
    auto itr1 = find(edges[u].begin(), edges[u].end(),v);
    auto itr2 = find(edges[v].begin(), edges[v].end(),u);
    if(itr1 != edges[u].end() && itr2 != edges[v].end()){
        cout << "Edge!" << endl;
    }
    else{
        cout << "Not Edge!" << endl;
    }

}

bool hasCommonAdjacent(int u, int v, int n)
{

    //returns true if vertices u and v have common adjacent vertices
    if(u<0 || v<0 || u>=n || v>=n) return false;
    for(int i=0; i<edges[u].size(); i++)
    {
        for(int j=0; j<edges[v].size(); j++)
        {
            if(edges[u].at(i) == edges[v].at(j))
            {
                return true;
            }
        }
    }
    return false;
}



//only for Weighted and Directed Graph because it was used list
vector< list< pair<int, int> > > removeEdge(vector< list< pair<int, int> > > adjlist, int i, int j) {

    auto itr = adjlist[i].begin();
    while (itr != adjlist[i].end()) {
        if((*itr).first == j){
            adjlist[i].erase(itr);
            break;
        }
        ++itr;
    }

    return adjlist;

}

void printGraph(int v) {
    for (int d = 1; d <= v; ++d) {
        cout << "\nVertex " << d << ":";
        int i = 0;
        for (auto x : edges[d]){
            cout << " -> " << x << " (w:" << cost[d].at(i) << ")";
            i++;
        }
    }
    printf("\n");
}

int findDegree(int v){
    int degree = edges[v].size();
    cout << "\nVertex " << v << ":";
    for(auto it = edges[v].begin(); it != edges[v].end(); it++)
		cout << " -> " << *it;
    printf("\n");
    return degree;

}

void findInOutDegree(vector< list< pair<int, int> > > adjlist, int n)
{
    int* iN = new int[n]();
    int* ouT = new int[n]();

    for (int i = 1; i < adjlist.size(); ++i)
    {
        ouT[i] = adjlist[i].size();
        list< pair<int, int> >::iterator itr;
        for(itr = adjlist[i].begin(); itr != adjlist[i].end(); itr++){
            iN[(*itr).first]++;
        }
    }

    cout << "Vertex\t\tIn\t\tOut" << endl;
    for(int k = 1; k <= n; k++)
    {
        cout << k << "\t\t" << iN[k] << "\t\t" << ouT[k] << endl;
    }

}

int main() {

    ///unweighted graph
    int v;
    printf("Input the number of vertex for unweighted graph: ");
    scanf("%d",&v);

    for(int i=1; i<=v; i++){
        int v1, v2;
        scanf("%d%d",&v1,&v2); ///node1-node2
        addEdge(v1, v2);
    }
    printGraph(v);

    int totalDegree = findDegree(1);
    printf("Total degree of node 1 is: %d\n",totalDegree);


    ///Weighted and Directed Graph

    int vertices, edges, v1, v2, weight;

    printf("\nEnter the Number of Vertices: ");
    scanf("%d", &vertices);

    printf("Enter the Number of Edges: ");
    scanf("%d", &edges);

    // Adjacency List is a vector of list.
    // Where each element is a pair<int, int>
    // pair.first -> the edge's destination
    // pair.second -> edge's weight
    vector< list< pair<int, int> > > adjacencyList(vertices + 1);

    printf("Enter the Edges V1 -> V2, of weight W\n");

    for (int i = 1; i <= edges; ++i) {
        scanf("%d%d%d", &v1, &v2, &weight);

        // Adding Edge to the Directed Graph
        adjacencyList[v1].push_back(make_pair(v2, weight));
    }

    printf("\nThe Adjacency List-\n");
    // Printing Adjacency List
    for (int i = 1; i < adjacencyList.size(); ++i) {
        printf("adjacencyList[%d]", i);

        list< pair<int, int> >::iterator itr = adjacencyList[i].begin();

        while (itr != adjacencyList[i].end()) {
            printf(" -> %d (%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }
    int size1 = adjacencyList.size();

    findInOutDegree(adjacencyList, size1);
    adjacencyList = removeEdge(adjacencyList, 1, 2);
    findInOutDegree(adjacencyList, size1);

    for (int i = 1; i < adjacencyList.size(); ++i) {
        printf("adjacencyList[%d]", i);

        list< pair<int, int> >::iterator itr = adjacencyList[i].begin();

        while (itr != adjacencyList[i].end()) {
            printf(" -> %d (%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }


    return 0;
}

