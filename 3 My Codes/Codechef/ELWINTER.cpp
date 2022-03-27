#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll color[100005];
queue<pair<ll, ll>> grey;
vector<ll> adj[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q, i, u, v, node, type, t, greySize;

    cin >> n >> m >> q;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(q--)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> u;
            if(color[u] == 0)
            {
                grey.push({u, 0});
                color[u] = 1;
            }
        }
        else if(type == 2)
        {
            cin >> t;

            greySize = grey.size();

            for(i = 0; i < greySize && !grey.empty(); i++)
            {
                node = grey.front().ff;
                grey.pop();
                color[node] = 2;

                for(auto Next : adj[node])
                {
                    if(color[Next] == 0)
                    {
                        grey.push({Next, t-1});
                        color[Next] = 1;
                    }
                }
            }

            while(!grey.empty() && grey.front().ss > 0)
            {
                node = grey.front().ff;
                t = grey.front().ss;
                grey.pop();
                color[node] = 2;

                for(auto Next : adj[node])
                {
                    if(color[Next] == 0)
                    {
                        grey.push({Next, t-1});
                        color[Next] = 1;
                    }
                }
            }
        }

        else
        {
            cin >> v;

            cout << (color[v] == 0? "NO\n" : "YES\n");
        }
    }
}
