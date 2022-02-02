#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

vector<ll> desire[1000006];
ll cnt[1000006];

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;

    ll ret = bigmod(a, p/2);
    ret = (ret * ret) % mod;

    if(p&1)
        ret = (ret * a) % mod;

    return ret;
}

ll invmod(ll a)
{
    return bigmod(a, mod-2);
}

int main()
{
    ll n, a, i, j, k, p, sum1, q, sum2;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> k;

        for(j = 0; j < k; j++)
        {
            cin >> a;
            desire[i].push_back(a);
            cnt[a]++;
        }
    }

    p = invmod(n);
    sum1 = 0;
    for(i = 0; i < n; i++)
    {
        q = invmod(desire[i].size());
        sum2 = 0;
        for(j = 0; j < desire[i].size(); j++)
            sum2 = (sum2 + cnt[desire[i][j]]*p) % mod;

        sum1 = (sum1 + q*sum2) % mod;
    }

    cout << (p*sum1)%mod;
}
