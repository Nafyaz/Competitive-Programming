#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

pair<int, int> edges[100005];
map<pair<int, int>, int> weights;
vector<int> adj[100005];
vector<int> twoEdges, oneEdge;

void dfs(int s, int parent, int prime)
{
    for(auto u : adj[s])
    {
        if(u != parent)
        {
            weights[{s, u}] = prime;
            weights[{u, s}] = prime;

            if(prime == 2)
                dfs(u, s, 3);
            else
                dfs(u, s, 2);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, u, v, possible;

    cin >> t;

    while(t--)
    {
        cin >> n;

        weights.clear();
        for(i = 1; i <= n; i++)
            adj[i].clear();

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;

            edges[i] = {u, v};

            adj[u].push_back(v);
            adj[v].push_back(u);

            weights[{u, v}] = 0;
            weights[{v, u}] = 0;
        }

        oneEdge.clear();
        twoEdges.clear();
        possible = 1;
        for(i = 1; i <= n; i++)
        {
            if(adj[i].size() == 1)
                oneEdge.push_back(i);
            if(adj[i].size() == 2)
                twoEdges.push_back(i);
            if(adj[i].size() > 2)
                possible = 0;
        }

        if(!possible)
            cout << "-1\n";

        else if(twoEdges.size() == 0)
            cout << "2\n";

        else if(twoEdges.size() == 1)
            cout << "2 3\n";

        else
        {
            dfs(oneEdge[0], -1, 2);

            for(i = 1; i < n; i++)
                cout << weights[edges[i]] << " ";
            cout << "\n";
        }
    }
}
