#include<bits/stdc++.h>
using namespace std;

int ans[200005];
vector<int> adj[200005];

int parent[200005];

int Find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

int Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x != y)
    {
        parent[min(x, y)] = max(x, y);

        return 1;
    }
    return 0;
}

int main()
{
    int n, m, a, b, i;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans[n] = 0;

    for(i = n; i >= 1; i--)
    {
        parent[i-1] = i-1;
        ans[i-1] = ans[i] + 1;

        for(auto u : adj[i])
        {
            if(u > i)
                ans[i-1] -= Union(i, u);
        }
    }

    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
