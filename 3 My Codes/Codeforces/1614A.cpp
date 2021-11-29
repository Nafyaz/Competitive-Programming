#include<bits/stdc++.h>
using namespace std;

int a[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T, n, l, r, k, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> l >> r >> k;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        ans = 0;
        for(i = 0; i < n; i++)
        {
            if(l <= a[i] && a[i] <= r && k >= a[i])
            {
                ans++;
                k -= a[i];
            }
        }

        cout << ans << "\n";
    }
}
