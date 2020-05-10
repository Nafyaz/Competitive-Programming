#include<bits/stdc++.h>
using namespace std;
void build(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    int mid = (s+e)/2;
    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node, int s, int e, int idx, int val)
{
    if(s == e)
    {
        tree[node] = val;
        a[idx] = val;
        return;
    }

    int mid = (s+2)/2;
    if(idx <= mid)
        update(2*node, s, mid, idx, val);
    else
        update(2*node+1, mid+1, e, idx, val);

    tree[node] = tree[2*node] + tree[2*node+1];
}
int query(int node, int s, int e, int l, int r)
{
    if(s >= l && e <= r)
        return tree[node];
    else if(s > l || e < r)
        return 0;

    int mid = (s+e)/2;

    int p1 = query(2*node, s, mid, l, r);
    int p2 = query(2*node+1, mid+1, e, l, r);

    return p1+p2;
}
int main()
{

}
