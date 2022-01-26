#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int w[102];
vector<int> adj[100005];
vector<pair<int, pair<int, int>>> queries;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if(a.ss.ff != b.ss.ff)
        return a.ss.ff < b.ss.ff;

    return a.ss.ss > b.ss.ss;
}

int main()
{
    int n, m, q, u, v, i, p, a;

    cin >> n >> m >> q;

    for(i = 1; i <= n; i++)
        cin >> w[i];

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 0; i < q; i++)
    {
        queries.ff = i;
        cin >> queries.ss.ff >> queries.ss.ss;
    }

    sort(queries.begin(), queries.end(), cmp);

    for(i = 0; i < q; i++)
    {

    }
}
