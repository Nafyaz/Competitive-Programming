#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n;
string s;
ll a[26];

void solve()
{
    ll i, l, r, cnt[26] = {0};
    ll dp1[1003] = {0}, dp2[1003] = {0}, mx = 0;
    l = 0;
    r = -1;

    dp1[0] = 1;

    while(r+1 < n)
    {
        r++;

        cnt[s[r] - 'a']++;

        for(i = 0; i < 26; i++)
        {
            while(l <= r && cnt[i] && r-l+1 > a[i])
            {
                cnt[s[l] - 'a']--;
                l++;
            }
        }

        mx = max(mx, r-l+1);

        dp2[r+1] = INT_MAX;
        for(i = r; i >= l; i--)
        {
            dp1[r+1] = (dp1[r+1] + dp1[i]) % mod;
            dp2[r+1] = min(dp2[r+1], dp2[i]+1);
        }
    }

    cout << dp1[n] << "\n" << mx << "\n" << dp2[n];
}

int main()
{
    ll i;

    cin >> n >> s;

    for(i = 0; i < 26; i++)
        cin >> a[i];

    solve();
}
