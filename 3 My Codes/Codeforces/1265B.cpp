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
    int n, i, t, x, pos[200009], mn, mx, sz;
    cin >> t;

    while(t--)
    {
        mn = INT_MAX;
        mx = INT_MIN;
        sz = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            pos[x] = i;
        }

        for(i = 1; i <= n; i++)
        {
            mn = min(mn, pos[i]);
            mx = max(mx, pos[i]);
            sz++;

            if(sz == mx - mn + 1)
                cout << '1';
            else
                cout << '0';
        }
        cout << endl;

    }
}
