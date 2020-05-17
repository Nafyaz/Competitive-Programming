#include<bits/stdc++.h>
using namespace std;

int n, m, k, dis[30009];
set<tuple<int, int, int> > forbidden;
vector<int> adj[30009];

int main()
{
    int u, v, w, i;
    cin >> n >> m >> k;
    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 0; i < k; i++)
    {
        cin >> u >> v >> w;
        forbidden.insert(make_tuple(u, v, w));
    }


}
