#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second


int main()
{
    ll n, m, i;
    cin >> n;
    ll q, mx = -1, mxidx;
    for(i = 1; i <= n; i++)
    {
        cin >> q;
        if(q > mx)
        {
            mx = q;
            mxidx = i;
        }
    }

    cin >> m;

    vector<pair<ll, ll>> adj[n+1];
    for(i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    for(i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(auto u : adj[i])
            cout << '{' << u.ff << ", " << u.ss << '}' << " ";
        cout << endl;
    }

    set<pair<ll, pair<ll, ll> > >edge;
    set<ll> node;
    node.insert(mxidx);
    for(auto u : adj[mxidx])
        edge.insert({u.ff, {mxidx, u.ss}});



    ll ans = 0;
    while(!edge.empty())
    {
        for(auto e : edge)
            cout << e.ff << " " << e.ss.ff << " " << e.ss.ss << endl;
        cout << endl;

        pair<ll, pair<ll, ll>>e = *edge.begin();
        edge.erase(edge.begin());

        if(node.find(e.ss.ss) != node.end())
            continue;

        ans += e.ff;
        ll v = e.ss.ss;
        node.insert(v);

        for(auto u : adj[v])
        {
            if(node.find(u.ss) == node.end())
                edge.insert({u.ff, {v, u.ss}});
        }
    }

    if(node.size() < n)
        cout << -1;
    else
        cout << ans;
}
