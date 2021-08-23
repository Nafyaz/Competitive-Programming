#include<bits/stdc++.h>
using namespace std;

int n, m, x;

vector<int> adj[100005];
bool visited[100005];

void dfs(int s)
{
    visited[s] = 1;

    for(auto u : adj[s])
    {
        if(!visited[u] && u != x)
            dfs(u);
    }
}

int main()
{
    int i, a, b;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> x;

    dfs(!x);

    for(i = 0; i < n; i++)
    {
        if(i != x && !visited[i])
        {
            cout << "Not Connected";
            return 0;
        }
    }

    cout << "Connected";
}
