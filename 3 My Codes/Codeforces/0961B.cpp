#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, a[100005], t, prefa[100005], preft[100005], ans;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    prefa[0] = preft[0] = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> t;
        prefa[i] = prefa[i-1] + a[i];
        preft[i] = preft[i-1] + a[i] * t;
    }

    ans = preft[n];

    for(i = 1; i <= n-k+1; i++)
        ans = max(ans, preft[n] - (preft[i+k-1] - preft[i-1]) + (prefa[i+k-1] - prefa[i-1]));

    cout << ans;
}
