#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n;

int color[10009], ans;
vector<int> adj[10009];

void func(pair<int, int> p, pair<int, int> q)
{
    int s = p.ff;

    while(s != p.ss)
    {
        for(auto u : adj[s])
        {
            if({u, s} == q)
            func(p, )
        }
        s ++;
        if(s == q.ff)
            s = q.ss;
    }
}

int main()
{
    int n, m, x, y;

    cin >> n >> m;

    while(m--)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    func({1, n}, {-1, -1});
}
