#include<bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int>V[N];
int dis[N];
bool vis[N];

void bfs(int s)
{
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(int i=0;i<V[x].size();i++)
        {
            int u=V[x][i];
            if(!vis[u])
            {
                vis[u]=1;
                dis[u]=dis[x]+1;
                Q.push(u);
            }
        }
    }
    return;
}

int main()
{
    int node,edge;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u); //Bi-directional
    }
    bfs(1); //Shortest Distance from node 1
}
