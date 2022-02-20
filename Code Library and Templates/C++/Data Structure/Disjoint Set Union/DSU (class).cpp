#include <iostream>
using namespace std;

class DisjSet {
	int *sz, *parent, n;

public:
	DisjSet(int n)
	{
		sz = new int[n];
		parent = new int[n];
		this->n = n;
		init();
	}

	void init()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
		}
	}

	int findRoot(int u)
	{
	    while(parent[u]!=-1){
            u = parent[u];
	    }
		return u;
	}

	void unionDS(int a, int b)
	{
		a = findRoot(a); // now a is the root of a
		b = findRoot(b); // now b is the root of b

		if (a == b)
			return;

		if (sz[a] >= sz[b]) {
			parent[b] = a;
            sz[a] = sz[a]+sz[b];
		}
		else{
            parent[a] = b;
            sz[b] = sz[a]+sz[b];
        }
	}

    int query(int a, int b){

        a = findRoot(a);
        b = findRoot(b);

        if(a == b)
            return 1;
        else
            return 0;
    }


};

int main()
{
	DisjSet obj(5);
	obj.unionDS(0, 2);
	obj.unionDS(4, 2);
	obj.unionDS(3, 1);

	if (obj.query(4,0))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (obj.query(1,0))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}

