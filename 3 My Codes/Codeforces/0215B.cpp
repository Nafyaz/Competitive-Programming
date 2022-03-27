#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k, i, j;
    double A, B, x[5003], p1, r1, y[5003], r2, z, p2, ans;

    cin >> n;
    for(i = 0; i < n; i++)
        cin >> x[i];

    cin >> m;
    for(i = 0; i < m; i++)
        cin >> y[i];

    cin >> k;
    p2 = 5003;
    for(i = 0; i < k; i++)
    {
        cin >> z;
        p2 = min(p2, z);
    }

    cin >> A >> B;

    ans = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            r1 = x[i];
            p1 = y[j];

            r2 = sqrt(r1*r1*p1*B/(p1*B + p2*A));
            if(r2 < r1)
                ans = max(ans, r2);
        }
    }
    cout << fixed << setprecision(7) << ans;
}

