#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

bool vis[200005];
vector<pair<ll, ll>> adj[200005];
ll nodeColor[200005];
ll colorCnt[3];

bool dfs(ll s, ll color)
{
    vis[s] = 1;
    nodeColor[s] = color;
    colorCnt[color]++;

    bool ret = 1;
    for(auto u : adj[s])
    {
        if(!vis[u.ss])
        {
            if(u.ff == 1)
                ret &= dfs(u.ss, 3-color);
            else
                ret &= dfs(u.ss, color);
        }
        else
        {
            if(u.ff == 1 && nodeColor[u.ss] == color)
                return 0;
            if(u.ff == 0 && nodeColor[u.ss] != color)
                return 0;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, m, i, j, flag, ans;
    string c;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(i = 1; i <= n; i++)
        {
            vis[i] = 0;
            adj[i].clear();
            nodeColor[i] = 0;
        }

        while(m--)
        {
            cin >> i >> j >> c;

            if(c == "crewmate")
            {
                adj[i].push_back({0, j});
                adj[j].push_back({0, i});
            }
            else
            {
                adj[i].push_back({1, j});
                adj[j].push_back({1, i});
            }
        }

        ans = 0;
        flag = 1;
        for(i = 1; i <= n && flag; i++)
        {
            if(!vis[i])
            {
                colorCnt[1] = colorCnt[2] = 0;
                if(dfs(i, 1))
                    ans += max(colorCnt[1], colorCnt[2]);
                else
                    flag = 0;
            }
        }

        cout << (flag? ans : -1) << "\n";
    }
}
