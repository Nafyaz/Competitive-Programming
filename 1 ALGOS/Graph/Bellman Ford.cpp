#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1000000000;

void solve()
{
    vector<int> d (n, INF);
    vector<int> p (n, -1);
    d[v] = 0;
    bool any = 1;
    while(any)
    {
        any = 0;

        for (int j=0; j<m; j++)
        {
            if (d[e[j].a] < INF)
            {
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = 1;
                }
            }
        }
    }

    if (d[t] == INF)
        cout << "No path from " << v << " to " << t << ".";
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());

        cout << "Path from " << v << " to " << t << ": ";
        for (size_t i = 0; i < path.size(); i++)
            cout << path[i] << ' ';
    }
}