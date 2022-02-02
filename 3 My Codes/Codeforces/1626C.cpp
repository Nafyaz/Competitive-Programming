#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll k[102];
ll h[102];

map<pair<ll, ll>, ll> dp;

ll call(ll i, ll health)
{
    if(health < h[i])
        return -1;

    if(i == n)
        return 0;

    if(dp.find({i, health}) != dp.end())
        return dp[{i, health}];

    ll newHealth = k[i+1]-k[i] + health;
    ll cost = call(i+1, newHealth);
    ll ret = LLONG_MAX;

    if(cost == -1)
        return dp[{i, health}] = -1;

    ret = min(ret, newHealth*(newHealth+1)/2 - health*(health+1)/2 + cost);

    if(h[i+1] > k[i+1]-k[i])
        return dp[{i, health}] = ret;

    ll l, r, mid;
    l = h[i+1];
    r = k[i+1] - k[i];

    while(l <= r)
    {
        mid = (l+r)/2;
        cost = call(i+1, mid);

        if(cost == -1)
            l = mid+1;
        else
        {
            r = mid-1;
            ret = min(ret, mid*(mid+1)/2 + cost);
        }
    }

    return dp[{i, health}] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> k[i];
        for(i = 1; i <= n; i++)
            cin >> h[i];

        dp.clear();
        cout << call(0, h[0]) << "\n";
    }
}
