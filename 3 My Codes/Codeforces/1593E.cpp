#include<bits/stdc++.h>
using namespace std;

vector<int> adj[400005];
int rem[400005], layer[400005];

int main()
{
    int T, n, k, i, u, v, node, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        for(i = 1; i <= n; i++)
            adj[i].clear();
        memset(rem, 0, sizeof rem);
        memset(layer, 0, sizeof layer);

        for(i = 1; i <= n-1; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

            rem[u]++;
            rem[v]++;
        }

        queue<int> q;
        for(i = 1; i <= n; i++)
        {
            if(rem[i] <= 1)
            {
                q.push(i);
                layer[i] = 1;

                if(rem[i] == 1)
                    rem[i]--;
            }
        }

        while(!q.empty())
        {
            node = q.front();
            q.pop();

            for(auto next : adj[node])
            {
                if(layer[next] != 0 && layer[next] <= layer[node])
                    continue;

                rem[next]--;
                if(rem[next] <= 1)
                {
                    q.push(next);
                    layer[next] = layer[node] + 1;

                    if(rem[next] == 1)
                        rem[next]--;
                }
            }
        }

        ans = 0;
        for(i = 1; i <= n; i++)
        {
            if(layer[i] > k)
                ans++;
        }

        cout << ans << "\n";
    }
}
