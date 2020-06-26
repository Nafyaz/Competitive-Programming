#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define N 100009

ll m, n, dp[109][10009];
vector<pair<ll, ll> > v;

ll func(ll i, ll w)
{
    if(i == n)
        return 0;
    if(w + v[i].ff > m)
        return 0;
    if(dp[i][w])
        return dp[i][w];

    dp[i][w] = max(func(i+1, w), v[i].ss+func(i+1, w+v[i].ff));
    return dp[i][w];
}

int main()
{
    ll i, a, b;
    while(cin >> m >> n)
    {
        v.clear();
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        cout << func(0, 0) << endl;
    }
}
