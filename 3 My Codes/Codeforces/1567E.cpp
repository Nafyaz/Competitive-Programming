#include<bits/stdc++.h>
using namespace std;

int n, a[200005];
bool b[200005];
int tree[800005];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = b[s];
        return tree[node];
    }

    int mid = (s+e)/2;

    int p1 = build(2*node, s, mid);
    int p2 = build(2*node+1, mid+1, e);

    return tree[node] = p1 + p2;
}

void update(int node, int s, int e, int idx, int val)
{
    if(s == e)
    {
        tree[node] = val;
        return tree[node];
    }

    int mid = (s+e)/2, p1, p2;

    if(idx <= mid)
    {
        p1 = update(2*node, s, mid, idx, val);
        p2 = tree[2*node+1];
    }
    else
    {
        p1 = tree[2*node];
        p2 = update(2*node+1, mid+1, e, idx, val);
    }

    return tree[node] = p1+p2;
}

int query(int node, int s, int e, int l, int r)
{

}

int main()
{
    int i, x, y, l, r;

    cin >> n >> q;

    a[0] = INT_MIN;
    a[n+1] = INT_MAX;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];

        b[i-1] = (a[i-1] <= a[i]);
    }

    build(1, 1, n-1);

    while(q--)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> x >> y;

            a[x] = y;

            b[x-1] = (a[x-1] <= a[x]);
            update(1, 1, n-1, x-1, b[x-1]);

            b[x] = (a[x] <= a[x+1]);
            update(1, 1, n-1, x, b[x]);
        }
        else
        {
            cin >> l >> r;


        }
    }
}
