#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t, p, a, b, c, x, y;

    cin >> t;

    while(t--)
    {
        cin >> p >> a >> b >> c >> x >> y;

        cout << p/min(b+a*x, c+a*y) << "\n";
    }
}
