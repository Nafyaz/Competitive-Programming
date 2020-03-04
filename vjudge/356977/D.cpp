#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.ff.ff != b.ff.ff)
        return a.ff.ff > b.ff.ff;
    return a.ff.ss < b.ff.ss;
}

int main()
{
    int n, p, i;
    string s, ar[1009];
    vector<pair<pair<int, int>, int>> v;
    map<string, int> mp;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> s >> p;
        if(mp.find(s) == mp.end())
        {
            v.push_back({{p, i}, v.size() + 1});
            mp[s] = v.size();
            ar[v.size()] = s;
        }
        else
        {
            v[mp[s] - 1].ff.ff += p;
            v[mp[s] - 1].ff.ss = i;
        }
//            cout << v[mp[s] - 1].ff.ff << " " << v[mp[s] - 1].ff.ss << " " << v[mp[s] - 1].ss << endl;
    }

//    cout << "ok" << endl;
//
    for(auto u : v)
        cout << ar[u.ss] << " " << u.ff.ff << " " << u.ff.ss << " " << u.ss << endl;

    sort(v.begin(), v.end(), cmp);

    cout << ar[v[0].ss] << endl;
}
