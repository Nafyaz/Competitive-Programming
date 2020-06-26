#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll factmod(ll n, ll p)
{
    ll power = 0;
    while(n)
    {
        power += n/p;
        n /= p;
    }
    return power;
}

ll mulmod(ll a, ll b, ll m)
{
    if(b == 0)
        return 0;
    if(b == 1)
        return a%m;

    ll x = mulmod(a, b/2, m), y = 0;
    if(b%2 == 1)
        y = a%m;
    return ((x+x)%m + y)%m;
}

long long bigmod(long long a, long long b, long long m)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a%m;

    long long x = bigmod(a, b/2, m), y = 1;
    if(b%2 == 1)
        y = a%m;

    return (mulmod(x, x, m) * y)%m;
}

int main()
{
    ll x, n;
    cin >> x >> n;

    vector <ll> primes;

    for(ll i = 2; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            primes.push_back(i);
            while(x%i == 0)
                x /= i;
        }
    }

    if(x > 1)
        primes.push_back(x);

    ll ans = 1, power;
    for(ll i = 0; i < primes.size(); i++)
    {
        power = factmod(n, primes[i]);
        ans = (ans   *   bigmod(primes[i], power, 1000000007)   ) % 1000000007;
    }

    cout << ans;
}
