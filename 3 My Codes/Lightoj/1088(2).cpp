#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, q, i, a, b, posa, posb, ans;
    int p[100009];

    cin >> t;

    while(t--)
    {
        cin >> n >> q;

        for(i = 0; i < n; i++)
            cin >> p[i];

        cout << "Case " << ++caseno << ":\n";

        while(q--)
        {
            cin >> a >> b;
            posa = lower_bound(p, p+n, a) - p;
            posb = lower_bound(p, p+n, b+1) - p;

            ans = posb - posa;

            cout << ans << "\n";
        }
    }
}
