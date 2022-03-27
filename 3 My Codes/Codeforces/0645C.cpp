#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
string s;
ll pref[100005];

bool isPossible(ll dist)
{
    ll i, st, ed;

    for(i = 1; i <= n; i++)
    {
        if(s[i-1] == '1')
            continue;

        st = max(1LL, i-dist);
        ed = min(n, i+dist);

        if(pref[ed] - pref[st-1] >= k+1)
            return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, low, high, mid, ans;

    cin >> n >> k >> s;

    for(i = 1; i <= n; i++)
        pref[i] = pref[i-1] + (s[i-1] == '0');

    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high)/2;

        if(isPossible(mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }

    cout << ans;
}
