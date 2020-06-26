#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m;
vector<pair<int, int> > v;
vector<int> x[2], inter;

void func(int a, int type)
{
    for(int i = 0; i < m; i++)
    {
        if(v[i].ff != a && v[i].ss != a)
            x[type].push_back(i);
    }
}

int main()
{
    int i, a, b;
    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }

    //fixing x
    func(v[0].ff, 0);
    if(x[0].size() == 0)
    {
        cout << "YES";
        return 0;
    }

    //fixing y
    func(v[x[0][0]].ff, 1);
    if(x[1].size() == 0)
    {
        cout << "YES";
        return 0;
    }

    set_intersection(x[0].begin(), x[0].end(), x[1].begin(), x[1].end(), back_inserter(inter));

    if(inter.size() == 0)
    {
        cout << "YES";
        return 0;
    }

    //fixing y
    x[1].clear();
    func(v[x[0][0]].ss, 1);
    if(x[1].size() == 0)
    {
        cout << "YES";
        return 0;
    }

    inter.clear();
    set_intersection(x[0].begin(), x[0].end(), x[1].begin(), x[1].end(), back_inserter(inter));
    if(inter.size() == 0)
    {
        cout << "YES";
        return 0;
    }

    //fixing x
    x[0].clear();
    func(v[0].ss, 0);
    if(x[0].size() == 0)
    {
        cout << "YES";
        return 0;
    }

    //fixing y
    x[1].clear();
    func(v[x[0][0]].ff, 1);
    if(x[1].size() == 0)
    {
        cout << "YES";
        return 0;
    }

    inter.clear();
    set_intersection(x[0].begin(), x[0].end(), x[1].begin(), x[1].end(), back_inserter(inter));
    if(inter.size() == 0)
    {
        cout << "YES";
        return 0;
    }

    //fixing y
    x[1].clear();
    func(v[x[0][0]].ss, 1);
    if(x[1].size() == 0)
    {
        cout << "YES";
        return 0;
    }

    inter.clear();
    set_intersection(x[0].begin(), x[0].end(), x[1].begin(), x[1].end(), back_inserter(inter));

    if(inter.size() == 0)
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";
}
