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
    ll t, n, m, z, o, ans, part;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        z = n-m;
        o = m;
        part = o+1;

        if(z <= part)
        {
            ans = n*(n+1)/2 - z;
            cout << ans << endl;
            continue;
        }


        ans = (part - z%part)*(z/part)*(z/part + 1)/2 + (z%part)*((z+part-1)/part) * ((z+part-1)/part + 1)/2;
        ans = n*(n+1)/2 - ans;

        cout << ans << endl;
    }
}
