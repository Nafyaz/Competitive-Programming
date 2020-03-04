#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    ll i, j, n, m, k, x;

    cin >> n >> m >> k;
    if(k > 4*n*m - 2*n - 2*m)
    {
        cout << "NO";
        return 0;
    }


    vector<pair<ll, string> > v, ans;

    if(m > 1)
    {
        v.push_back({m-1, "R"});
        v.push_back({m-1, "L"});
    }

    for(i = 1; i < n; i++)
    {
        if(m > 1)
            v.push_back({m-1, "DRU"});
        v.push_back({1, "D"});
        if(m > 1)
            v.push_back({m-1, "L"});
    }

    if(n > 1)
        v.push_back({n-1, "U"});

    i = 0;
    for(auto u : v)
    {
//        cout << k << " " << u.ff << " " << u.ss << endl;
        if(k >= u.ff*u.ss.size())
        {
            k -= u.ff*u.ss.size();
            ans.push_back(u);
        }
        else if(k)
        {
            if(k/u.ss.size())
                ans.push_back({k/u.ss.size(), u.ss});
            k -= k/u.ss.size()*u.ss.size();
            if(k)
                ans.push_back({1, u.ss.substr(0, k) });
            break;
        }
        else
            break;
    }

    cout << "YES" << endl << ans.size() << endl;

    for(auto u : ans)
        cout << u.ff << " " << u.ss << endl;
}
