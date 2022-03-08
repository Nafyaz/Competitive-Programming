#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, l, x, y, a, i;

    cin >> n >> l >> x >> y;

    map<ll, bool> mp;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        mp[a] = 1;
    }

    bool need[2] = {1, 1};
    for(auto u : mp)
    {
        if(mp.find(u.ff+x) != mp.end())
            need[0] = 0;
        if(mp.find(u.ff+y) != mp.end())
            need[1] = 0;
    }

    if(!need[0] && !need[1])
    {
        cout << 0;
        return 0;
    }

    if(need[0] ^ need[1])
    {
        if(need[0])
            cout << "1 " << x;
        else
            cout << "1 " << y;
        return 0;
    }

    for(auto u : mp)
    {
        if(mp.find(u.ff+x+y) != mp.end())
        {
            cout << "1 " << u.ff+x;
            return 0;
        }
        if(mp.find(u.ff+y-x) != mp.end() && u.ff+y <= l)
        {
            cout << "1 " << u.ff+y;
            return 0;
        }
        if(mp.find(u.ff-x+y) != mp.end() && u.ff-x >= 0)
        {
            cout << "1 " << u.ff-x;
            return 0;
        }
    }

    cout << "2 " << x << " " << y;
}
