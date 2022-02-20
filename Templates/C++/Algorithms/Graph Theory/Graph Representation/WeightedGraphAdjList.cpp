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


//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}

void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges, time ;
	bool directed ;
	ArrayList  * adjList ;
	int *color;
	int *parent;
	int *dist;// distance
	int *hasVisited;
	int *dtime;
	int *ftime;
	int *edge;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v, int n);
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
	adjList = 0 ;
	directed = dir ; //set direction of the graph
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;
	if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = new ArrayList[nVertices] ;
    color = new int[nVertices];
    dist = new int[nVertices];
    parent = new int[nVertices];
    dtime = new int[nVertices];
    ftime = new int[nVertices];
    edge = new int[nVertices];
}

void Graph::addEdge(int u, int v, int n)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    edge[v] = n;
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed)
	{
	    adjList[v].insertItem(u) ;
	    edge[u] = n;
	}

}

void Graph::removeEdge(int u, int v)
{
    //removed the edge between u and v if such edge exists
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return;
    adjList[u].removeItem(v);
    edge[v] = 0;
    adjList[v].removeItem(u);
    edge[u] = 0;
    nEdges--;

}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false;
    if(adjList[u].searchItem(v) != NULL_VALUE && adjList[v].searchItem(u) != NULL_VALUE) return true;
    else return false;
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    if(u<0 || u>=nVertices) return NULL_VALUE;

    return adjList[u].getLength();
}

void Graph::printAdjVertices(int u)
{

    //prints all adjacent vertices of a vertex u
    if(u<0 || u>=nVertices) return;
    adjList[u].printList();
}

bool Graph::hasCommonAdjacent(int u, int v)
{

    //returns true if vertices u and v have common adjacent vertices
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false;
    for(int i=0; i<adjList[u].getLength(); i++)
    {
        for(int j=0; j<adjList[v].getLength(); j++)
        {
            if(adjList[u].getItem(i) == adjList[v].getItem(j))
            {
                return true;
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
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d Edge: %d", adjList[i].getItem(j), edge[adjList[i].getItem(j)]);
        }
        printf("\n");
    }
}


Graph::~Graph()
{
    delete[] adjList;
    delete[] color;
    delete[] dist;
    delete[] parent;
    //write your destructor here
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
        for(int i = 0; i<adjList[x].getLength(); i++)
        {
            int y = adjList[x].getItem(i);
            if(color[y] == WHITE)
            {
                color[y] = GREY;
                parent[y] = x;
                dist[y] = dist[x] + edge[y];
                q1.enqueue(y);
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
        if(color[i] != BLACK)
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

    for(int i=0; i<adjList[u].getLength(); i++)
    {
        int y = adjList[u].getItem(i);
        if(color[y] == WHITE)
        {
            dfsVisit(y);
        }
    }
    color[u] = BLACK;
    time = time + 1;
    ftime[u] = time;

}
void Graph::dfs(int u)
{
    time = 0;
    for(int i = 0; i<nVertices; i++)
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
        printf("7. Print Graph 8. BFS 9. Distance 10. Components Count 11. DFS\n");
        printf("12. Discover/Final Time\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v, n;
            scanf("%d%d%d", &u, &v, &n);
            g.addEdge(u, v, n);
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
            if(g.isEdge(u,v)) printf("It's an Edge\n");
            else printf("Not an edge\n");
        }
        else if(ch==4)
        {
            int u;
            scanf("%d",&u);
            int degree = g.getDegree(u);
            printf("Degree: %d\n",degree);
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
