#include<bits/stdc++.h>
using namespace std;

int in_degree[100005];
vector <int> adj;
queue <int> q;
void bfs()
{

}

int main()
{
    int node,edge;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=node;i++)
    {
        for(auto j : adj[i])
            in_degree[j]++;
    }


}
