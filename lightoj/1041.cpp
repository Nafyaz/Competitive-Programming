#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int n;
vector <pair<int, pair<int, int> > > edges;
int parent[110];

bool is_connected()
{
    int x = 0;
    for(int i = 1; i <= n; i++)
    {
        if(parent[i] == i)
            x++;
    }
    if(x>1)
        return 0;
    else
        return 1;
}
int find(int u)
{
    if(parent[u] == u)
        return u;
    parent[u] = find(parent[u]);
    return parent[u];
}

int merge(int u, int v)
{
    int x = find(u);
    int y = find(v);
    parent[x] = y;
}

int kruskal()
{
    int u, v, cost = 0, i;

    for(i = 0; i < 110; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end());

    for(auto p : edges)
    {
        u = p.ss.ff;
        v = p.ss.ss;
        if(find(u) == find(v))
            continue;
        else
        {
            merge(u, v);
            cost += p.ff;
        }
    }
    return cost;
}


int main()
{
    int t, caseno = 0, u, v, w, e;
    map<string, int> mp;
    string us, vs;
    scanf("%d", &t);
    while(t--)
    {
        mp.clear();
        edges.clear();
        n = 0;
        scanf("%d", &e);
        while(e--)
        {
            cin >> us >> vs;
            scanf("%d", &w);

            if(mp.find(us) == mp.end())
            {
                u = ++n;
                mp[us] = u;
            }
            if(mp.find(vs) == mp.end())
            {
                v = ++n;
                mp[vs] = v;
            }

            edges.push_back({w, {mp[us], mp[vs]}});
        }

        int mn = kruskal();

        is_connected() == 0? printf("Case %d: Impossible\n", ++caseno) : printf("Case %d: %d\n", ++caseno, mn);
    }
}


