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
    ll a, b, g;
    cin >> a >> b;
    g = __gcd(a, b);

    ll i, ans = 1;

    for(i = 2; i <= sqrt(g); i++)
    {
        if((g%i) == 0)
        {
            while(g%i == 0)
                g /= i;
            ans++;
        }
    }

    if(g > 1)
        ans++;
    cout << ans;
}
