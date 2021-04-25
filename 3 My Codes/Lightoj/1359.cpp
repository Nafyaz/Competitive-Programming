#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

int n, m;
vector<pii> adj[100009];

int main()
{
    int T, i, k, u, v, w, q;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        for(i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        cin >> q;

        while(q--)
        {
            cin >> k;
            for(i = 0; i < k; i++)
            {
                cin >>
            }
        }
    }
}
