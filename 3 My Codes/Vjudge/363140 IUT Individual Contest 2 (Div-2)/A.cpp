#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

bool flag[N];
vector<ll> primes;

void sieve()
{
    ll i, j;
    flag[0] = flag[1] = 1;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;
    for(i = 3; i*i < N; i += 2)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

int main()
{
//    freopen("out.txt", "w", stdout);
    ll t, caseno = 0, i, n, cnt, g, x;
    sieve();
    cin >> t;
    while(t--)
    {
        cin >> x;
        g = 0;
        for(i = 0; primes[i]*primes[i] <= abs(x); i++)
        {
            cnt = 0;
            while(x%primes[i] == 0)
            {
                x /= primes[i];
                cnt++;
            }

            g = __gcd(g, cnt);
        }

        if(x > 1 || x < -1)
            g = 1;
        if(x == -1)
        {
            while(g%2 == 0)
                g /= 2;
        }

        cout << "Case " << ++caseno << ": " << g << endl;
    }
}
