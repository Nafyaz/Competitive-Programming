#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000009
bool flag[N];
vector<ll> primes;
ll phi[N], val[N];

void linsieve()
{
    ll i, j;
    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
        for(j = 0; j < primes.size() && i * primes[j] < N; j++)
        {
            flag[i * primes[j]] = 1;
            if(i % primes[j] == 0)
                break;
        }
    }
}

void segsivephi(ll a, ll b)
{
    ll i, j, cnt;

    for(i = a; i <= b; i++)
    {
        phi[i-a] = i;
        val[i-a] = i;
    }

    for(auto p : primes)
    {
        if(p * p > b)
            break;

        for(i = (a + p - 1) / p * p; i <= b; i += p)
        {
            for(cnt = 0; val[i - a] % p == 0; cnt++)
                val[i - a] /= p;

            if(cnt)
                phi[i - a] = phi[i - a] / p * (p - 1);
        }
    }

    for(i = a; i <= b; i++)
    {
        if(val[i - a] > 1)
            phi[i - a] = phi[i - a] / val[i - a] * (val[i - a] - 1);
    }
}

int main()
{
    linsieve();

    ll a, b, i;

    cin >> a >> b;
    segsivephi(a, b);

    for(i = a; i <= b; i++)
        cout << phi[i - a] << endl;
}
