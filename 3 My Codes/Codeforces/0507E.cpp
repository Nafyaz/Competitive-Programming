#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, working;

vector<pair<ll, ll>> adj[100005];
ll dis[100005];
ll workingDis[100005];
ll parent[100005];

struct nodeInQ
{
    ll dis, wDis, node;
};

bool operator < (nodeInQ a, nodeInQ b)
{
    if(a.dis != b.dis)
        return a.dis < b.dis;
    if(a.wDis != b.wDis)
        return a.wDis > b.wDis;
    return a.node < b.node;
}

void spfa(ll s)
{
    nodeInQ node;
    node.dis = 0;
    node.wDis = 0;
    node.node = s;

    set<nodeInQ>q;
    q.insert(node);
    dis[s] = 0;
    workingDis[s] = 0;

    while(!q.empty())
    {
        node = *(q.begin());
        q.erase(q.begin());

        if(node.dis > dis[node.node] || (node.dis == dis[node.node] && node.wDis < workingDis[node.node]))
            continue;

        for(auto u : adj[node.node])
        {
            nodeInQ node2;

            node2.dis = dis[node.node] + 1;
            node2.wDis = workingDis[node.node] + u.ff;
            node2.node = u.ss;

            if(node2.dis < dis[node2.node] || (node2.dis == dis[node2.node] && node2.wDis > workingDis[node2.node]))
            {
                dis[node2.node] = node2.dis;
                workingDis[node2.node] = node2.wDis;
                parent[node2.node] = node.node;
                q.insert(node2);
            }
        }
    }
}

int main()
{
    ll i, k, x, y, z;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        working += z;

        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }

    for(i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    spfa(1);

//    cout << "\n";
//    for(i = 1; i <= n; i++)
//    {
//        cout << i << ": " << dis[i] << " " << workingDis[i] << " " << parent[i] << "\n";
//    }
//    cout << "\n";

    k = (dis[n] - workingDis[n]) + (working - workingDis[n]);

    cout << k << "\n";

    set<pair<ll, ll>> edges;
    for(x = n; parent[x] != 0; x = parent[x])
    {
        edges.insert({min(x, parent[x]), max(x, parent[x])});
    }

//    cout << "\n";
//    for(auto u : edges)
//        cout << u.ff << " " << u.ss << "\n";
//    cout << "\n";

    for(i = 1; i <= n; i++)
    {
        for(auto u : adj[i])
        {
            if(u.ss > i)
            {
                if(u.ff == 1 && edges.find({i, u.ss}) == edges.end())
                    cout << i << " " << u.ss << " " << 0 << "\n";
                if(u.ff == 0 && edges.find({i, u.ss}) != edges.end())
                    cout << i << " " << u.ss << " " << 1 << "\n";
            }
        }
    }
}
