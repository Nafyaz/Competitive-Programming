#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int sub[100005];
int depth[100005];

int dfs(int s, int d)
{
    depth[s] = d;
    int ret = 1;

    for(auto u : adj[s])
        ret += dfs(u, d+1);

    return sub[s] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, p;

    cin >> n;

    for(i = 2; i <= n; i++)
    {
        cin >> p;
        adj[p].push_back(i);
    }

    dfs(1, 1);

    for(i = 1; i <= n; i++)
        cout << (n - sub[i] - depth[i] + 1)/2.0 + depth[i] << " ";
}
