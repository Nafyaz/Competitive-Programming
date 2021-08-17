//Breadth First Search
#include<bits/stdc++.h>
using namespace std;

int Time[102], t;
int n, m;
bool visited[102];
vector<int> adj[102];
int dis[102];

void bfs(int s)
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        visited[i] = 0;
    }

    queue<int> q;

    q.push(s);
    Time[s] = ++t;
    dis[s] = 0;
    visited[s] = 1;

    while(!q.empty())
    {
        int from = q.front();
        q.pop();

        for(auto to : adj[from])
        {
            if(!visited[to])
            {
                q.push(to);
                Time[to] = ++t;
                dis[to] = dis[from] + 1;
                visited[to] = 1;
            }
        }
    }
}

int main()
{
    int i, a, b;
    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    for(i = 1; i <= n; i++)
        cout << i << ": " << Time[i] << "\n";

}
/*
5 5
1 2
1 3
2 5
3 4
5 4
*/
