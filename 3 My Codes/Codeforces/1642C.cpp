#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
bool isTaken[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, x, i, pos, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            isTaken[i] = 0;
        }

        sort(a, a+n);

        ans = 0;
        for(i = 0; i < n; i++)
        {
            if(isTaken[i])
                continue;

            pos = lower_bound(a+i, a+n, a[i]*x) - a;

            while(pos < n && isTaken[pos])
                pos++;

            if(pos < n && a[pos] == a[i]*x)
                isTaken[i] = isTaken[pos] = 1;
            else
            {
                ans++;
                isTaken[i] = 1;
            }
        }

        cout << ans << "\n";
    }
}
