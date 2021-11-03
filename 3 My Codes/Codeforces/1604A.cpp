#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, i, n, a, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        ans = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            ans += max(0, a-i-ans-1);
        }

        cout << ans << "\n";
    }
}
