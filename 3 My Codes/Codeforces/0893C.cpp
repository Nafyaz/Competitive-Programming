#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e, i, j, x, y, node, len;
    scanf("%d %d", &n, &e);

    int gold[n+1];
    for(i = 1; i <= n; i++)
        scanf("%d", &gold[i]);

    vector <int> v[n + 1];
    for(i = 1; i <= e; i++)
    {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }


    int min_gold;
    long long sum_gold = 0;
    queue <int> q;
    int vis[n+1];
    for(i = 0; i <= n; i++)
        vis[i] = 0;

    for(i = 1; i <= n; i++)
    {
        if(vis[i] == 1)
            continue;

        q.push(i);
        vis[i] = 1;
        min_gold = gold[i];
        while(!q.empty())
        {
            node = q.front();
            q.pop();
            len = v[node].size();
            for(j = 0; j < len; j++)
            {
                if(vis[v[node][j]] == 0)
                {
                    q.push(v[node][j]);
                    vis[v[node][j]] = 1;
                }
            }
            if(gold[node] < min_gold)
                min_gold = gold[node];
        }
        sum_gold += min_gold;
    }
    printf("%lld", sum_gold);
}
