#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
bool vis[1003];
int left[1003];

int main()
{
    int T, caseno = 0, n, m, i, u, v;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = left[i] = 0;
        }

        for(i = 0; i < m; i++)
        {
            cin >> u >> v;

            adj[u].push_back(v);
        }


    }
}
