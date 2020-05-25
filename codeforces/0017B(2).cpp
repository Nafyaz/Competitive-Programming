#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, in[1009];
vector<pair<ll, ll>> g[1009];
set<pair<ll, ll>> gr[1009];

int main()
{
    cin >> n;
    ll i, q, mx = -1, mxidx;
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
    for(i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        gr[b].insert({c, a});
        in[b]++;
    }

    queue<ll> Q;
    for(i = 1; i <= n; i++)
    {
        if(in[i] == 0)
        {
            if(i != mxidx)
            {
                cout << -1;
                return 0;
            }
            Q.push(i);
        }
    }
    if(Q.size() != 1)
    {
        cout << -1;
        return 0;
    }

    set<ll> node;
    node.insert(mxidx);
    ll ans = 0;
    while(!Q.empty())
    {
        ll v = Q.front();
        Q.pop();

        for(auto u : g[v])
        {
            in[u.ss]--;
            if(in[u.ss] == 0)
            {
                for(auto x : gr[u.ss])
                {
                    if(node.find(x.ss) != node.end())
                    {
                        ans += x.ff;
                        node.insert(u.ss);
                        Q.push(u.ss);
                        break;
                    }
                }
            }
        }
    }

    cout << ans;
}
