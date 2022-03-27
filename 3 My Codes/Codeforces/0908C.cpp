#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, r, i, j, x[1002];
    double y[1002];

    cin >> n >> r;

    for(i = 0; i < n; i++)
    {
        cin >> x[i];

        y[i] = r;
        for(j = 0; j < i; j++)
        {
            if(abs(x[i] - x[j]) <= 2*r)
                y[i] = max(y[i], y[j] + sqrt(4*r*r - (x[i]-x[j])*(x[i]-x[j])));
        }

        cout << fixed << setprecision(7) << y[i] << " ";
    }
}
