#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000009
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

    ll n, i, c;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        for(i = 0; primes[i] * primes[i] <= n; i++)
        {
            for(c = 0; n%primes[i] == 0; c++)
                n /= primes[i];

            if(c > 0)
                cout << primes[i] << "^" << c << " ";
        }

        if(n > 1)
            cout << n << "^1\n";
    }
}
