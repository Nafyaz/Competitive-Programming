#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, m;

ll mulmod(ll a, ll b, ll m)
{
    if(b == 0)
        return 0;
    if(b == 1)
        return a%m;

    ll p = mulmod(a, b/2, m), q = 0;

    if(b&1)
        q = a%m;

    return ((p+p)%m + q)%m;
}
ll bigmod(ll k, ll n, ll m)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return k%m;

    ll p = bigmod(k, n/2, m), q = 1;

    if(n&1)
        q = k%m;

    return mulmod(mulmod(p, p, m), q, m);
}

int main()
{
    ll T, x;
    cin >> T;
    while(T--)
    {
        cin >> n  >> k >> m;

        cout << bigmod(k, n, m) << endl;
    }
}
/*
 123456789012345678
 500000000000000000
 999999999999999999
1000000000000000000
*/
