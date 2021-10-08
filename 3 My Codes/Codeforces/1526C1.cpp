#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll i, j, n, a[2003], health[2003][2003], cnt[2003][2003], ans;

int main()
{
    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            health[i][j] = max(health[i][j], health[i-1][j]);
            cnt[i][j] = max(cnt[i][j], cnt[i-1][j]);

            if(health[i-1][j-1] + a[i] >= 0)
            {
                health[i][j] = max(health[i][j], health[i-1][j-1] + a[i]);
                cnt[i][j] = max(cnt[i][j], cnt[i-1][j-1]+1);
                ans = max(ans, cnt[i][j]);
            }
        }
    }

    cout << ans;
}
