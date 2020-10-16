#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

#define N 100009
#define M 1000000007
ll tree[4*N], a[N], lazy_sum[4*N], lazy_mul[4*N], lazy_init[4*N];

void remove_lazy(ll node, ll s, ll e)
{
    ll left = 2*node, right = 2*node + 1;

    if(lazy_sum[node] != 0)
    {
        tree[node] = (tree[node] + (e - s + 1) * lazy_sum[node]) % M;
        if(s != e)
        {
            lazy_sum[left] = (lazy_sum[left] + lazy_sum[node]) % M;
            lazy_sum[right] = (lazy_sum[right] + lazy_sum[node]) % M;
        }
        lazy_sum[node] = 0;
    }

    if(lazy_mul[node] != 1)
    {
        tree[node] = (tree[node] * lazy_mul[node]) % M;
        if(s != e)
        {
            lazy_mul[left] = (lazy_mul[left] * lazy_mul[node]) % M;
            lazy_sum[right] = (lazy_mul[right] * lazy_mul[node]) % M;
        }
        lazy_mul[node] = 1;
    }

    if(lazy_init[node] != 0)
    {
        tree[node] = ((e - s + 1) * lazy_init[node]) % M;
        if(s != e)
        {
            lazy_init[left] = lazy_init[node];
            lazy_init[right] = lazy_init[node];
        }
        lazy_init[node] = 0;
    }
}

void update_sum(ll node, ll s, ll e, ll l, ll r, ll val)
{
    remove_lazy(node, s, e);

    int left = 2*node, right = 2*node + 1;

    if(s > r || e < l)
        return;

    if(s >= l && e <= r)
    {
        tree[node] = (tree[node] + (e - s + 1) * val) % M;
        if(s != e)
        {
            lazy_sum[left] = (lazy_sum[left] + val) % M;
            lazy_sum[right] = (lazy_sum[right] + val) % M;
        }
        return;
    }
    ll mid = (s + e) / 2;
    update_sum(left, s, mid, l, r, val);
    update_sum(right, mid + 1, e, l, r, val);
    tree[node] = (tree[left] + tree[right]) % M;
}

void update_mul(ll node, ll s, ll e, ll l, ll r, ll val)
{
    remove_lazy(node, s, e);

    int left = 2*node, right = 2*node + 1;

    if(s > r || e < l)
        return;

    if(s >= l && e <= r)
    {
        tree[node] = (tree[node] * val) % M;
        if(s != e)
        {
            lazy_mul[left] = (lazy_mul[left] * val) % M;
            lazy_mul[right] = (lazy_mul[right] * val) % M;
        }
        return;
    }
    ll mid = (s + e) / 2;
    update_mul(left, s, mid, l, r, val);
    update_mul(right, mid + 1, e, l, r, val);
    tree[node] = (tree[left] + tree[right]) % M;
}

void update_init(ll node, ll s, ll e, ll l, ll r, ll val)
{
    remove_lazy(node, s, e);

    int left = 2*node, right = 2*node + 1;

    if(s > r || e < l)
        return;

    if(s >= l && e <= r)
    {
        tree[node] = ((e - s + 1) * val) % M;
        if(s != e)
        {
            lazy_init[left] = val;
            lazy_init[right] = val;
        }
        return;
    }
    ll mid = (s + e) / 2;
    update_init(left, s, mid, l, r, val);
    update_init(right, mid + 1, e, l, r, val);
    tree[node] = (tree[left] + tree[right]) % M;
}

ll query_sum(ll node, ll s, ll e, ll l, ll r)
{
    remove_lazy(node, s, e);

    if(s > r || e < l)
        return 0;

    if(s >= l and e <= r)
        return tree[node];

    ll mid = (s + e) / 2;
    ll p1 = query_sum(2*node, s, mid, l, r);
    ll p2 = query_sum(2*node + 1, mid + 1, e, l, r);
    return (p1 + p2) % M;
}

void build(ll node, ll s, ll e)
{
    lazy_mul[node] = 1;
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    ll mid = (s+e)/2;
    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    tree[node] = (tree[2*node] + tree[2*node+1]) % M;
}

int main()
{
    ll n, q, i, type, x, y, v;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);


    for(i = 1; i <= 10; i++)
        cout << setw(4) << tree[i] << " ";
    cout << "\n";
    for(i = 1; i <= 10; i++)
        cout << setw(4) << lazy_sum[i] << " ";
    cout << "\n";
    for(i = 1; i <= 10; i++)
        cout << setw(4) << lazy_mul[i] << " ";
    cout << "\n";
    for(i = 1; i <= 10; i++)
        cout << setw(4) << lazy_init[i] << " ";
    cout << "\n\n\n";

    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> x >> y >> v;
            update_sum(1, 1, n, x, y, v);
        }

        else if(type == 2)
        {
            cin >> x >> y >> v;
            update_mul(1, 1, n, x, y, v);
        }

        else if(type == 3)
        {
            cin >> x >> y >> v;
            update_init(1, 1, n, x, y, v);
        }

        else if(type == 4)
        {
            cin >> x >> y;
            cout << query_sum(1, 1, n, x, y) << "\n";
        }

        for(i = 1; i <= 10; i++)
            cout << setw(4) << tree[i] << " ";
        cout << "\n";
        for(i = 1; i <= 10; i++)
            cout << setw(4) << lazy_sum[i] << " ";
        cout << "\n";
        for(i = 1; i <= 10; i++)
            cout << setw(4) << lazy_mul[i] << " ";
        cout << "\n";
        for(i = 1; i <= 10; i++)
            cout << setw(4) << lazy_init[i] << " ";
        cout << "\n\n\n";
    }
}

