#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll bigmod(ll a, ll p)
{
    ll ret = 1;
    while(p)
    {
        if(p&1)
            ret = (ret*a)%mod;
        a = (a*a)%mod;
        p >>= 1;
    }
    return ret;
}

int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
            cout << 4 << endl;
        else
            cout << (4 + bigmod(29, n-1))%mod << endl;
    }
}
