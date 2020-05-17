#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j, n, k, a[35], b[35], ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < n; i++)
            cin >> b[i];

        sort(a, a+n);
        sort(b, b+n, greater<int>());

        ans = 0;
        for(i = 0; i < k; i++)
            ans += max(a[i], b[i]);
        for(i = k; i < n; i++)
            ans += a[i];

        cout << ans << endl;
    }
}
