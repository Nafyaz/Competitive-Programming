#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

ll a[200009], vis[200009], n;
vector <pair<ll, ll> > v(200009);

pair<ll, ll> bfs(ll s)
{
    if(i < 0 || i >= n)
        return {INT_MAX, INT_MAX};

    if(vis[i])
        return v[i];

    vis[i] = visval;

    ll x;
    if(i + a[i] < n)
    {
        x = a[i + a[i]];
        if(x%2 == 0)
            v[i].ff = 1;
        else
            v[i].ss = 1;
    }
    if(i - a[i] >= 0)
    {
        x = a[i - a[i]];
        if(x%2 == 0)
            v[i].ff = 1;
        else
            v[i].ss = 1;
    }

    pair<ll, ll> p1 = func(i + a[i]), p2 = func(i - a[i]);
    v[i].ff = min({v[i].ff, p1.ff+1, p2.ff+1});
    v[i].ss = min({v[i].ss, p1.ss+1, p2.ss+1});

    return v[i];

    queue<ll> q;
    q.push(s);

    while(!q.empty())
    {
        ll i = q.front();
        q.pop();


    }
}

int main()
{
    ll i, j;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        v[i].ff = v[i].ss = INT_MAX;
    }
    for(i = 0; i < n; i++)
    {
        if(!vis[i])
            func(i);
    }

    for(i = 0; i < n; i++)
    {
        if(a[i]%2 == 0)
        {
            if(v[i].ss >= INT_MAX)
                cout << -1 << " ";
            else
                cout << v[i].ss << " ";
        }
        else
        {
            if(v[i].ff >= INT_MAX)
                cout << -1 << " ";
            else
                cout << v[i].ff << " ";
        }
    }
}
