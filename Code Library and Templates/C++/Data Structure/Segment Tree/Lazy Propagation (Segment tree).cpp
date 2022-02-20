#include<stdio.h>
#include<iostream>

using namespace std;

#define mx 100001
int arr[mx];

struct info {
    int prop, sum, value;
} tree[mx * 3];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].sum = arr[b];
        tree[node].prop = 0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = b+(e-b)/2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].prop = 0;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = b+(e-b)/2;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;

}


void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = b+(e-b)/2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;

}

int main()
{
    //READ("in");
    int n,i;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> arr[i];
    init(1, 1, n);

    cout << query(1, 1, n, 3, 4) << endl;
    update(1, 1, n, 3, 5, 2);
    cout << query(1, 1, n, 3, 4) << endl;
    //update(1, 1, n, 2, 3, 2);
    //cout << query(1, 1, n, 2, 2) << endl;

    return 0;

}

