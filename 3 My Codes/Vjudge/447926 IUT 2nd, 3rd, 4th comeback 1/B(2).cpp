#include<bits/stdc++.h>
using namespace std;
#define sz 1024009
int p[sz], tree[4*sz];
queue<int> lazy[4*sz];

void build(int node, int s, int e)
{
    while(!lazy[node].empty())
        lazy[node].pop();

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

void removeLazy(int node, int s, int e)
{
    int val;
    while(!lazy[node].empty())
    {
        val = lazy[node].front();

        if(val == -1)
        {
            tree[node] = (e-s+1) - tree[node];

            if(s == e)
                p[s] = 1 - p[s];
        }
        else
        {
            tree[node] = (e-s+1)*val;

            if(s == e)
                p[s] = val;
        }

        if(s != e)
        {
            lazy[2*node+1].push(val);
            lazy[2*node+2].push(val);
        }

        lazy[node].pop();
    }
}

void update(int node, int s, int e, int l, int r, int val)
{
    if(s > r || e < l)
        return;

    removeLazy(node, s, e);

    if(s == e)
    {
        tree[node] = val;
        p[s] = val;
        return;
    }

    if(l <= s && e <= r)
    {
        tree[node] = (e-s+1)*val;
        if(s != e)
        {
            lazy[2*node+1].push(val);
            lazy[2*node+2].push(val);
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
    if(s > r || e < l)
        return;

    removeLazy(node, s, e);

    if(s == e)
    {
        tree[node] = tree[node] ^ 1;
        p[s] = p[s] ^ 1;
        return;
    }

    if(l <= s && e <= r)
    {
        tree[node] = (e-s+1) - tree[node];
        if(s != e)
        {
            lazy[2*node+1].push(-1);
            lazy[2*node+2].push(-1);
        }

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

    removeLazy(node, s, e);

    if(s >= l && e <= r)
        return tree[node];

    int mid = (s+e)/2;

    int ret1 = query(2*node+1, s, mid, l, r);
    int ret2 = query(2*node+2, mid+1, e, l, r);

    return ret1 + ret2;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, caseno = 0, N, M, T, Q, queryno, a, b, i;
    string pirates, type;

    cin >> t;

    while(t--)
    {
        cin >> M;

        N = 0;

        while(M--)
        {
            cin >> T >> pirates;

            while(T--)
            {
                for(i = 0; i < pirates.size(); i++)
                {
                    p[N] = pirates[i] - '0';
                    N++;
                }
            }
        }

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


