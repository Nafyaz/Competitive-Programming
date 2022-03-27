#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

ll F[1003];

ll fact(ll n)
{
    if(n <= 1)
        return F[n] = 1;
    if(F[n])
        return F[n];

    return F[n] = (fact(n-1)*n)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n&1)
        {
            cout << "0\n";
            continue;
        }

        cout << (fact(n/2)*fact(n/2))%mod << "\n";
    }
}
