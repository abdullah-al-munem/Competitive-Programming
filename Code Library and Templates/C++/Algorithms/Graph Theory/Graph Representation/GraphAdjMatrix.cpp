#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3

//******************Queue class starts here**************************

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges , time ;
	bool directed ;
	int ** matrix ; //adjacency matrix to store the graph
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation
	int *color;
	int *parent;
	int *dist;
	int *dtime;
	int *ftime;

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u);
    void printAdjVertices(int u);
    bool hasCommonAdjacent(int u, int v);
    void printGraph();
    void bfs(int u);
    int getDist(int u, int v);
    int findComponents();
    void dfs(int u);
    void dfsVisit(int u);
    void Time(int u);
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ; //set direction of the graph
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;

	//allocate space for the matrix
    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0; //initialize the matrix cells to 0
    }
    color = new int[nVertices];
    dist = new int[nVertices];
    parent = new int[nVertices];
    dtime = new int[nVertices];
    ftime = new int[nVertices];
}

void Graph::addEdge(int u, int v)
{
    //write your code here
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    matrix[u][v] = 1;
    if(!directed) matrix[v][u] = 1;
    nEdges++;

}

void Graph::removeEdge(int u, int v)
{

    //write this function
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    matrix[u][v] = 0;
    if(!directed) matrix[v][u] = 0;
    nEdges--;
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(matrix[u][v] == 1 && matrix[v][u] == 1) return true;
    else return false;
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    int sum = 0;
    for(int i=0; i<nVertices; i++)
    {
        if(matrix[u][i] == 1)
        {
            sum = sum + 1;
        }
    }
    return sum;
}

void Graph::printAdjVertices(int u)
{
    //prints all adjacent vertices of a vertex u
    for(int i=0; i<nVertices; i++)
    {
        if(matrix[u][i] == 1)
        {
            printf("%d ",i);
        }
    }

}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    for(int i=0; i<nVertices; i++)
    {
        if(matrix[u][i] == 1)
        {
            for(int j=0; j<nVertices; j++)
            {
                if(matrix[v][j] == 1)
                {
                    if(i == j) return true;
                }
            }
        }
    }
    return false;
}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
    delete[] matrix;
    delete[] color;
    delete[] dist;
    delete[] parent;
}

void Graph::bfs(int u)
{
    Queue q1;
    for(int i = 0; i<nVertices; i++)
    {
        color[i] = WHITE;
        parent[i] = NULL_VALUE;
        dist[i] = INFINITY;
    }

    color[u] = GREY;
    parent[u] = NULL_VALUE;
    dist[u] = 0;

    q1.enqueue(u);
    while(!q1.empty())
    {
        int x = q1.dequeue();
        for(int i = 0; i<nVertices; i++)
        {
            if(matrix[x][i] == 1)
            {
                if(color[i] == WHITE)
                {
                    color[i] = GREY;
                    parent[i] = x;
                    dist[i] = dist[x] + 1;
                    q1.enqueue(i);
                }
            }
        }
        color[x] = BLACK;
    }
}

int Graph::getDist(int u, int v)
{
    bfs(u);
    return dist[v];
}

int Graph::findComponents()
{
    int count =0;
    for(int i = 0; i<nVertices; i++)
    {
        color[i] = WHITE;
    }

    for(int i=1; i<nVertices; i++)
    {
        if(color[i] == WHITE)
        {
            bfs(i);
            count++;
        }
    }
    return count;
}

void Graph::dfsVisit(int u)
{
    color[u] =  GREY;
    time = time + 1;
    dtime[u] =  time;
    for(int i=0; i<nVertices; i++)
    {
        if(matrix[u][i] == 1)
        {
            if(color[i] == WHITE)
            {
                dfsVisit(i);
            }
        }
    }
    color[u] = BLACK;
    time = time + 1;
    ftime[u] = time;

}
void Graph::dfs(int u)
{
    time = 0;
    for(int i = 1; i<nVertices; i++)
    {
        color[i] = WHITE;
    }

    for(int i = 0; i<nVertices; i++)
    {
        if(color[i] == WHITE)
        {
            dfsVisit(i);
        }
    }
}

void Graph::Time(int u)
{
   printf("Discover time: %d Finish time: %d\n",dtime[u], ftime[u]);
}
//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. 2. Remove Edge 3. Check Edge\n");
        printf("4.Get Degree 5.Print Adjacent Vertices 6.Check Common Adjacent\n");
        printf("7. Print Graph  8. BFS 9. Distance 10. Components Count 11. DFS\n");
        printf("12. Discover/Final Time\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.removeEdge(u,v);
        }
        else if(ch==3)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.isEdge(u,v)) printf("It's an Edge");
            else printf("Not an edge");
        }
        else if(ch==4)
        {
            int u;
            scanf("%d",&u);
            int degree = g.getDegree(u);
            printf("%d\n",degree);
        }
        else if(ch==5)
        {
            int u;
            scanf("%d",&u);
            g.printAdjVertices(u);
        }
        else if(ch==6)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.hasCommonAdjacent(u,v)) printf("They have common adjacent\n");
            else printf("They don't have common adjacent");
        }
        else if(ch==7)
        {
            g.printGraph();
        }
        else if(ch==8)
        {
            int u;
            scanf("%d",&u);
            g.bfs(u);
        }
        else if(ch==9)
        {
            int u,v;
            scanf("%d",&u);
            scanf("%d",&v);
            printf("Distance from %d to %d is: %d\n", u, v, g.getDist(u,v));
        }
        else if(ch==10)
        {
            printf("components count: %d\n", g.findComponents());
        }
        else if(ch==11)
        {
            int u;
            scanf("%d",&u);
            g.dfs(u);
        }
        else if(ch==12)
        {
            int u;
            scanf("%d",&u);
            g.Time(u);
        }
    }

}
