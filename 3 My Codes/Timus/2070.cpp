#include<bits/stdc++.h>
using namespace std;
#define N 1000009
#define ll long long

bool flag[N];
vector<ll> primes;

void sieve()
{
    ll i, j;
    for(i = 3; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i*i < N; i += 2)
    {
        if(flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 0;
        }
    }

    primes.push_back(2);
    for(i = 3; i < N; i += 2)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

ll NOD_of_square(ll n)
{
    ll i, ret = 1, p;

    for(i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++)
    {
        for(p = 0; n%primes[i] == 0; p++)
            n /= primes[i];

        ret *= (2*p+1);
    }

    if(n > 1)
        ret = ret*3;

    return ret;
}

int main()
{
    sieve();

    ll l, r, i, ans, notans;
    vector<ll> v;

    for(i = 0; i < N; i++)
    {
        if(flag[NOD_of_square(i)])
            v.push_back(i*i);
    }

    cin >> l >> r;

    ans = r-l+1;
    notans = lower_bound(v.begin(), v.end(), r+1) - lower_bound(v.begin(), v.end(), l);

    cout << ans - notans;
}
