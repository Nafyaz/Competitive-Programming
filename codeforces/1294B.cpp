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
    int t, n, i, x, y, flag;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int, int> > v(n);
        s = "";
        for(i = 0; i < n; i++)
            cin >> v[i].ff >> v[i].ss;
        sort(v.begin(), v.end());

        flag = x = y = 0;
        for(i = 0; i < n; i++)
        {
            if(v[i].ff < x || v[i].ss < y)
            {
                flag = 1;
                break;
            }
            s = s + string (v[i].ff - x, 'R') + string (v[i].ss - y, 'U');
            x = v[i].ff;
            y = v[i].ss;
        }

        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl << s << endl;

    }
}
