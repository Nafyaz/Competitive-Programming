#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

map<ll, ll> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, i, x, flag;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        mp[x] = 1;
    }

    vector<ll> ans;
    flag = 1;

    for(ll len = 1; len <= 2000000009 && flag; len *= 2)
    {
        for(auto u : mp)
        {
            if(mp.find(u.ff + len) != mp.end() && mp.find(u.ff + 2*len) != mp.end())
            {
                ans.clear();
                ans.push_back(u.ff);
                ans.push_back(u.ff + len);
                ans.push_back(u.ff + 2*len);

                flag = 0;
                break;
            }

            if(mp.find(u.ff + len) != mp.end())
            {
                ans.clear();
                ans.push_back(u.ff);
                ans.push_back(u.ff + len);
            }
        }
    }

    if(ans.empty())
        ans.push_back((*mp.begin()).ff);

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u << " ";
}
