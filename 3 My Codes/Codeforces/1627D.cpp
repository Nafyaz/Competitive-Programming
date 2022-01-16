#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

#define N 1000006

int a[1000006];

bool flag[N];
vector<ll> primes;
vector<ll> primeCnt[1000006];

void sieve()
{
    ll i, j;

    flag[2] = 1;
    for(i = 3; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < N; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

void factorize(ll idx)
{
    ll i, cnt, x = a[idx];

    for(i = 0; primes[i]*primes[i] <= x; i++)
    {
        if(x%primes[i] == 0)
        {
            for(cnt = 0; x%primes[i] == 0; cnt++)
                x /= primes[i];

            primeCnt[i].push_back({cnt, idx});
        }
    }

    if()
}

int main()
{
    sieve();

    ll n, i;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        factorize(i);
    }
}
