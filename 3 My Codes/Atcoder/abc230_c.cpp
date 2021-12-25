#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a, b;

bool func(ll i, ll j)
{
    i -= a;
    j -= b;

    if(i == j)
    {
        ll k = i;
        if(max(1-a, 1-b) <= k && k <= min(n-a, n-b))
            return 1;
    }
    else if(i == -j)
    {
        ll k = i;
        if(max(1-a, b-n) <= k && k <= min(n-a, b-1))
            return 1;
    }

    return 0;
}

int main()
{
    ll p, q, r, s, i, j;

    cin >> n >> a >> b;
    cin >> p >> q >> r >> s;

    for(i = p; i <= q; i++)
    {
        for(j = r; j <= s; j++)
        {
            if(func(i, j))
                cout << '#';
            else
                cout << '.';
        }
        cout << "\n";
    }
}
