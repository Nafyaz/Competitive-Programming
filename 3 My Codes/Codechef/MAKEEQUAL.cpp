#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, i, a, mn, mx;

    cin >> T;

    while(T--)
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
