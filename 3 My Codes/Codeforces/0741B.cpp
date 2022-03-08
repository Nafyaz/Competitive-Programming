#include<bits/stdc++.h>
using namespace std;

int n;
int w[1003];
int b[1003];

int par[1003];

vector<int> group[1003];

int dp[1003][1003];

int Find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    par[max(x, y)] = min(x, y);
}

int knapsack(int g, int W)
{
    if(g > n)
        return 0;

    if(dp[g][W] != -1)
        return dp[g][W];

    int ret = knapsack(g+1, W);

    if(group[g].empty())
        return dp[g][W] = ret;


    int groupW = 0, groupB = 0;

    for(auto u : group[g])
    {
        if(w[u] <= W)
            ret = max(ret, b[u] + knapsack(g+1, W-w[u]));

        groupW += w[u];
        groupB += b[u];
    }

    if(groupW <= W)
        ret = max(ret, groupB + knapsack(g+1, W-groupW));

    return dp[g][W] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, W, i, x, y;

    cin >> n >> m >> W;

    for(i = 1; i <= n; i++)
    {
        cin >> w[i];
        par[i] = i;
    }
    for(i = 1; i <= n; i++)
        cin >> b[i];

    while(m--)
    {
        cin >> x >> y;

        Union(x, y);
    }

    for(i = 1; i <= n; i++)
        group[Find(i)].push_back(i);

    memset(dp, -1, sizeof dp);
    cout << knapsack(1, W) << "\n";
}
