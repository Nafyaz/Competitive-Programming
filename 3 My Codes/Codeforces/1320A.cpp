#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, b, ans = 0;
    map<ll, ll> mp;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> b;
        mp[b-i] += b;
        ans = max(ans, mp[b-i]);
    }

    cout << ans;
}
