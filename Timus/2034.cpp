#include<bits/stdc++.h>
using namespace std;

int dis[100009][4], vis[100009][4];
vector<int> adj[100009];
int n;

void bfs(int s, int type)
{
    queue<int> q;
    q.push(s);
    vis[s][type] = 1;
    dis[s][type] = 0;

    int p;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(auto u : adj[p])
        {
            if(!vis[u][type])
            {
                vis[u][type] = 1;
                dis[u][type] = dis[p][type] + 1;
                q.push(u);
            }
        }
    }
}

int main()
{
    int i, m, u, v, s, f, r;
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s >> f >> r;

    bfs(s, 1);
    bfs(f, 2);
    bfs(r, 3);

//    for(i = 1; i <= n; i++)
//        cout << i << " ";
//    cout << endl;
//    for(i = 1; i <= n; i++)
//        cout << dis[i][1] << " ";
//    cout << endl;
//    for(i = 1; i <= n; i++)
//        cout << dis[i][2] << " ";
//    cout << endl;
//    for(i = 1; i <= n; i++)
//        cout << dis[i][3] << " ";
//    cout << endl;

    int mxlevel[100009], level;
    memset(mxlevel, -1, sizeof mxlevel);
    for(int i = 1; i <= n; i++)
    {
        if(dis[i][1] + dis[i][2] == dis[f][1])
        {
            level = dis[i][1];
            mxlevel[level] = max(mxlevel[level], dis[i][3]);
        }
    }

    int ans = INT_MAX;
    for(i = 0; i <= n; i++)
    {
//        cout << mxlevel[i] << " ";
        if(mxlevel[i] != -1)
            ans = min(ans, mxlevel[i]);
    }

    cout << ans;
}
