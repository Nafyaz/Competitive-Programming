#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200009

ll a[N], subArraySum[N][2];

int main()
{
    ll i, n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll sum = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += (i % 2 == 0? a[i] : 0);
            a[i] *= (i % 2 == 0? -1 : 1);
        }
        subArraySum[0][0] = 0;
        subArraySum[0][1] = 0;
        ll mx = 0;
        for (i = 0; i < n; i++)
        {
            subArraySum[i + 1][0] = max(0LL, subArraySum[i][1] + a[i]);
            subArraySum[i + 1][1] = max(a[i], subArraySum[i][0] + a[i]);
            mx = max(subArraySum[i + 1][0], mx);
        }
        cout << sum + mx << endl;
    }

    return 0;
}

