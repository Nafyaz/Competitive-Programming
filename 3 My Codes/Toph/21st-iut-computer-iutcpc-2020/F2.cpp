/*
Check and remove this section while coding
1. Get rid of toolbars except compiler and main. Enable only logs and status.
2. Use C++17 in global compiler settings.
3. Turn on Wall, Wextra, Wshadow in warnings.
4. Make tab spout 4 spaces
*/

/*
ID: nafis.f1
TASK:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

ll bigmod(ll a, ll b, ll mod)
{
    ll res = 1%mod;
    while (b)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

ll invmod(ll a, ll m)  //only if m is prime and gcd(a, m) = 1
{
    return bigmod(a, m-2, m);
}

ll call(ll a, ll n, ll mod)
{
    if(n == 1)
        return 1;
    ll ret1 = call(a, n/2, mod);
    ll ret2 = (bigmod(a, n/2, mod) * ret1)%mod;

    if(n%2 == 0)
        return (ret1 + ret2)%mod;
    else
        return ((ret1 + ret2)%mod + bigmod(a, n-1, mod))%mod;
}

int main()
{
    ll t, a, b, n, m, mod;
    ll an, ans, temp;
    cin >> t;

    while(t--)
    {
        cin >> a >> b >> n >> m >> mod;
        an = bigmod(a, n, mod);
        ans = (m*(m+1)/2)%mod;
        ans = (an*ans)%mod;

        if(n > 1 && a > 1)
        {
            temp = call(a%mod, n%mod, mod);
            temp = (temp*b)%mod;
            temp = (temp*m)%mod;
        }
         else if(n > 1)
        {
            temp = (m*b)%mod;
            temp = (temp*n)%mod;
        }
        else
            temp = (m*b)%mod;

        cout << (ans + temp)%mod << "\n";
    }
}

