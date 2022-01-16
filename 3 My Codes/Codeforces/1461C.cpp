#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, i, a, lastBad, r;
    double p, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        lastBad = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> a;

            if(a != i)
                lastBad = i;
        }

        ans = 1;
        for(i = 1; i <= m; i++)
        {
            cin >> r >> p;

            if(r >= lastBad)
                ans *= (1 - p);
        }

        cout << fixed << setprecision(7) << (lastBad? 1 - ans : 1.0) << "\n";
    }
}
