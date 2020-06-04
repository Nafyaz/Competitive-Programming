#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, par[109];
vector<pair<int, pair<int, int>>> edges;

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
    par[a] = b;
}

int kruskal()
{
    for(int i = 1; i <= n; i++)
        par[i] = i;

    int ret = 0, a, b, c;
    sort(edges.begin(), edges.end());

    for(auto e : edges)
    {
        c = e.ff;
        a = e.ss.ff;
        b = e.ss.ss;
        if(Find(a) != Find(b))
        {
            ret += c;
            Union(a, b);
        }
    }
    return ret;
}

int main()
{
    int i, j;
    string s;
    cin >> n;
    for(i = 2; i <= n; i++)
    {
        for(j = 1; j < i; j++)
        {
            cin >> s;
            if(s == "x")
                continue;
            int c = stoi(s);
            edges.push_back({c, {i, j}});
        }

        for(auto e : edges)
            cout << e.ff << " " << e.ss.ff << " " << e.ss.ss << "; ";
        cout << endl;
    }

    cout << kruskal();
}
/*
5
50
30  5
100  20  50
10  x  x  10
*/
