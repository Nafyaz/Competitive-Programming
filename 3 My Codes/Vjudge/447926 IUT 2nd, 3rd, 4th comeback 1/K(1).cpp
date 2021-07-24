#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, k;
ll c[20];
map<pair<ll, ll>, ll> mp;

ll func(ll i, ll sum)
{
    if(sum == k)
        return 1;
    if(i >= n || sum > k)
        return -1;

    if(mp.find({i, sum}) != mp.end())
        return mp[{i, sum}];

    if(func(i+1, sum) == 1)
        return 1;
    if(func(i+1, sum+c[i]) == 1)
        return 1;
    if(func(i+1, sum+2*c[i]) == 1)
        return 1;

    return mp[{i, sum}] = -1;
}

int main()
{
    ll t, caseno = 0, i;

    cin >> t;

    while(t--)
    {
        mp.clear();
        cin >> n >> k;

        for(i = 0; i < n; i++)
            cin >> c[i];

        cout << "Case " << ++caseno << ": ";

        if(func(0, 0) == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
