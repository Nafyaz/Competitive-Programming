#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll aSum[1000006];
bool flag[1003];
vector<ll> primes;

void sieve()
{
    ll i, j;

    flag[2] = 1;
    for(i = 3; i < 1003; i += 2)
        flag[i] = 1;

    for(i = 3; i*i < 1003; i += 2)
    {
        if(flag[i])
        {
            for(j = i*i; j < 1003; j += i)
                flag[j] = 0;
        }
    }

    primes.push_back(2);
    for(i = 3; i < 1003; i += 2)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

ll SOD(ll n)
{
    ll ret = 1;

    for(ll i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++)
    {
        ll p = 1;
        for(ll c = 0; n%primes[i] == 0; c++)
        {
            n /= primes[i];
            p *= primes[i];
        }
        ret *= (p * primes[i] - 1) / (primes[i] - 1);
    }

    if(n > 1)
        ret *= (n*n - 1) / (n - 1);

    return ret;
}

int main()
{
    ll T, n, i, x;

    sieve();
    memset(aSum, -1, sizeof aSum);

    cin >> T;

    while(T--)
    {
        cin >> n;

        if(aSum[n] == -1)
            aSum[n] = SOD(n) - n;

        if(aSum[n] > n)
            cout << "abundant\n";
        else if(aSum[n] < n)
            cout << "deficient\n";
        else
            cout << "perfect\n";
    }
}
