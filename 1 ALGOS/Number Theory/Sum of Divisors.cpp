#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

bool flag[N];
vector<ll> primes;

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

ll SOD(ll n)
{
    ll i, c, ret = 1;

    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        int p = 1;
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

int main()
{
    sieve();
    cout << SOD(81);
}


