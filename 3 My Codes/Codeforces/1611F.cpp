#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005], pref[200005];
ll Log[200005], sparse[200005][20];

ll find_min(ll a, ll b)
{
    ll k = Log[b-a+1];

    return min(sparse[a][k], sparse[b-(1LL<<k)+1][k]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, n, s, i, j, low, high, mid, mn, range, ansLeft, ansRight;

    for(i = 2; i < 200005; i++)
        Log[i] = Log[i/2] + 1;

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
            sparse[i][0] = pref[i];
        }

        for(j = 1; j < 20; j++)
        {
            for(i = 1; i + (1LL<<j) - 1 <= n; i++)
                sparse[i][j] = min(sparse[i][j-1], sparse[i + (1LL<<(j-1))][j-1]);
        }

//        for(j = 0; j < 3; j++)
//        {
//            for(i = 0; i <= 3; i++)
//                cout << setw(10) << sparse[i][j];
//            cout << "\n";
//        }

        range = -1;
        for(i = 1; i <= n; i++)
        {
            low = i;
            high = n;

            while(low <= high)
            {
                mid = (low + high)/2;
                mn = find_min(i, mid);

                if(s + mn - pref[i-1] >= 0)
                {
                    if(mid - i + 1 > range)
                    {
                        range = mid - i + 1;
                        ansLeft = i;
                        ansRight = mid;
                    }
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
        }

        if(range == -1)
            cout << "-1\n";
        else
            cout << ansLeft << " " << ansRight << "\n";
    }
}
