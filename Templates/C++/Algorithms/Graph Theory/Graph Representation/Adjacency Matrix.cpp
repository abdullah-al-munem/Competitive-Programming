#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

//undirected graph
int matrix[20][20];

void init(int v) {
    int i, j;
    for (i = 1; i <= v; i++)
        for (j = 0; j < v; j++)
            matrix[i][j] = 0;
}

//unweighted graph
void add_edge(int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

//weighted graph
void add_edge(int u, int v, int cost) {
    matrix[u][v] = cost;
    matrix[v][u] = cost;
}

void removeEdge(int i, int j) {
    matrix[i][j] = 0;
    matrix[j][i] = 0;
}

int findAdNode(int v,int v1){

    int count = 0;
    printf("Adjacency Nodes of %d is:\n",v1);
    for(int i=1; i<=v; i++){
        if(matrix[v1][i] == 1){
            count++;
            printf("%d -> %d\n",v1,i);
        }

    }

    return count;

}

void displayMatrix(int v) {
    int i, j;
    for(i = 1; i <= v; i++) {
       for(j = 1; j <= v; j++) {
          cout << matrix[i][j] << " ";
       }
       cout << endl;
    }
}

int main() {

    //unweighted graph
    int v;
    printf("Input the number of vertex for unweighted graph: ");
    scanf("%d",&v);
    for(int i=1; i<=v; i++){
        int v1, v2;
        scanf("%d%d",&v1,&v2); ///node1-node2
        add_edge(v1, v2);
    }
    displayMatrix(v);
    int nodes = findAdNode(v,1);
    printf("Total adNode: %d\n", nodes);

    //weighted graph
    int n,e;
    printf("Input the number of vertices and edges for weighted graph: ");
    scanf("%d%d",&n,&e); ///node-edge
    for(int i=1; i<=e; i++){
        int n1, n2, weight;
        scanf("%d%d%d",&n1,&n2,&weight);  ///node1-node2-cost
        add_edge(n1, n2, weight);
    }
    displayMatrix(e);

    return 0;
}

