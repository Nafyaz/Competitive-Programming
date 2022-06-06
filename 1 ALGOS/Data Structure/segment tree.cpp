#include<bits/stdc++.h>
using namespace std;
#define sz 100005

int n, k;
int x[sz];
int Tree[4*sz];

void build(int node, int s, int e)
{
    if(s == e)
    {
        Tree[node] = x[s];
        return;
    }

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;

    build(left, s, mid);
    build(right, mid+1, e);

    Tree[node] = Tree[left] * Tree[right];
}

void update(int node, int s, int e, int idx, int val)
{
    if(s == e)
    {
        Tree[node] = val;
        x[idx] = val;
        return;
    }

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;

    if(idx <= mid)
        update(left, s, mid, idx, val);
    else
        update(right, mid+1, e, idx, val);

    Tree[node] = Tree[left] * Tree[right];
}

int query(int node, int s, int e, int l, int r)
{
    if(l > e || r < s)
        return 1;

    if(l <= s && r >= e)
        return Tree[node];

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;
    int p1 = query(left, s, mid, l, r);
    int p2 = query(right, mid+1, e, l, r);

    return p1*p2;
}