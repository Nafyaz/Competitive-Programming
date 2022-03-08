//Follow Starscream-11813
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, l, r, ans;
    pair<ll, ll> p[102];
    ll k[102], h[102];

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> k[i];
        for(i = 0; i < n; i++)
            cin >> h[i];

        for(i = 0; i < n; i++)
        {
            l = k[i] - h[i] + 1;
            r = k[i];

            p[i] = {l, r};
        }

        sort(p, p+n);

//        for(i = 0; i < n; i++)
//            cout << p[i].ff << " " << p[i].ss << "\n";

        ans = 0;
        for(i = 0; i < n; i++)
        {
            l = p[i].ff;
            r = p[i].ss;

            while(i+1 < n && r >= p[i+1].ff)
            {
                r = max(r, p[i+1].ss);
                i++;
            }

            ans += (r-l+1)*(r-l+2)/2;
        }

        cout << ans << "\n";
    }
}
