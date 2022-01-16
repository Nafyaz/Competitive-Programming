#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, i, cnt, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        ans = a[1];

        for(i = 2, cnt = 0; i <= n; i++)
        {
            if(a[i])
                cnt++;
            else
                cnt = 0;

            if(cnt == 3)
            {
                ans++;
                cnt = 0;
            }
        }

        cout << ans << "\n";
    }
}
