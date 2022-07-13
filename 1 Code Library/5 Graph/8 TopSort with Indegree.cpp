#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
vector<int> adj[N];
vector<int> path;
int in[N];

void topsort()
{
    queue<int> Q;
    int i;
    for(i = 1; i <= n; i++)
    {
        if(in[i] == 0)
            Q.push(i);
    }
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        path.push_back(node);
        for(auto u : adj[node])
        {
            in[u]--;
            if(in[u] == 0)
                Q.push(u);
        }
    }
}

int main()
{
    int i, m;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    topsort();

    if(path.size() != n)
        cout << "impossible";
    else
    {
        for(i = 0; i < path.size(); i++)
            cout << path[i] << " ";
    }

}
