#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, parent[100010];
vector <pair <int, pair< int, int> > > edges;

int find(int x)
{
    if(parent[x] == x)
        return x;
    else
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int u, int v)
{
    int x = find(u);
    int y = find(v);

    parent[x] = y;
}

int kruskal()
{
    int i;

    sort(edges.begin(), edges.end());
    for(i = 0; i < n+5; i++)
            parent[i] = i;

    int u, v, w, cost = 0;

    for(i = 0; i < edges.size(); i++)
    {
        u = edges[i].ss.ff;
        v = edges[i].ss.ss;
        w = edges[i].ff;

        if(find(u) != find(v))
        {
            merge(u, v);
            cost += w;
        }
    }

    return cost;
}

int main()
{
    int m, T, caseno = 0, i, u, v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);

        edges.clear();
        for(i = 0; i < n+5; i++)
            parent[i] = i;

        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            edges.push_back({1, {u, v}});
            merge(u, v);
        }

        for(i = 2; i <= n; i++)
        {
            if(find(1) != find(i))
            {
                edges.push_back({2, {1, i}});
                merge(1, i);
            }
        }

        printf("Case #%d: %d\n", ++caseno, kruskal());
    }
}
