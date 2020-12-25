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

ll mod;

ll bigmod(ll a, ll b)
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

ll egcd(ll a, ll m, ll& x, ll& y)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = egcd(m, a%m, x1, y1);

    x = y1;
    y = x1 - y1*(a/m);

    return d;
}

ll invmod(ll a, ll m)  //when gcd(a, m) = 1
{
    ll x, y;
    egcd(a, m, x, y);

    return (x%m + m) % m;
}

int main()
{
    ll t, a, b, n, m, an, ans, temp;
    cin >> t;

    while(t--)
    {
        cin >> a >> b >> n >> m >> mod;
        an = bigmod(a, n);
        ans = (m*(m+1)/2)%mod;
        ans = (an*ans)%mod;

        if(n > 1 && a > 1)
        {
            temp = ((an - 1) * invmod(a-1, mod))%mod;
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
