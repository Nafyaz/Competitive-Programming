#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009
bool flag[N];
vector<ll> primes;
void sieve()
{
    ll i, j, val = sqrt(N) + 1;

    flag[2] = 1;
    for(i = 3; i <= N; i += 2)
        flag[i] = 1;

    for(i = 3; i < val; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j <= N; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i <= N; i++)
    {
        if(flag[i])
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

int main()
{
//    freopen("out.txt", "w", stdout);

    ll T, caseno = 0, i, j, val;
    ll n;
    sieve();
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld", &n);
        if(n == 1)
            printf("Case %lld: 0\n", ++caseno);
        else
            printf("Case %lld: %lld\n", ++caseno, NOD(n) - 1);
    }
}
