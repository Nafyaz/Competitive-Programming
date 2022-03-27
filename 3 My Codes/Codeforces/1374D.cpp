#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, i, a, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        map<ll, ll> freq;

        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(a%k == 0)
                continue;

            a = (a+k-1)/k*k - a;
            freq[a]++;
        }

        ans = 0;
        for(auto u : freq)
            ans = max(ans, k*(u.ss-1) + u.ff + 1);
        cout << ans << "\n";
    }
}
