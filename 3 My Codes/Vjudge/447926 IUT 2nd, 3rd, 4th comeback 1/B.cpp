#include<bits/stdc++.h>
using namespace std;
#define sz 1024009
int p[sz], tree[4*sz], lazy[4*sz];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = p[s];
        return;
    }

    int mid = (s+e)/2;

    build(2*node+1, s, mid);
    build(2*node+2, mid+1, e);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void update(int node, int s, int e, int l, int r, int val)
{
    if(s > r || e < l)
        return;

    if(lazy[node] != -1)
    {
        tree[node] = (e-s+1)*lazy[node];
        lazy[2*node+1] = lazy[node];
        lazy[2*node+2] = lazy[node];

        lazy[node] = -1;
    }

    if(s == e)
    {
        tree[node] = val;
        p[s] = val;
        return;
    }

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
    update(2*node+2, mid+1, e, l, r, val);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void inverse(int node, int s, int e, int l, int r)
{
    if(lazy[node] != -1)
    {
        tree[node] = (e-s+1)*lazy[node];
        lazy[2*node+1] = lazy[node];
        lazy[2*node+2] = lazy[node];

        lazy[node] = -1;
    }

    if(s > r || e < l)
        return;

    if(s == e)
    {
        tree[node] = tree[node] ^ 1;
        p[s] = p[s] ^ 1;
        return;
    }

    int mid = (s+e)/2;

    inverse(2*node+1, s, mid, l, r);
    inverse(2*node+2, mid+1, e, l, r);

    tree[node] = tree[2*node+1] + tree[2*node+2];

    return;
}

int query(int node, int s, int e, int l, int r)
{
    if(s > r || e < l)
        return 0;

    if(lazy[node] != -1)
    {
        tree[node] = (e-s+1)*lazy[node];
        lazy[2*node+1] = lazy[node];
        lazy[2*node+2] = lazy[node];

        lazy[node] = -1;
    }

    if(s >= l && e <= r)
        return tree[node];

    int mid = (s+e)/2;

    int ret1 = query(2*node+1, s, mid, l, r);
    int ret2 = query(2*node+2, mid+1, e, l, r);

    return ret1 + ret2;
}


int main()
{
    int t, caseno = 0, N, M, T, Q, queryno, a, b, i;
    string pirates, allPirates, type;

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
            p[i] = allPirates[i] - '0';

        memset(lazy, -1, sizeof lazy);
        build(0, 0, N-1);

        cin >> Q;

        cout << "Case " << ++caseno << ":\n";

        queryno = 0;

        while(Q--)
        {
//            for(i = 0; i < N; i++)
//                cout << setw(3) << p[i] << " ";
//            cout << "\n";
//            for(i = 0; i < 38; i++)
//                cout << setw(3) << tree[i] << " ";
//            cout << "\n";
//            for(i = 0; i < 38; i++)
//                cout << setw(3) << lazy[i] << " ";
//            cout << "\n";

            cin >> type >> a >> b;

            if(type == "F")
                update(0, 0, N-1, a, b, 1);
            else if(type == "E")
                update(0, 0, N-1, a, b, 0);
            else if(type == "I")
                inverse(0, 0, N-1, a, b);
            else
                cout << "Q" << ++queryno << ": " << query(0, 0, N-1, a, b) << "\n";
        }
    }
}

