#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define N 100009

int n, subtime[N], subsize[N], len[N];
vector<pair<int, int>> adj[N];
bool visited[N];

void find_subsize(int s)
{
    visited[s] = 1;
    int ret1 = 0, ret2 = 1;

    for(auto u : adj[s])
    {
        if(!visited[u.ss])
        {
            find_subsize(u.ss);
            ret1 = ret1 + u.ff + subtime[u.ss];
            ret2 = ret2 + subsize[u.ss];
        }
    }

    subtime[s] = ret1;
    subsize[s] = ret2;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return subtime[a.ss]*subsize[b.ss] <= subtime[b.ss]*subsize[a.ss];
}

void find_len(int s, int dist)
{
    visited[s] = 1;
    len[s] = dist;

    for(auto u : adj[s])
    {
        if(!visited[u.ss])
        {
            find_len(u.ss, dist + u.ff);
            dist = dist + u.ff + 2*subtime[u.ss] + u.ff;
        }
    }
}

int main()
{
    int a, b, t, i;
    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> a >> b >> t;
        adj[a].push_back({t, b});
        adj[b].push_back({t, a});
    }

    find_subsize(1);

    for(i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), cmp);

    memset(visited, 0, sizeof visited);
    find_len(1, 0);

    int ans = 0;
    for(i = 1; i <= n; i++)
        ans += len[i];

    cout << fixed;
    cout << setprecision(6) << (double)ans / (n-1);
}
