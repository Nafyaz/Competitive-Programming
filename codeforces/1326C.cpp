#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

int main()
{
    ll n, k, p, prev, i, j, flag = 0;
    cin >> n >> k;
    cout << n*(n+1)/2 - (n-k)*(n-k+1)/2 << " ";
    ll ans = 1;
    for(i = 0; i < n; i++)
    {
        cin >> p;
        if(p > n-k)
        {
            if(flag)
                ans = ans*(i-prev)%mod;
            prev = i;
            flag = 1;
        }
    }

    cout << ans;
}
