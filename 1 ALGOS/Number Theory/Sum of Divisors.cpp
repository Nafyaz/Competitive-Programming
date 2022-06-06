#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

bool flag[N];
int leastFactor[N];
vector<ll> primes;
ll sod[N];

void linSieve()
{
    int i, j;

    for(i = 2; i < N; i++)
    {
        if(leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);

        }
        for(j = 0; j < (int)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < N; j++)
            leastFactor[i*primes[j]] = primes[j];
    }
}


void sieve()
{
    ll i, j;

    flag[0] = flag[1] = 1;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < N; i+=2)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

ll linSOD(ll n)
{
    ll lf, c, p, ret = 1;

    while(n > 1)
    {
        lf = leastFactor[n];
        p = 1;

        for(c = 0; n%lf == 0; c++)
        {
            n /= lf;
            p *= lf;
        }

        ret *= (p*lf - 1)/(lf - 1);
    }

    return ret;
}

ll SOD(ll n)
{
    ll i, c, ret = 1;

    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        ll p = 1;
        for(c = 0; n % primes[i] == 0; c++)
        {
            n /= primes[i];
            p = p * primes[i];
        }
        ret *= (p * primes[i] - 1) / (primes[i] - 1);
    }

    if(n > 1)
        ret *= (n*n - 1) / (n - 1);
    return ret;
}

void allSOD()
{
    ll i, j;

    for(i = 1; i < N; i++)
    {
        for(j = i; j < N; j += i)
            sod[j] += i;
    }
}