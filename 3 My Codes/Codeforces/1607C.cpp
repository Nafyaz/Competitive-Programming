#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    int T, n, i, total, val, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        total = 0;
        ans = INT_MIN;

        for(i = 0; i < n; i++)
        {
            val = a[i] - total;
            total += val;
            ans = max(ans, val);
        }

        cout << ans << "\n";
    }
}
