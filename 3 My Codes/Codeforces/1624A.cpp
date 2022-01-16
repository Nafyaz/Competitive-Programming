#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, a, mn, mx;

    cin >> t;

    while(t--)
    {
        cin >> n;

        mn = INT_MAX;
        mx = INT_MIN;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }

        cout << mx - mn << "\n";
    }
}
