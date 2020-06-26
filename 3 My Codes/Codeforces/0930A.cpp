#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int n, parent[100009], level[100009];
int apples[100009];
vector<int> adj[100009];

void bfs(int s)
{
    int node;
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        node = q.front();
        q.pop();
        for(auto u : adj[node])
        {
            if(u != parent[node])
            {
                parent[u] = node;
                level[u] = level[node] + 1;
                apples[level[node]]++;
                q.push(u);
            }
        }
    }
}

int main()
{
    int a, i;
    cin >> n;
    for(i = 2; i <= n; i++)
    {
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    bfs(1);

    int ans = 1;
    for(i = 0; i <= n; i++)
        ans += apples[i]%2;

    cout << ans;
}
