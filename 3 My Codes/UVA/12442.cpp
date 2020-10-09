#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back

int N, a, b;
int adj[50009], sum[50009];
bool vis[50009];

int dfs(int u)
{
    vis[u] = 1;
    int ret = 1;
    if(adj[u] != -1 && !vis[adj[u]])
        ret = 1 + dfs(adj[u]);
    vis[u] = 0;
    return sum[u] = ret;
}

int main()
{
    int T, caseno = 0, i;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(i = 1; i <= N; i++)
        {
            adj[i] = -1;
            sum[i] = -1;
            vis[i] = 0;
        }

        for(i = 0; i < N; i++)
        {
            cin >> a >> b;
            adj[a] = b;
        }

        int ans = 0, max_len = 0;
        for(i = 1; i <= N; i++)
        {
            if(sum[i] == -1)
                dfs(i);
            if(sum[i] > max_len)
            {
                max_len = sum[i];
                ans = i;
            }
        }
        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
