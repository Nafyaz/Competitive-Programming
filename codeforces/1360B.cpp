#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, s[50], ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        sort(s, s+n);
        ans = 1009;
        for(i = 1; i < n; i++)
        {
            ans = min(ans, s[i] - s[i-1]);
        }

        cout << ans << endl;
    }
}
