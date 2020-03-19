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
        return a.ff.ff < b.ff.ff;
    return a.ff.ss > b.ff.ss;
}

int main()
{
    int t, n, i, l, r, lastblue;
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

        sort(v.begin(), v.begin() + n, cmp);
//        for(i = 0; i < n; i++)
//            cout << v[i].ff.ff << " " << v[i].ff.ss << " " << v[i].ss << endl;

        ans[v[0].ss] = 1;
        lastblue = v[0].ff.ss;
        for(i = 1; i < n; i++)
        {
            if(v[i].ff.ff <= lastblue)
                ans[v[i].ss] = 0;
            else
                ans[v[i].ss] = 1;

            if(ans[v[i].ss] == 1)
                lastblue = max(lastblue, v[i].ff.ss);
            else if(v[i].ff.ss >= lastblue)
                lastblue = min(lastblue, v[i].ff.ff-1);

//            cout << ans[v[i-1].ss] << " " << ans[v[i].ss] << endl;
        }
        for(i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
    }
}
