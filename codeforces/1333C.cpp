#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, j, a, sum = 0, ans;
    cin >> n;

    map<ll, ll> mp;

    mp[0] = 0;
    ans = 0;
    j = 1;
    for(i = 1; i <= n; i++)
    {
        cin >> a;
        sum += a;
        if(mp.find(sum) != mp.end())
        {
            j = max(j, mp[sum] + 2);
        }

        ans += i-j+1;
        mp[sum] = i;
    }

    cout << ans;
}
