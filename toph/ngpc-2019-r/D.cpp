#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100009], tree[400009], phi[100009];
void Tau_all(ll n)
{
    for(ll i = 1; i <= n; i++)
        phi[i] = i;
    for (ll p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;

            for (ll i = 2*p; i<=n; i += p)
               phi[i] = (phi[i]/p) * (p-1);
        }
    }
}
void build(ll node, ll s, ll e)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    ll mid = (s+e)/2;

    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(ll node, ll s, ll e, ll idx, ll val)
{
    if(s == idx && e == idx)
    {
        a[idx] = val;
        tree[node] = val;
        return;
    }

    ll mid = (s+e)/2;

    if(idx <= mid)
        update(2*node, s, mid, idx, val);
    else
        update(2*node+1, mid+1, e, idx, val);

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(ll node, ll s, ll e, ll l, ll r)
{
    if(s >= l && e <= r)
        return tree[node];
    if(s > r || e < l)
        return 0;

    ll mid = (s+e)/2, p1, p2;

    p1 = query(2*node, s, mid, l, r);
    p2 = query(2*node+1, mid+1, e, l, r);

    return p1+p2;
}


int main()
{
    Tau_all(100008);
    ll n, q, i, x;



    cin >> n >> q;

    for(i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = phi[x];
    }

    build(1, 1, n);



    ll idx, val, l, r;

    while(q--)
    {
        cin >> x;
        if(x == 1)
        {
            cin >> idx >> val;
            update(1, 1, n, idx, phi[val]);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}
