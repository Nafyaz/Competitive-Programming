//Depth First Search
#include<bits/stdc++.h>
using namespace std;

int n, m;
int Time[102], t;
bool visited[102];
vector<int> adj[102];

void dfs(int s)
{
    Time[s] = ++t;
    visited[s] = 1;

    for(auto u : adj[s])
    {
        if(!visited[u])
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

    dfs(1);

    for(i = 1; i <= n; i++)
        cout << i << ": " << Time[i] << "\n";
}
