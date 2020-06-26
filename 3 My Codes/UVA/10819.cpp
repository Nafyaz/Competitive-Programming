#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define N 100009

ll m, n, dp[109][10009];
vector<pair<ll, ll> > v;

ll func(ll i, ll w, ll flag)
{
    if(i == n || w > m)
        return 0;

    if(dp[i][w] != -1)
        return dp[i][w];
    if(w + v[i].ff > 2000 && w + v[i].ff <= m+200 && !flag)
    {
        m += 200;
        dp[i][w] = v[i].ss + func(i+1, w+v[i].ff, 1);
        m -= 200;
        dp[i][w] = max(dp[i][w], func(i+1, w, 0));
        return dp[i][w];
    }

    dp[i][w] = max(func(i+1, w, 0), v[i].ss+func(i+1, w+v[i].ff, 0));
    return dp[i][w];
}

int main()
{
    ll i, a, b;
    while(cin >> m >> n)
    {
        v.clear();
        memset(dp, -1, sizeof(dp));
        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        cout << func(0, 0, 0) << endl;
    }
}
