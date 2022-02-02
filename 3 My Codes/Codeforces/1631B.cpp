#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, k, needChange, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        ans = 0;
        for(i = n-2; i >= 0; i--)
        {
            if(a[i] != a[n-1])
            {
                ans++;
                k = n - i - 1;
                i = n - 2*k;
            }
        }

        cout << ans << "\n";
    }
}
