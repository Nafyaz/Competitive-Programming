#include<bits/stdc++.h>
using namespace std;

int dist[100009], mx;
vector<int> adj[100009];

void dfs(int i, int p)
{
    int leafcnt = 0;
    for(auto u : adj[i])
    {
        if(u == p)
            continue;
        dist[u] = !dist[i];
        if(adj[u].size() == 1)
        {
            leafcnt++;
//            cout << leafcnt  << " " << u << endl;
            if(leafcnt > 1)
                mx--;
        }
        else
            dfs(u, i);
    }
}

int main()
{
    int n, u, v, i;

    cin >> n;
    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 1;
    while(adj[root].size() == 1)
        root++;

//    cout << root << endl;

    mx = n-1;
    dfs(root, 0);

    bool odd = 0, even = 0;
    for(i = 1; i <= n; i++)
    {
        if(adj[i].size() == 1)
        {
            if(dist[i])
                even = 1;
            else
                odd = 1;
        }
    }

    cout << ((odd && even)? 3 : 1) << " " << mx;
}
