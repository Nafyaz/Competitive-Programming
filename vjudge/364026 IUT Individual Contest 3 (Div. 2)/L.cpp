#include<bits/stdc++.h>
using namespace std;

int x[1000009], y[1000009];

int main()
{
    int t, i, j, n, e, p, a, b, c;
    cin >> t;
    while(t--)
    {
        cin >> n >> e >> p;
        for(i = 0; i < e; i++)
            cin >> x[i];
        for(i = 0; i < p; i++)
            cin >> y[i];

        sort(x, x+e);
        sort(y, y+p);

        long long ans = 0;
        for(i = 0; i < p; i++)
        {
            a = (lower_bound(x, x+e, y[i]) - x)%e;
            b = (a+1)%e;
            c = (a-1+e)%e;
            cout << y[i] << " " << a << " " << b << " " << c << endl;

            a = min((y[i] - x[a] + n)%n, (x[a] - y[i] + n)%n);
            b = min((y[i] - x[b] + n)%n, (x[b] - y[i]+ n)%n);
            c = min((y[i] - x[c] + n)%n, (x[c] - y[i] + n)%n);

            ans += min({a, b, c});
        }

        cout << ans << endl;
    }
}
