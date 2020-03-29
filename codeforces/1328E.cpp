#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m, par[200009], T, st[200009], ed[200009];
int anc[200009][20], level[200009];
vector<int> adj[200009];

void dfs(int s, int p, int l)
{
    par[s] = p;
    st[s] = ++T;
    level[s] = l;
    for(auto u : adj[s])
    {
        if(u != p)
        {
            dfs(u, s, l+1);
        }
    }
    ed[s] = ++T;
}

int main()
{
    int i, j, k, u, v;
    cin >> n >> m;

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0);

    while(m--)
    {
        set<pair<int, int>> p;
        cin >> k;
        while(k--)
        {
            cin >> u;
            u = par[u];
            p.insert({level[u], u});
        }
        vector<int> vec;
        for(auto u : p)
        {
            vec.push_back(u.ss);
//            cout << u.ff << " " << u.ss << endl;
        }

        int flag = 1;
        for(i = 0; i < vec.size()-1; i++)
        {
            if(st[vec[i]] >= st[vec[i+1]] || ed[vec[i]] <= ed[vec[i+1]])
            {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }

        if(flag)
            cout << "YES" << endl;
    }

}
