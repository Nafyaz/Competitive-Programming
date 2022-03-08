#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[2003], b[2003];
ll preA[2003], preB[2003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, x, i, j, lenA, r1, r2, c1, c2, mnR1, mnR2;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        preA[i] = preA[i-1] + a[i];
    }
    for(i = 1; i <= m; i++)
    {
        cin >> b[i];
        preB[i] = preB[i-1] + b[i];
    }

    cin >> x;

    ll ans = 0;
    for(lenA = 1; lenA <= n; lenA++)
    {
        mnR1 = 1;
        mnR2 = 1+lenA-1;
        for(r1 = 2; r1+lenA-1 <= n; r1++)
        {
            r2 = r1+lenA-1;
            if(preA[r2] - preA[r1-1] < preA[mnR2] - preA[mnR1-1])
            {
                mnR1 = r1;
                mnR2 = r2;
            }
        }

//        cout << "lenA: " << lenA << "; " << mnR1 << " " << mnR2 << "\n";

        for(c1 = 1, c2 = 1; c2 <= m; c2++)
        {
//            cout << "Before: " << c1 << " " << c2 << "\n";

            while(c1 <= c2 && (preA[mnR2] - preA[mnR1-1]) * (preB[c2] - preB[c1-1]) > x)
                c1++;

//            cout << "After: " << c1 << " " << c2 << "\n\n";
            if(c1 <= c2)
                ans = max(ans, (mnR2 - mnR1 + 1)*(c2 - c1 + 1));
        }
    }

    cout << ans;
}
