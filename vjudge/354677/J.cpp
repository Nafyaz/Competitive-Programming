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
    int t, n, i, l, r;
    vector<pair<pair<int, int>, int> > v(100009);
    int ans[100009];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> l >> r;
            v[i] = {{l, r}, i};
        }

        sort(v.begin(), v.begin() + n);
//        for(i = 0; i < 4; i++)
//            cout << v[i].ff.ff << " " << v[i].ff.ss << " " << v[i].ss << endl;

        ans[v[0].ss] = 1;
        for(i = 1; i < n; i++)
        {
            ans[v[i].ss] = ans[v[i-1].ss]^1;
//            cout << ans[v[i-1].ss] << " " << ans[v[i].ss] << endl;
        }
        for(i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
    }
}
