#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> adj[200005];
map<pair<ll, ll>, ll> weights;
ll par[200005];
ll inverseInSub[200005];
ll inverseIfRoot[200005];

vector<ll> nodes;

void dfs(ll s, ll p)
{
    par[s] = p;

    for(auto u : adj[s])
    {
        if(u == p)
            continue;

        dfs(u, s);

        if(weights[{par[u], u}] == 0)
            inverseInSub[s]++;

        inverseInSub[s] += inverseInSub[u];
    }
}

ll bfs()
{
    ll ret = INT_MAX;

    queue<ll> q;
    q.push(1);

    while(!q.empty())
    {
        ll p = q.front();
        q.pop();

        if(par[p] == -1)
        {
            inverseIfRoot[1] = inverseInSub[1];
            ret = inverseIfRoot[1];
            nodes.push_back(1);
        }
        else
        {
            inverseIfRoot[p] = inverseIfRoot[par[p]];
            if(weights[{p, par[p]}] == 1)
                inverseIfRoot[p]--;
            else
                inverseIfRoot[p]++;

            if(ret > inverseIfRoot[p])
            {
                ret = inverseIfRoot[p];
                nodes.clear();
                nodes.push_back(p);
            }
            else if(ret == inverseIfRoot[p])
                nodes.push_back(p);
        }

        for(auto u : adj[p])
        {
            if(u != par[p])
                q.push(u);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, a, b;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        weights[{a, b}] = 1;
        weights[{b, a}] = 0;
    }

    dfs(1, -1);

    cout << bfs() << "\n";
    sort(nodes.begin(), nodes.end());
    for(auto u : nodes)
        cout << u << " ";
}
