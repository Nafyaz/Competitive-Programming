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
    int t, n, i, a[2009], o, e;
    cin >> t;
    while(t--)
    {
        o = e = 0;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]&1)
                o++;
            else
                e++;
        }
        if(o == n && n%2 == 0)
            cout << "NO" << endl;
        else if(e == n)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
