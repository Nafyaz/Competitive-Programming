#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
vector<int> inTree;
int sz[200005], posInTree[200005];

int dfs(int s)
{
    inTree.push_back(s);

    sz[s] = 1;

    for(auto u : adj[s])
        sz[s] += dfs(u);

    return sz[s];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, p, i, u, k;

    cin >> n >> q;

    for(i = 2; i <= n; i++)
    {
        cin >> p;

        adj[p].push_back(i);
    }

    dfs(1);

    for(i = 0; i < n; i++)
        posInTree[inTree[i]] = i;

    while(q--)
    {
        cin >> u >> k;

        if(k > sz[u])
        {
            cout << "-1\n";
            continue;
        }

        p = posInTree[u];
        cout << inTree[p+k-1] << "\n";
    }
}
