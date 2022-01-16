#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, b, mx, cnt, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        mx = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        ans = 0;
        for(b = 1; b <= mx; b *= 2)
        {
            for(i = 0, cnt = 0; i < n; i++)
                cnt += ((a[i] & b) != 0);

            if(cnt > 1)
                ans += b;
        }

        cout << ans << "\n";
    }
}
