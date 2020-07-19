#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100009
bool flag[N];
vector<ll> primes;

void sieve()
{
    ll i, j;
    flag[0] = flag[1] = 1;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;
    for(i = 3; i * i < N; i += 2)
    {
        if(!flag[i])
        {
            for(j = i * i; j < N; j += 2 * i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

ll PHI(ll n)
{
    if(n == 1)
        return 0;

    ll i, cnt, ret = n;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        for(cnt = 0; n % primes[i] == 0; cnt++)
            n /= primes[i];

        if(cnt > 0)
            ret = ret / primes[i] * (primes[i] - 1);
    }

    if(n > 1)
        ret = ret / n * (n - 1);

    return ret;
}

int main()
{
    sieve();
    ll n;
    while(1)
    {
        cin >> n;
        if(!n)
            break;
        cout << PHI(n) << endl;
    }
}
