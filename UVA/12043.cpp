#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100009
bool flag[N];
vector<ll> primes;
ll NOD[N], SOD[N];

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

ll NODcall(ll n)
{
    if(NOD[n] != -1)
        return NOD[n];
    ll i, c, ret = 1, temp = n;
    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        for(c = 0; n%primes[i] == 0; c++)
            n /= primes[i];
        ret *= (c + 1);
    }

    if(n > 1)
        ret = ret << 1;
    return NOD[temp] = ret;
}

ll SODcall(ll n)
{
    if(SOD[n] != -1)
        return SOD[n];
    ll i, c, p, ret = 1, temp = n;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        p = 1;
        for(c = 0; n%primes[i] == 0; c++)
        {
            n /= primes[i];
            p *= primes[i];
        }

        ret *= (p * primes[i] - 1) / (primes[i] - 1);
    }

    if(n > 1)
        ret *= (n * n - 1) / (n - 1);

    return SOD[temp] = ret;
}

int main()
{
    ll t, a, b, k, i, n, s;

    sieve();
    memset(NOD, -1, sizeof NOD);
    memset(SOD, -1, sizeof SOD);

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        n = s = 0;
        for(i = (a + k - 1) / k * k; i <= b; i += k)
        {
            n += NODcall(i);
            s += SODcall(i);
        }

        cout << n << " " << s << endl;
    }
}
