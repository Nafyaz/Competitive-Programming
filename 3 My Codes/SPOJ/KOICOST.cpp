#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m, mod = 1000000000;
vector<pair<int, pair<int, int> > > edge;
int par[100009];

int Find(int a)
{
    if(par[a] == a)
        return a;
    return par[a] = Find(par[a]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
        par[a] = b;
}

int kruskal()
{
    int i, u, v, w, sum = 0, ret = 0;
    for(i = 0; i <= n; i++)
        par[i] = i;

    sort(edge.begin(), edge.end());

    for(auto e : edge)
    {
        u = e.ss.ff;
        v = e.ss.ss;
        w = e.ff;
        sum = (sum + w)%mod;
        if(Find(u) != Find(v))
        {
            ret = (ret + sum)%mod;
            Union(u, v);
        }
    }

    return ret;
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

    cout << kruskal();
}
