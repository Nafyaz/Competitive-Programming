#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[5003];
ll pref[5003];
ll mxSum[5003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, x, i, j, k, len, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
            mxSum[i] = INT_MIN;
        }

        for(len = 1; len <= n; len++)
        {
            for(i = 1; i+len-1 <= n; i++)
            {
                j = i+len-1;

                if(pref[j] - pref[i-1] > mxSum[len])
                    mxSum[len] = pref[j] - pref[i-1];
            }
        }

        for(k = 0; k <= n; k++)
        {
            ans = 0;
            for(len = 0; len <= n; len++)
                ans = max(ans, mxSum[len] + x*min(k, len));

            cout << ans << " ";
        }
        cout << "\n";
    }
}
