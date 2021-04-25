#include<bits/stdc++.h>
using namespace std;
#define N 200009
#define pii pair<int, int>
#define ff first
#define ss second

int n, m;
vector<pii> adj[N];
bool unuseful[N];
int vis[N], ans;

void dfs(int s)
{
    vis[s] = 1;
    for(auto u : adj[s])
    {
        if(vis[u.ff] == 1)
        {
            unuseful[u.ss] = 1;
            ans++;
        }
        else  if(vis[u.ff] == 0)
            dfs(u.ff);
    }

    vis[s] = 2;
}

int main()
{
    int i, u, v;

    while(cin >> n >> m)
    {
        ans = 0;
        memset(unuseful, 0, sizeof unuseful);

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }

        for(i = 1; i <= m; i++)
        {
            cin >> u >> v;
            adj[u].push_back({v, i});
        }

        dfs(1);

        cout << m-ans << "\n";
        for(i = 1; i <= m; i++)
        {
            if(!unuseful[i])
                cout << i << " ";
        }
        cout << "\n";
    }
}
