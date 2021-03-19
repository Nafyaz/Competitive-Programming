#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll egcd(ll a, ll m, ll& x, ll& y)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = egcd(m, a%m, x1, y1);

    x = y1;
    y = x1 - y1*(a/m);

    return d;
}

ll invmod(ll a, ll m)
{
    ll x, y;
    egcd(a, m, x, y);

    return (x%m + m) % m;
}

int main()
{
    ll t, n, p, i, a;
    cin >> t;
    while(t--)
    {
        cin >> n >> p;

        if(n >= p)
        {
            cout << 0 << "\n";
            continue;
        }

        a = 1;
        for(i = n+1; i < p; i++)
            a = (a*i) % p;

        cout << (p - invmod(a, p))%p << "\n";
    }
}

