#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
ll dirx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
ll diry[8] = {0, 1, 1, 1, 0, -1, -1, -1};

set<pair<ll, ll>> allowed;
map<pair<ll, ll>, ll> mp;
map<ll, pair<ll, ll>> rev_mp;

vector<ll> adj[100009];
ll dis[100009];

ll bfs(ll st, ll ed)
{
    memset(dis, -1, sizeof dis);
    queue<ll> q;
    dis[st] = 0;
    q.push(st);

    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        for(auto u : adj[node])
        {
            if(dis[u] == -1)
            {
                q.push(u);
                dis[u] = dis[node] + 1;
            }
        }
    }

    return dis[ed];
}

int main()
{
    ll x0, y0, x1, y1, n, i, j, r, a, b, node = 0;
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> r >> a >> b;
        for(j = a; j <= b; j++)
            allowed.insert({r, j});
    }

    for(auto p : allowed)
    {
        mp[p] = node;
        rev_mp[node] = p;
        node++;

//        cout << p.ff << " " << p.ss << ": " << mp[p] << endl;
    }

    for(auto p : allowed)
    {
        pair<ll, ll> u;
        for(i = 0; i < 8; i++)
        {
            u.ff = p.ff + dirx[i];
            u.ss = p.ss + diry[i];
            if(allowed.find(u) != allowed.end())
                adj[mp[p]].push_back(mp[u]);
        }
    }

//    cout << rev_mp[4].ff << ", " << rev_mp[4].ss << endl;
//    cout << rev_mp[6].ff << ", " << rev_mp[6].ss << endl;

//    for(i = 0; i <= 11; i++)
//    {
//        cout << i << ": ";
//        for(auto u : adj[i])
//            cout << u << " ";
//        cout << endl;
//    }

    cout << bfs(mp[{x0, y0}], mp[{x1, y1}]);
}
