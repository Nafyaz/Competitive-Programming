#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

int main()
{
    ll a, n, k, i, j, cnt;
    cin >> n >> k;
    map<vector<pair<ll, ll>>, ll> mp;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        vector<pair<ll, ll>> v;
        for(j = 2; j*j <= a; j++)
        {
            cnt = 0;
            while(a%j == 0)
            {
                cnt++;
                a /= j;
            }
            if(cnt%k != 0)
                v.push_back({j, cnt%k});
        }
        if(a > 1 && k > 1)
            v.push_back({a, 1});
        mp[v]++;
    }

//    for(auto u : mp)
//    {
//        for(auto p : u.ff)
//            cout << "(" << p.ff << ", " << p.ss << "), ";
//        cout << ": " << u.ss << endl;
//    }
    ll ans = 0;
    for(auto u : mp)
    {
        vector<pair<ll, ll>> v;
        for(auto p : u.ff)
            v.push_back({p.ff, k-p.ss});

        if(u.ff == v)
            ans += mp[v]*(mp[v]-1)/2;
        else
            ans += u.ss * mp[v];
        mp[v] = 0;
    }

    cout << ans;
}
