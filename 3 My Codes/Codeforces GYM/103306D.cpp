#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, c, r, cc, rr, s, mx, mn;

    cin >> t;

    while(t--)
    {
        cin >> c >> r >> s;

        cc = c%s;
        rr = r%s;

        mx = c / s;
        if(rr == 0 && cc > 0)
            mx++;
        if(rr > 0 && cc+rr > s)
            mx++;

        c = max(0LL, c - (s-1)*r);
        mn = c / s;
        if(c%s > 0)
            mn++;

        cout << mx << " " << mn << "\n";
    }
}
