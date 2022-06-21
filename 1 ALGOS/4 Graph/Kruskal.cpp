#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int parent[10009], n, m;
vector<pair<int, pair<int, int> > >edges;

int Find(int a)
{
    if(parent[a] == a)
        return a;
    parent[a] = Find(parent[a]);
    return parent[a];
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    parent[a] = b;
}

int kruskal()
{
    int i, u, v, w, ret = 0;
    for(i = 0; i <= n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end());
    int cnt = 0;
    for(auto e : edge)
    {
        u = e.ss.ff;
        v = e.ss.ss;
        w = e.ff;

        if(Find(u) != Find(v))
        {
            Union(u, v);
            ret += w;
            cnt++;
            if(cnt == n-1)
                return ret;
        }
    }
}

int main()
{
    int i, j;

    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    kruskal();
}
