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
