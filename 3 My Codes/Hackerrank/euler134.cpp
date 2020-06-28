#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

bool flag[N];
vector<ll> primes;

void linsieve()
{
    ll i, j;
    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
        for(j = 0; j < (ll)primes.size() && i * primes[j] < N; j++)
        {
            flag[i * primes[j]] = 1;
            if(i % primes[j] == 0)
                break;
        }
    }
}

void segsieve(ll L, ll R)
{
    memset(flag, 0, sizeof flag);
    ll i, j;
    for(i = 0; primes[i] * primes[i] < R + 200; i++)
    {
        for(j = max((L + primes[i] -1)/primes[i], 2LL); primes[i] * j < R + 200; j++)
            flag[primes[i] * j - L] = 1;
    }
}

ll mulmod(ll a, ll b, ll mod)
{
    if(a < b)
        swap(a, b);
    ll ret = 0;
    while(b)
    {
        if(b&1)
            ret = (ret + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ret;
}

ll bigmod(ll a, ll b, ll mod)
{
    ll ret = 1;
    while(b)
    {
        if(b&1)
            ret = mulmod(ret, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }

    return ret;
}

ll func(ll p1, ll p2)
{
    ll i, k = log10(p1) + 1;
    ll m = bigmod(10, k, 100000000000LL);
    ll inv = bigmod(m, p2 - 2, p2);
    ll x = (-mulmod(p1, inv, p2) + p2) % p2;

//    cout << mulmod(-p1, inv, p2) << endl;
//    cout << p1 << " " << p2 << " " << k << " " << m << " " << inv << " " << x << " " << x * m + p1 << endl;
    return x * m + p1;
}

int main()
{
    linsieve();
    ll t, l, r, i;

    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        segsieve(l, r);

//        for(i = 0; i < 20; i++)
//            cout << i + l << " " << flag[i] << endl;

        ll p1 = -1, p2, ans = 0;

        for(i = l; i < r + 200; i++)
        {
            if(!flag[i - l])
            {
//                cout << i << endl;
                if(p1 == -1)
                {
                    p1 = i;
                    continue;
                }
                else if(p1 > r)
                    break;

                p2 = i;
                ans += func(p1, p2);
                p1 = i;
            }
        }

        cout << ans << endl;
    }
}
