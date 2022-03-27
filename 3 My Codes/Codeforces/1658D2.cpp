#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
ll Log[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, l, r, i, j, mx, mn, mxa, flag;
    for(i = 2; i < 200005; i++)
        Log[i] = Log[i/2] + 1;

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        mxa = INT_MIN;
        for(i = l; i <= r; i++)
        {
            cin >> a[i];
            mxa = max(mxa, a[i]);
        }

        cout << "mxa: " << Log[mxa] << "; ";
        mxa = (1LL << (Log[mxa] + 1)) - 1;
        cout << "mxa: " << mxa << "\n";

        for(i = 0; i <= mxa; i++)
        {
            mn = INT_MAX;
            mx = INT_MIN;
            flag = 1;

            for(j = l; j <= r; j++)
            {
                mx = max(mx, a[j]^i);
                mn = min(mn, a[j]^i);

                if(mx > r || mn < l)
                {
                    flag = 0;
                    break;
                }

            }

            if(flag)
            {
                cout << i << "\n";
                break;
            }
        }
    }
}
