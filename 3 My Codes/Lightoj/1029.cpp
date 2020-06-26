#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int n;
vector <pair<int, pair<int, int> > > edges;
int parent[110];

void neg_weight()
{
    for(auto &p : edges)
        p.ff = -p.ff;
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
    int t, caseno = 0, u, v, w;
    scanf("%d", &t);
    while(t--)
    {
        edges.clear();
        scanf("%d", &n);
        while(1)
        {
            scanf("%d %d %d", &u, &v, &w);
            if(u || v || w)
                edges.push_back({w, {u, v}});
            else
                break;
        }

        int mn = kruskal();
        neg_weight();
        int mx = -kruskal();
        (mn+mx) % 2 == 0? printf("Case %d: %d\n", ++caseno, (mn+mx)/2) : printf("Case %d: %d/2\n", ++caseno, mn+mx);
    }
}
