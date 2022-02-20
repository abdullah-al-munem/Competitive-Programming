
#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;

#define INF 9999
//undirected graph
int matrix[20][20];
int parent[20][20];

void init(int v) {
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            if(i==j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INF;
            parent[i][j] = i;
        }
    }
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
    cout << endl;
}

void displayParent(int v){
    int i, j;
    for(i = 1; i <= v; i++) {
       for(j = 1; j <= v; j++) {
          cout << parent[i][j] << " ";
       }
       cout << endl;
    }
}

void pathFind(int src, int dst){
    int c=0;
    if(src == dst){
        cout<< "Path: " << src;
        c++;
        return;
    }
    pathFind(src,parent[src][dst]);
    cout << " " << dst;
}

void floyds(int v, int e)
{
    int i, j, k;
    for (k = 1; k <= v; k++)
    {
        for (i = 1; i <= v; i++)
        {
            for (j = 1; j <= v; j++)
            {
               if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
    displayMatrix(e);
    int s,d;
    cout<<"Enter source and destination: ";
    cin >> s >> d;

    cout<< "Distance: " << matrix[s][d] << endl;
    pathFind(s,d);
    cout<<endl;

}


int main() {

    //weighted graph
    int n,e;
    printf("Input the number of vertices and edges: ");
    scanf("%d%d",&n,&e); ///node-edge
    init(n);
    for(int i=1; i<=e; i++){
        int n1, n2, weight;
        scanf("%d%d%d",&n1,&n2,&weight);  ///node1-node2-cost
        add_edge(n1, n2, weight);
    }
    cout << endl;
    displayMatrix(e);
    floyds(n,e);
    //displayParent(e);

    return 0;
}


