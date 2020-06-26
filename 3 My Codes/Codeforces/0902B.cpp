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

int n, color[10009], ans;
vector<int> adj[10009];

void bfs(int s)
{
    queue<int> q;

    int p;
    q.push(s);
    ans++;

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        for(auto u : adj[p])
        {
            if(color[u] != color[p])
                ans++;
            q.push(u);
        }
    }
}

int main()
{
    int i, x;
    cin >> n;

    for(i = 2; i <= n; i++)
    {
        cin >> x;
        adj[x].push_back(i);
    }

    for(i = 1; i <= n; i++)
        cin >> color[i];

    bfs(1);

    cout << ans;
}
