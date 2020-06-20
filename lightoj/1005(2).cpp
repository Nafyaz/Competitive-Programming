#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[31][901];

ll call(ll n, ll k)
{
    if(k == 0 || n == 0)
        return 0;
    if(dp[n][k] != -1)
        return dp[n][k];

    for(ll i = )
}

int main()
{
    ll t, caseno = 0, n, k, i;
    cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof dp);
        cin >> n >> k;
        cout << "Case " << ++caseno << ": " << call(n, k) << endl;
    }
}
