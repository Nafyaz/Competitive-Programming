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

ll n, a[300009], ans[64], mod = 1000000007;
ll freq[64];

void func(ll x)
{
    for(ll i = 0; x; i++)
    {
        freq[i] += (x&1);
        x = x >> 1;
    }
}

ll po(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = 1;
    if(b&1)
        x = a%mod;
    ll y = po(a, b/2);
    return (((y*y)%mod)*x)%mod;
}

int main()
{
    ll i, j;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        func(a[i]);
    }

//    for(auto u : freq)
//        cout << u.ff << " " << u.ss << endl;

    for(i = 0; i <= 62; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[j] & (1LL << i))
            {
                ans[i] += (n-j) - freq[i];
                freq[i]--;
            }
            else
                ans[i] += freq[i];
        }
    }

    ll x = 0;
    for(i = 0; i <= 62; i++)
        x = (x + (ans[i]%mod)*po(2LL, i))%mod;
    cout << x;
}
