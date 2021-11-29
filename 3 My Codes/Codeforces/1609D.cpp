#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int par[1003], sz[1003];
vector<pair<int, int>> v;

int Find(int x)
{
    if(par[x] == x)
        return x;

    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x != y)
    {
        if(x > y)
            swap(x, y);

//        if(x == 1 && y == 2)
//        {
//            for(auto u : v)
//                cout << u.ff << ": " << u.ss << "; ";
//            cout << "\n";
//        }
//
//        cout << sz[x] << "#" << x << "\n";

        v.erase(find(v.begin(), v.end(), make_pair(sz[x], x)));

//        if(x == 1 && y == 2)
//        {
//            for(auto u : v)
//                cout << u.ff << ": " << u.ss << "; ";
//            cout << "\n";
//        }


        v.erase(find(v.begin(), v.end(), make_pair(sz[y], y)));

        par[x] = y;
        sz[y] += sz[x];

        v.push_back({sz[y], y});
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, d, i, x, y, extra, ans;

    cin >> n >> d;

    for(i = 1; i <= n; i++)
    {
        par[i] = i;
        v.push_back({1, i});
        sz[i] = 1;
    }

    extra = 0;
    while(d--)
    {
        cin >> x >> y;

//        if(d == 5)
//        {
//            cout << Find(x) << "#" << Find(y) << "\n";
//        }

        if(Find(x) != Find(y))
            Union(x, y);
        else
            extra++;

//        if(d == 5)
//        {
//            for(auto u : v)
//                cout << u.ff << ": " << u.ss << "; ";
//            cout << "\n";
//        }

        sort(v.begin(), v.end());

        ans = 0;
        for(i = (int)v.size()-1; i >= 0 && i >= (int)v.size() - extra - 1; i--)
            ans += v[i].ff;

        cout << ans-1 << "\n";
    }
}
