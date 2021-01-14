#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second

bool func(pair<pii, int> a, pair<pii, int> b)
{
    if(a.ff.ff != b.ff.ff)
        return a.ff.ff > b.ff.ff;
    return a.ff.ss < b.ff.ss;
}

int main()
{
    int n, i, l, r, t;
    vector<pair<pii, int>> v;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> l >> r;
        v.push_back({{l, r}, i});
    }
    sort(v.begin(), v.end(), func);

    map<int, int> mp;

    for(i = 0; i < (int)v.size(); i++)
    {
        t = v[i].ff.ss;
        while(mp.find(t) != mp.end())
            t--;

        mp[t] = v[i].ss;
    }

    int ans[109];
    for(auto u : mp)
        ans[u.ss] = u.ff;

    for(i = 0; i < n; i++)
        cout << ans[i] << " ";
}
