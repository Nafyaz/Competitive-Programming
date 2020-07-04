#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[109];

int main()
{
    int m, i, j, k;
    cin >> m;
    while(m--)
    {
        cin >> n >> k;
        for(i = 0; i <= n; i++)
            adj.clear();

        for(i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(i = 0; i < )
    }
}
