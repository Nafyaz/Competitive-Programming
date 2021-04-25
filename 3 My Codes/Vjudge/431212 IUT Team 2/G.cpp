#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, caseno = 0, n, i, k, p, ans, cnt;

    ll s[1010];

    cin >> t;

    while(t--)
    {
        memset(s, 0, sizeof s);

        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> k >> p;
            s[p] += k;
        }

        ans = cnt = 0;
        for(i = 1000; i >= 0; i--)
        {
            cnt += s[i];
            ans = max(ans, i*cnt);
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
