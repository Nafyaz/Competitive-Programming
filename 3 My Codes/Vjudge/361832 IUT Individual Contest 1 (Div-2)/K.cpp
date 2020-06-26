#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%m;
    ll x = 1, y;
    if(p&1)
        x = a%m;
    y = bigmod(a, p/2, m);

    return (((y*y)%m) * x)%m;
}

int main()
{
    ll t, a, b, c, p;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        p = bigmod(b, c, mod-1);
        cout << bigmod(a, p, mod) << endl;
    }
}
