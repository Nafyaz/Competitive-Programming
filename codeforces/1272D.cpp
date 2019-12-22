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
    int i, x, n;
    cin >> n;
    int a[n];
    vector <pair<int, int> > v;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mx = -1;
    for(i = 0; i < n; i++)
    {
        if(i > 0 && a[i] > a[i-1])
            v.back().ss++;
        else
            v.push_back({i, i});

        mx = max(mx, v.back().ss - v.back().ff + 1);
    }

    int p, q;
    for(i = 1; i < v.size(); i++)
    {
        p = v[i-1].ss;
        q = v[i].ff;

//        cout << p << " " << q << endl;

        if(p + 2 < q)
            continue;
        if(p + 2 == q && a[p] < a[p+1] && a[p+1] < a[p+2])
        {
            mx = max(mx, (v[i].ss - v[i].ff + 1) + (v[i-1].ss - v[i-1].ff + 1));
        }
        else if(p + 1 == q)
        {
            if(a[p-1] < a[p+1] || a[p] < a[q+1])
                mx = max(mx, (v[i].ss - v[i].ff + 1) + (v[i-1].ss - v[i-1].ff + 1) - 1);
        }
    }

    cout << mx;
}
