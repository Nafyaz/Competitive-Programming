#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
bool vis[700005];
vector<int> adj[700005];
ll nodeColor[700005];
ll colorCnt[2];

bool dfs(ll s, ll color)
{
    if(s <= n)
        colorCnt[color]++;
    nodeColor[s] = color;
    vis[s] = 1;

    bool ret = 1;

    for(auto u : adj[s])
    {
        if(!vis[u])
            ret &= dfs(u, 3-color);
        else if(nodeColor[u] == color)
            return 0;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i, j, fakeNode, flag, ans;
    string c;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i <= n+m; i++)
        {
            vis[i] = 0;
            adj[i].clear();
            nodeColor[i] = 0;
        }

        fakeNode = n+1;
        while(m--)
        {
            cin >> i >> j >> c;

            if(c == "crewmate")
            {
                adj[i].push_back(fakeNode);
                adj[fakeNode].push_back(i);

                adj[j].push_back(fakeNode);
                adj[fakeNode].push_back(j);

                fakeNode++;
            }
            else
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

        ans = 0;
        flag = 1;
        for(i = 1; i <= n && flag; i++)
        {
            colorCnt[1] = colorCnt[2] = 0;
            if(!vis[i])
            {
                if(dfs(i, 1))
                    ans += max(colorCnt[1], colorCnt[2]);
                else
                    flag = 0;
            }
        }

        cout << (flag? ans : -1) << "\n";
    }
}
