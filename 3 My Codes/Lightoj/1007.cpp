#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define N 5000009
bool flag[N];
vector<ll> primes;
ll phi[N];

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

void allphi()
{
    ll i, j;
    for(i = 1; i < N; i++)
        phi[i] = i;

    for(auto p : primes)
    {
        for(i = 1; p*i < N; i++)
            phi[p*i] = phi[p*i] / p * (p-1);
    }
}

int main()
{
    sieve();
    allphi();

    ll t, caseno = 0, i, x, a, b;

    for(i = 1; i < N; i++)
        phi[i] = phi[i] * phi[i];
    for(i = 1; i < N; i++)
        phi[i] += phi[i-1];

    scanf("%llu", &t);
    while(t--)
    {
        scanf("%llu %llu", &a, &b);
        printf("Case %llu: %llu\n", ++caseno, phi[b] - phi[a-1]);
    }
}
