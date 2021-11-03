#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int edgeCnt[1003], killed[1003], aware[1003];
vector<int> adj[1003];

int main()
{
    int T, caseno = 0, n, m, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            edgeCnt[i] = 0;
            killed[i] = 0;
            aware[i] = 0;
        }

        for(i = 0; i < m; i++)
        {
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
            edgeCnt[a]++;
            edgeCnt[b]++;
        }

        queue<pair<int, int>> q;
        for(i = 1; i <= n; i++)
        {
            if(edgeCnt[i] <= 1)
                q.push({i, 1});
        }

        while(!q.empty())
        {
            pair<int, int> p = q.front();
            if(p.ss == 1)
                ans++;
            for()
        }
    }
}
