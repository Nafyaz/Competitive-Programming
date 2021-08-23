#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, s[5003], ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> s[i];

        sort(s, s+n);

        ans = INT_MAX;
        for(i = 1; i < n; i++)
            ans = min(ans, s[i] - s[i-1]);

        cout << ans << "\n";
    }

}
