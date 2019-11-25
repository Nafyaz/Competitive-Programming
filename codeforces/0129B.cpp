#include<bits/stdc++.h>
using namespace std;

vector <int> adj[110];
vector <int> :: iterator it;

int main()
{
    int n, m, u, v, i;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue <pair<int, int> > q;
    int ans = 0;
    bool flag;
    while(1)
    {
        flag = 1;
        for(i = 1; i <= n; i++)
        {
            if(adj[i].size() == 1)
            {
                flag = 0;
                u = adj[i][0];
                q.push({u, i});
                adj[i].clear();
            }
        }
        if(flag)
            break;
        ans ++;
        while(!q.empty())
        {
            u = q.front().first;
            i = q.front().second;

            q.pop();
            it = find(adj[u].begin(), adj[u].end(), i);
            if(it != adj[u].end())
                adj[u].erase(it);

        }
    }

    printf("%d", ans);
}
