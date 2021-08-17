#include<bits/stdc++.h>
using namespace std;

int n, color[10009], fix[10009], ans;
vector<int> adj[10009];

void func(int s)
{
    for(auto u : adj[s])
    {
        if(!fix[u] && color[s] == color[u])
        {
            color[u]++;
            ans = max(ans, color[u]);
        }
    }
}

int main()
{
    int i, m, x, y;

    cin >> n >> m;

    for(i = 1; i < n; i++)
    {
        color[i] = 1;

        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }
    color[n] = 1;

    adj[n].push_back(1);
    adj[1].push_back(n);

    while(m--)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i = 1; i <= n; i++)
    {
        fix[i] = 1;
        func(i);
    }

    cout << ans << "\n";
    for(i = 1; i <= n; i++)
        cout << color[i] << " ";
}
/*
5 2
2 5
2 4
*/
