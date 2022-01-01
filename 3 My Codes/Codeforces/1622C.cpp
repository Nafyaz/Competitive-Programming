#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
ll preSum[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, i, sum, operations, x, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        sum = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        if(sum <= k)
        {
            cout << "0\n";
            continue;
        }

        sort(a+1, a+n+1);

        for(i = 1; i <= n; i++)
        {
            preSum[i] = preSum[i-1] + a[i];
//            cout << preSum[i] << " ";
        }
//        cout << "\n";

        ans = sum - k;

        for(i = n; i >= 2; i--)
        {
            if(k - preSum[i-1] + preSum[1] < 0)
                x = (k - preSum[i-1] + preSum[1] - (n-i+1)) / (n-i+2);
            else
                x = (k - preSum[i-1] + preSum[1]) / (n-i+2);

            operations = max(0LL, a[1] - x) + (n-i+1);

//            cout << i << " " << (k - preSum[i-1] + preSum[1]) << " " << x << " " << max(0LL, a[1] - x) << " " << n-i+1 << " " << operations << "\n";

            ans = min(ans, operations);
        }

        cout << ans << "\n";
    }
}
/*
1
10 1
1 2 3 1 2 6 1 6 8 10
*/
/*
1
7 8
1 2 1 3 1 2 1
*/
