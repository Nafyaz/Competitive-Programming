#include<bits/stdc++.h>
using namespace std;
#define sz 1024009
int a[sz], tree[4*sz], lazy[4*sz];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    int mid = (s+e)/2;

    build(2*node+1, s, mid);
    build(2*node+2, mid+1, e);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void removeLazy(int node, int s, int e)
{
    if(lazy[node] != -1)
    {
        tree[node] = (e-s+1)*lazy[node];

        if(s != e)
        {
            lazy[2*node+1] = lazy[node];
            lazy[2*node+2] = lazy[node];
        }

        lazy[node] = -1;
    }
}

void update(int node, int s, int e, int l, int r, int val)
{
    removeLazy(node, s, e);

    if(s > r || e < l)
        return;

    if(s >= l && e <= r)
    {
        tree[node] = (e-s+1)*val;
        if(s != e)
        {
            lazy[2*node+1] = val;
            lazy[2*node+2] = val;
        }

        return;
    }

    int mid = (s+e)/2;
    update(2*node+1, s, mid, l, r, val);
    update(2*node+2, mid+1, l, r, val);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void inverse(int node, int s, int e, int l, int r)
{
    removeLazy(node, s, e);

    if(s > r || e < l)
        return;

    int mid = (s+e)/2;

    if(s >= l && e <= r)
    {
        tree[node] = (e-s+1) - tree[node];

        if(s != e)
        {
            removeLazy(2*node+1, s, mid);

        }
    }
}


int main()
{
    int t, N, M, T, Q, a, b, i;
    string pirates, allPirates, query;

    cin >> t;

    while(t--)
    {
        cin >> M;

        allPirates = "";

        while(M--)
        {
            cin >> T >> pirates;

            while(T--)
                allPirates = allPirates + pirates;
        }

        N = allPirates.size();

        for(i = 0; i < N; i++)
            a[i] = allPirates[i] - '0';

        memset(lazy, -1, sizeof lazy);
        build(0, 0, N-1);

        cin >> Q;

        while(Q--)
        {
            cin >> query >> a >> b;

            if(query == "F")
                update(0, 0, N-1, a, b, 1);
            else if(query == "E")
                update(0, 0, N-1, a, b, 0);
            else if(query == "I")
                inverse(0, 0, N-1, a, b);
        }
    }
}
