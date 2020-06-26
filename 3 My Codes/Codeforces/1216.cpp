#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int t, caseno = 0;
    double r1, r2, h, p, r3, x, ans;

    cin >> t;
    while(t--)
    {
        cin >> r1 >> r2 >> h >> p;
        x = r2*h/(r1-r2);
        r3 = (p+x)*r2/x;
        ans = pi/3*(r3*r3*(p+x) - r2*r2*x);

        cout << fixed;
        cout << "Case " << ++caseno << ": " << setprecision(7) << ans << endl;
    }
}
