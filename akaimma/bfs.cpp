#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e, i, x, y, node;
    scanf("%d %d", &n, &e);

    vector <int> v[n+1];
    for(i = 0; i < e; i++)
    {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int vis[n+1];
    memset(vis, -1, sizeof(vis));

    queue <int> q;
    q.push(1);
    int prev_color = 1;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        if(vis[node] == 1)
        int len = v[node].size();
        for(i = 0; i < len; i++)
            q.push(v[node][i]);

    }
}
