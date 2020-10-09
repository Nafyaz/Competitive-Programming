#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1009];
int dis[1009];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto u : adj[node])
        {
            if(dis[u] == -1)
            {
                q.push(u);
                dis[u] = dis[node] + 6;
            }
        }
    }
}

int main()
{
    int q, v, e, s, i, j, x, y;
    cin >> q;
    while(q--)
    {
        cin >> v >> e;
        for(i = 1; i <= v; i++)
        {
            adj[i].clear();
            dis[i] = -1;
        }

        while(e--)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cin >> s;


        bfs(s);

        for(i = 1; i <= v; i++)
        {
            if(i != s)
                cout << dis[i] << " ";
        }

        cout << "\n";
    }
}

