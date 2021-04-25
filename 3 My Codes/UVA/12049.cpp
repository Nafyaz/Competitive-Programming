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
    int t, n, m, i, x, ans;
    map<int, int> a, b;
    cin >> t;
    while(t--)
    {   a.clear();
        b.clear();
        ans = 0;

        cin >> n >> m;
        for(i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
        }
        for(i = 0; i < m; i++)
        {
            cin >> x;
            b[x]++;
        }

        for(auto u : a)
        {
            ans+= min(u.ss, b[u.ff]);
        }

        cout << n+m - 2*ans << endl;
    }
}

