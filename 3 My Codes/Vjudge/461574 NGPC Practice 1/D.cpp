#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, k, a[100005], i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        ans = 0;
        for(i = 0; i < n; i++)
        {
            if(i < k && a[i] < 0)
                ans -= a[i];
            if(a[i] > 0)
                ans += a[i];
        }

        cout << ans << "\n";
    }
}
