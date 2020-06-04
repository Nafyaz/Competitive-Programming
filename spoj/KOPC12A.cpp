#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, h[10009], c[10009];

ll cost(ll k)
{
    ll i, ret = 0;
    for(i = 0; i < n; i++)
        ret = ret + abs(h[i]-k)*c[i];
    return ret;
}

int main()
{
    ll t, i, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> h[i];
        for(i = 0; i < n; i++)
            cin >> c[i];
//        cout << cost(0);

        ll l, r, m1, m2, x;
        ans = LLONG_MAX, l = 0, r = 100000;
        while(l <= r)
        {
            x = (r - l)/3;
            m1 = l + x;
            m2 = l + 2*x;

            ll c1 = cost(m1), c2 = cost(m2);
            ans = min({ans, c1, c2});
//            cout << l << "/" << m1 << ": " << c1 << ", " << r << "/" << m2 << ": " << c2 << endl;

            if(c1 < c2)
                r = m2 - 1;
            else if(c1 > c2)
                l = m1 + 1;
            else
            {
                l = m1 + 1;
                r = m2 - 1;
            }
        }

        cout << ans << endl;
    }
}

