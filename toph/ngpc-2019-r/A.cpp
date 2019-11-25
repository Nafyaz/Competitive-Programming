#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, q, i, j, m, x, l, r, k, total = 0, lpos, rpos;
    cin >> n >> q;
    ll a[n];

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);
    while(q--)
    {
        cin >> m;
        if(m == 1)
        {
            cin >> x;
            total += x;
        }
        else
        {
            cin >> l >> r >> k;
            lpos = lower_bound(a, a+n, l+total) - a;
            rpos = upper_bound(a, a+n, r+total) - a;

            if(rpos - lpos < k)
                cout << -1 << endl;
            else
                cout << a[lpos + k - 1] - total << endl;
        }
    }
}
