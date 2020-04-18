#include<bits/stdc++.h>
using namespace std;

int c[100009];
vector<int> adj[100009];
set<int> colors;
set<pair<int, int> > edge;

int main()
{

    int n, m, i, j, a, b;
    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> c[i];
        colors.insert(c[i]);
    }

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        a = c[a];
        b = c[b];
        if(a == b || edge.find({a, b}) != edge.end())
            continue;

        edge.insert({a, b});
        edge.insert({b, a});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mx = -1, ans = -1;
    for(auto u : colors)
    {
        if((int)adj[u].size() > mx)
        {
            ans = u;
            mx = adj[u].size();
        }
    }

    cout << ans;
}
