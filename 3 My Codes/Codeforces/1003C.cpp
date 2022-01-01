#include<bits/stdc++.h>
using namespace std;

int pre[5003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i;
    int a;
    double ans = 0;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        cin >> a;

        pre[i] = pre[i-1] + a;
    }

    for(; k <= n; k++)
    {
        for(i = k; i <= n; i++)
            ans = max(ans, (double)(pre[i] - pre[i-k])/k);
    }

    cout << fixed << setprecision(6) << ans << "\n";
}
