#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long

void solve()
{
    ll n, i, a, ans = 0;

    cin >> n;

    ordered_set<pair<ll, ll>> os;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(!i)
        {
            os.insert({a, 0});
            continue;
        }

        if(os.order_of_key({a, -1}) <= os.size() - os.order_of_key({a+1, -1}))
            ans += os.order_of_key({a, -1});
        else
            ans += os.size() - os.order_of_key({a+1, -1});

        os.insert({a, i});
    }

    cout << ans << "\n";
}

int main()
{
    ll t;

    cin >> t;

    while(t--)
    {
        solve();
    }
}
