#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x1, y1, x2, y2, n, i, a, b, c, ans = 0;

    cin >> x1 >> y1 >> x2 >> y2;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        ll sign1 = (a*x1+b*y1+c) / abs(a*x1+b*y1+c);
        ll sign2 = (a*x2+b*y2+c) / abs(a*x2+b*y2+c);

        ans += (sign1*sign2 == -1);
    }

    cout << ans;
}
