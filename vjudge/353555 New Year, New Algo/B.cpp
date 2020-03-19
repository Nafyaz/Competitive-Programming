#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll xsp[100009][20], nsp[100009][20], Log[100009], a[100009];

ll find_high(ll i, ll j)
{
    ll r = Log[j-i+1];
    return max(xsp[i][r], xsp[j - (1<<r) + 1][r]);
}

ll find_low(ll i, ll j)
{
    ll r = Log[j-i+1];
    return min(nsp[i][r], nsp[j - (1<<r) + 1][r]);
}

int main()
{
    ll n, k, i, j;

    for(i = 2; i < 100009; i++)
        Log[i] = Log[i>>1] + 1;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        xsp[i][0] = a[i];
        nsp[i][0] = a[i];
    }

    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
        {
            xsp[i][j] = max(xsp[i][j-1], xsp[i + (1 << (j - 1))][j-1]);
            nsp[i][j] = min(nsp[i][j-1], nsp[i + (1 << (j - 1))][j-1]);
        }
    }

//    while(1)
//    {
//        cin >> i >> j;
//    cout << find_high(i, j) << " " << find_low(i, j) << endl;
//    }

    ll low, high, mid, mx, ans = 0;
    for(i = 0; i < n; i++)
    {
        low = i;
        high = n-1;
        while(low <= high)
        {
            mid = (high + low) >> 1;
            if(abs(find_high(i, mid) - find_low(i, mid)) <= k)
            {
                mx = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
//        cout << i << ": " << mx << endl;
        ans = ans + mx - i + 1;
    }
    cout << ans << endl;

}
