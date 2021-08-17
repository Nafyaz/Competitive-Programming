#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, i, j, ans, cnt;
    int l[2009];

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> l[i];

        sort(l, l+n);

        ans = 0;
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                int sum = l[i] + l[j];

                cnt = lower_bound(l, l+n, sum) - l - j - 1;
                ans += cnt;
            }
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
