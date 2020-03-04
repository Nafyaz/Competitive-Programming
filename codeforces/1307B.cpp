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
    int t, i, n, x, a[100009], flag, mx;
    cin >> t;
    while(t--)
    {
        flag = mx = 0;
        cin >> n >> x;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] == x)
            {
                cout << 1 << endl;
                flag = 1;
            }
            mx = max(mx, a[i]);
        }

        if(!flag)
            cout << max(2, (x+mx-1)/mx) << endl;
    }
}

