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

int main()
{
    ll t, n, a, b, c, f, i, mn ;
    cin >> t;
    while(t--)
    {
        mn = LLONG_MAX;
        cin >> n >> a >> b >> c;
        for(i = 0; i < n; i++)
        {
            cin >> f;
            mn = min(mn, c + abs(a-f) + abs(b-f));
        }

        cout << mn << endl;
    }
}

