#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009
bool flag[N];
vector<ll> primes;
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

int main()
{
    sieve();
    ll t, caseno = 0, i, j, n, m, p;
    cin >> t;
    while(t--)
    {
        cin >> n;
        m = 1;
        for(i = 0; i < n; i++)
        {
            cin >> p;
            m *= p;
        }

        m++;

        for(i = 0; primes[i] * primes[i] <= m; i++)
        {
            while(m % primes[i] == 0)
            {
                m /= primes[i];
                p = primes[i];
            }
        }

        if(m > 1)
            cout << "Case #" << ++caseno << ": " << m << endl;
        else
            cout << "Case #" << ++caseno << ": " << p << endl;
    }
}

