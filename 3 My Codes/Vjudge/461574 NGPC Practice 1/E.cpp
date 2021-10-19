#include<bits/stdc++.h>
using namespace std;
#define sz 100009

int n, k;
int x[sz];
int tree[4*sz];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = x[s];
        return;
    }

    int mid = (s+e)/2;

    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    tree[node] = tree[2*node] * tree[2*node+1];
}

void update(int node, int s, int e, int idx, int val)
{
    if(s == e)
    {
        tree[node] = val;
        x[idx] = val;
        return;
    }

    int mid = (s+e)/2;

    if(idx <= mid)
        update(2*node, s, mid, idx, val);
    else
        update(2*node+1, mid+1, e, idx, val);

    tree[node] = tree[2*node] * tree[2*node+1];
}

int query(int node, int s, int e, int l, int r)
{
    if(l > e || r < s)
        return 1;

    if(l <= s && r >= e)
        return tree[node];

    int mid = (s+e)/2;
    int p1 = query(2*node, s, mid, l, r);
    int p2 = query(2*node+1, mid+1, e, l, r);

    return p1*p2;
}

int main()
{
    int i, j, v, ans;
    string C;

    while(cin >> n >> k)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> x[i];

            if(x[i] > 0)
                x[i] = 1;
            else if(x[i] < 0)
                x[i] = -1;
        }

        build(1, 1, n);

        while(k--)
        {
            cin >> C;

            if(C == "C")
            {
                cin >> i >> v;

                if(v > 0)
                    v = 1;
                else if(v < 0)
                    v = -1;

                update(1, 1, n, i, v);

//                cout << "array: ";
//                for(i = 1; i <= n; i++)
//                    cout << x[i] << " ";
//                cout << "\n";
//
//                cout << "tree: ";
//                for(i = 1; i <= 4*n; i++)
//                    cout << tree[i] << " ";
//                cout << "\n";
            }
            else
            {
                cin >> i >> j;

                ans = query(1, 1, n, i, j);

                if(ans > 0)
                    cout << "+";
                else if(ans < 0)
                    cout << "-";
                else
                    cout << "0";
            }
        }

        cout << "\n";
    }
}

