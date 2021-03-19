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

int main()
{
    sieve();

    ll l, r, i, x, p, cnt;

    cin >> l >> r;

    ll ans = r-l+1;

    for(i = 0; i < primes.size(); i++)
    {
        p = primes[i];
        for(x = p, cnt = 1; x <= r; x *= p, cnt++)
        {
            if(flag[cnt+1] && x >= l)
                ans--;
        }
    }

    cout << ans;
}
