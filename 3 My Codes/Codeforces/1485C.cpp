#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, a, b, x, y, i, ans;

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        ans = 0;
        for(b = 1; b*b-1 <= x && b <= y; b++)
        {
            ans += min(x/(1+b), b-1);
            cout << b << "\n";
        }

        cout << ans << "\n";
    }
}
