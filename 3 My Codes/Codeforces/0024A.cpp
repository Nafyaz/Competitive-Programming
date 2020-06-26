#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<pair<int, int>> adj[109];
int vis[109];

int dfs(int s, int par, int mul)
{
//    cout << s << " " << par << " " << mul << endl;
    if(vis[s])
        return 0;
    vis[s] = 1;

    for(auto u : adj[s])
    {
        if(u.ss != par)
            return max(0, mul*u.ff) + dfs(u.ss, s, mul);
    }
}

int main()
{
    int n, i, j, a, b, c, ans;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({-c, a});

    }
    ans = INT_MAX;
//    cout << "lol\n";
    ans = min(ans, dfs(1, -1, 1));
//    cout << "lol\n";
    memset(vis, 0, sizeof vis);
    ans = min(ans, dfs(1, -1, -1));

    cout << ans;
}
