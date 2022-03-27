#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, l, r, i, j, mx, flag;

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        for(i = 0; i <= r; i++)
            cin >> a[i];

        for(i = 0; i <= r; i++)
        {
            mx = INT_MIN;
            flag = 1;

            for(j = 0; j <= r; j++)
            {
                mx = max(mx, a[j]^a[i]);

                if(mx > r)
                {
                    flag = 0;
                    break;
                }

            }

            if(flag)
            {
                cout << a[i] << "\n";
                break;
            }
        }
    }
}
