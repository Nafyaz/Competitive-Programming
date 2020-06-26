#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;
    int a[n], b[n];

    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    sort(a, a+n);
    sort(b, b+n);

    int ans = 0, low, hi;
    for(i = 0; i < n; i++)
    {
        low = lower_bound(b, b+n, a[i]) - b;
        hi = upper_bound(b, b+n, a[i]) - b;

        ans += hi - low;
    }

    cout << ans;
}
