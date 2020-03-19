#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool flag[3000];
vector<ll> prime;

void sieve()
{
    flag[0] = flag[1] = 1;

    for(int i = 4; i < 3000; i += 2)
        flag[i] = 1;
    for(int i = 3; i <= sqrt(3000) + 1; i += 2)
    {
        if(!flag[i])
        {
            for(int j = i*i; j < 3000; j += 2*i)
                flag[j] = 1;
        }
    }

    for(int i = 2; i < 3000; i++)
    {
        if(!flag[i])
            prime.push_back(i);
    }
}

ll large_prime(ll b)
{
    if(!flag[b])
        return b;
    ll p, mx = 0, mxp;
    for(int i = prime.size() - 1; i >= 0; i--)
    {
        if(b%prime[i] == 0)
        {
            p = 1;
            while(b%prime[i] == 0)
            {

                p *= prime[i];
                b /= prime[i];
            }
            if(mx < p)
            {
                mx = p;
                mxp = prime[i];
            }
        }
    }

    return mxp;
}

ll tz(ll n, ll b)
{
    ll ret = 0;
    ll p = large_prime(b), x = 0;
    while(n)
    {
        ret += n/p;
        n /= p;
    }

    while(b%p == 0)
    {
        x++;
        b /= p;
    }

    return ret/x;
}

int main()
{
    sieve();
    ll t, caseno = 0, b, ans, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ans = 0;
//        cout << "b:" << endl;
        for(b = 2; b <= 2500; b++)
        {
            if(tz(n, b) == k)
            {
                ans++;
//                cout << b << endl;
            }
        }

        cout << ans << endl;
    }
}
