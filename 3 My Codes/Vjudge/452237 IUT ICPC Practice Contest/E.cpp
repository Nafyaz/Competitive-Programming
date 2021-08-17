#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

ll n, k;
vector<ll> v[200009];

ll bigmod(ll b, ll p)
{
    if(p == 1)
        return b%mod;

    ll x = bigmod(b, p>>1);

    x = (x*x)%mod;

    if(p&1)
        x = (x*b)%mod;

    return x;
}

int main()
{
    ll i, x, len, color, ans = 0, cnt;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
        v[i].push_back(0);

    for(i = 1; i <= n; i++)
    {
        cin >> x;
        v[x].push_back(i);
    }

    for(i = 1; i <= n; i++)
        v[i].push_back(n+1);

    for(color = 1; color <= n; color++)
    {
        for(len = 1; len <= v[color].size() - 2; len++)
        {
            cnt = 0;
            for(i = 1; i + len < v[color].size(); i++)
            {
                cnt += ((v[color][i] - v[color][i-1]) * (v[color][i+len] - v[color][i+len-1])) % mod;
//                cout << color << " " << len << " " << i << " " << cnt << "\n";
            }
            ans = (ans + (cnt*bigmod(len, k)) % mod) % mod;
        }
    }

    cout << ans;
}
