#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, a, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        ans = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            ans |= a;
        }

        cout << ans << "\n";
    }
}
