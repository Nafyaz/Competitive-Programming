#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll mulmod(ll a, ll b)
{
    ll ret = 0;
    while(b)
    {
        if(b&1)
            ret = (ret + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ret;
}

ll bigmod(ll a, ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b&1)
            ret = mulmod(ret, a);
        a = mulmod(a, a);
        b >>= 1;
    }

    return ret;
}

ll fact(ll n)
{
    ll ret = 1;
    while(n)
    {
        ret = mulmod(ret, n);
        n--;
    }
    return ret;
}

int main()
{
    ll n, m, i, ans, on[1009];
    cin >> n >> m;
    for(i = 0; i < m; i++)
        cin >> on[i];
    sort(on, on + m);

    ans = 1;
    for(i = 1; i < m; i++)
    {
        if(on[i] - on[i-1] >= 2)
            ans = mulmod(ans, bigmod(2, on[i] - on[i-1] - 2));
    }

    ans = mulmod(ans, fact(n - m));

    ans = mulmod(ans, bigmod(fact(on[0] - 1), mod - 2));
    for(i = 1; i < m; i++)
        ans = mulmod(ans, bigmod(fact(on[i] - on[i-1] - 1), mod - 2));
    ans = mulmod(ans, bigmod(fact(n - on[m-1]), mod - 2));

    cout << ans;
}
