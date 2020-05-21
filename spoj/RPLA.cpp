#include<bits/stdc++.h>
using namespace std;

const int N = 1009;
vector<int> adj[N];
int rnk[N], in[N], path, mxrnk, n, m;
set<int> rnkset[N];

void topsort()
{
    int i;
    queue<int> Q;
    for(i = 0; i < n; i++)
    {
        if(in[i] == 0)
        {
            Q.push(i);
            rnkset[1].insert(i);
            rnk[i] = 1;
            mxrnk = max(mxrnk, rnk[i]);
        }
    }

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        path++;
        for(auto u : adj[node])
        {
            in[u]--;
            if(in[u] == 0)
            {
                Q.push(u);
                rnk[u] = rnk[node] + 1;
                rnkset[rnk[u]].insert(u);
                mxrnk = max(mxrnk, rnk[u]);
            }
        }
    }
}

int main()
{
    int t, caseno = 0, i, a, b;
    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            rnkset[i].clear();
            in[i] = 0;
        }
        path = 0;
        mxrnk = 0;

        for(i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[b].push_back(a);
            in[a]++;
        }

        topsort();

        cout << "Scenario #" << ++caseno << ":\n";
        for(i = 1; i <= mxrnk; i++)
        {
            for(auto u : rnkset[i])
            {
                cout << i << " " << u << endl;
            }
        }
    }
}
