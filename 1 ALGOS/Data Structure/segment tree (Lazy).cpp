#include<bits/stdc++.h>
using namespace std;
#define n 100000
int tree[4*n], a[n], lazy[4*n];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    int mid = (s+e)/2;
    build(2*node, s, mid);
    build(2*node + 1, mid+1, e);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

void updateRange(int node, int s, int e, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        tree[node] += (e - s + 1) * lazy[node];
        if(s != e)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(s > r || e < l)
        return;

    if(s >= l && e <= r)
    {
        tree[node] += (e - s + 1) * val;
        if(s != e)
        {
            lazy[2*node] += val;
            lazy[2*node + 1] += val;
        }
        return;
    }
    int mid = (s + e) / 2;
    updateRange(2*node, s, mid, l, r, val);
    updateRange(2*node + 1, mid + 1, e, l, r, val);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int queryRange(int node, int s, int e, int l, int r)
{
    if(lazy[node] != 0)
    {
        tree[node] += (e - s + 1) * lazy[node];
        if(s != e)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(s > r || e < l)
        return 0;

    if(s >= l and e <= r)
        return tree[node];
    int mid = (s + e) / 2;
    int p1 = queryRange(2*node, s, mid, l, r);
    int p2 = queryRange(2*node + 1, mid + 1, e, l, r);
    return (p1 + p2);
}

