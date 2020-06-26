#include<bits/stdc++.h>
using namespace std;
#define N 100009
int n, q;
int tree0[4*N], tree1[4*N], lazy[4*N];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tree0[node] = 1;
        return;
    }

    int left = 2*node + 1, right = 2*node + 2, mid = (s+e)>>1;
    build(left, s, mid);
    build(right, mid+1, e);

    tree0[node] = tree0[left] + tree0[right];
}

void update(int node, int s, int e, int l, int r)
{

    int temp, left = 2*node + 1, right = 2*node + 2, mid = (s+e)>>1;

    if(lazy[node])
    {
        if(s != e)
        {
            lazy[left] = (lazy[left] + lazy[node])%3;
            lazy[right] = (lazy[right] + lazy[node])%3;
        }

        while(lazy[node] > 0)
        {
            temp = tree1[node];
            tree1[node] = tree0[node];
            tree0[node] = (e-s+1) - temp - tree0[node];
            lazy[node]--;
        }
    }

    if(s > r || e < l)
        return;

    if(s >= l && e <= r)
    {
        temp = tree1[node];
        tree1[node] = tree0[node];
        tree0[node] = (e-s+1) - temp - tree0[node];

        if(s != e)
        {
            lazy[left] = (lazy[left] + 1)%3;
            lazy[right] = (lazy[right] + 1)%3;
        }
        return;
    }

    update(left, s, mid, l, r);
    update(right, mid+1, e, l, r);

    tree0[node] = tree0[left] + tree0[right];
    tree1[node] = tree1[left] + tree1[right];
}

int query(int node, int s, int e, int l, int r)
{

    int temp, left = 2*node + 1, right = 2*node + 2, mid = (s+e)>>1;

    if(lazy[node])
    {
        if(s != e)
        {
            lazy[left] = (lazy[left] + lazy[node])%3;
            lazy[right] = (lazy[right] + lazy[node])%3;
        }

        while(lazy[node] > 0)
        {
            temp = tree1[node];
            tree1[node] = tree0[node];
            tree0[node] = (e-s+1) - temp - tree0[node];
            lazy[node]--;
        }
    }

    if(s > r || e < l)
        return 0;

    if(s >= l && e <= r)
        return tree0[node];

    int p1 = query(left, s, mid, l, r);
    int p2 = query(right, mid+1, e, l, r);

    return p1 + p2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int type, l, r;
    cin >> n >> q;
    build(0, 0, n-1);

    while(q--)
    {
        cin >> type >> l >> r;

        if(!type)
        {
            update(0, 0, n-1, l, r);
        }
        else
        {
            cout << query(0, 0, n-1, l, r) << endl;
        }
    }
}
