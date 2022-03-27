#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, d, dist;
    ll n;

    cin >> a >> d >> n;

    cout << fixed << setprecision(6);

    dist = 0;
    while(n--)
    {
        dist += d;

        dist -= floor(dist/a/4)*a*4;

        if(dist <= a)
            cout << dist << " 0\n";
        else if(dist <= 2*a)
            cout << a << " " << dist-a << "\n";
        else if(dist <= 3*a)
            cout << a - (dist-2*a) << " " << a << "\n";
        else
            cout << "0 " << a - (dist-3*a) << "\n";
    }
}
