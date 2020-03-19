#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

bool flag[N];
vector<ll> primes;

void sieve()
{
    ll i, j, val = sqrt(N) + 1;

    flag[0] = flag[1] = 1;

    for(i = 4; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i < val; i += 2)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

ll NOD(ll n)
{
    ll i, c, sum = 1;

    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        for(c = 0; n % primes[i] == 0; c++)
            n /= primes[i];
        sum *= (c+1);
    }

    if(n > 1)
        sum = sum << 1;
    return sum;
}

