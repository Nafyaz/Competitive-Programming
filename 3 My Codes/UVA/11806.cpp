#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000007

ll dp[500][500];

ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;

    if(dp[n][r] != 0)
        return dp[n][r];

    if(!r)
        return dp[n][r] = 1;

    return dp[n][r] = (nCr(n-1, r-1) + nCr(n-1, r))%mod;
}

int main()
{
    ll t, caseno = 0, m, n, k, ans;

    cin >> t;

    while(t--)
    {
        cin >>  m >> n >> k;

        cout << "Case " << ++caseno << ": ";

//        if(k < 2 || k > m*n)
//            cout << 0 << "\n";

        ll all = nCr(m*n, k);
        ll oneside = (2*nCr((m-1)*n, k) + 2*(nCr(m*(n-1), k)))%mod;
        ll twoside = (4*nCr((m-1)*(n-1), k) + nCr((m-2)*n, k) + nCr(m*(n-2), k))%mod;
        ll threeside = (2*nCr((m-2)*(n-1), k) + 2*nCr((m-1)*(n-2), k));
        ll fourside = nCr((m-2)*(n-2), k);

        ans = ((all - oneside + twoside - threeside + fourside)% mod + mod)%mod;

        cout << ans << "\n";
    }
}
