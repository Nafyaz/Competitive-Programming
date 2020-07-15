#include<bits/stdc++.h>
using namespace std;
#define N 1000009
bool is_prime[N];
vector<int> primes;

int lcnt[N];

void sieve()
{
    int i, j;
    for(i = 4; i < N; i += 2)
        is_prime[i] = 1;
    for(i = 3; i * i < N; i += 2)
    {
        if(!is_prime[i])
        {
            for(j = i * i; j < N; j += 2 * i)
                is_prime[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!is_prime[i])
            primes.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int n, k, i, j, c, flag = 1;
    cin >> n >> k;
    while(n--)
    {
        cin >> c;
        for(i = 0; primes[i] * primes[i] <= c && is_prime[c]; i++)
        {
            for(j = 0; c % primes[i] == 0; j++)
                c /= primes[i];

            lcnt[primes[i]] = max(lcnt[primes[i]], j);
        }

        if(c > 1)
            lcnt[c] = max(lcnt[c], 1);
    }

    for(i = 0; primes[i] * primes[i] <= k && flag; i++)
    {
        for(j = 0; k % primes[i] == 0; j++)
            k /= primes[i];
        if(j > lcnt[primes[i]])
            flag = 0;
    }

    if(k > 1 && lcnt[k] == 0)
        flag = 0;

    cout << (flag? "Yes" : "No");
}
