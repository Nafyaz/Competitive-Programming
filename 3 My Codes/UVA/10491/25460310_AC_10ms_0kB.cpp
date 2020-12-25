#include<bits/stdc++.h>
using namespace std;

int main()
{
    long double x, y, z, ans;
    while(cin >> x >> y >> z)
    {
        ans = (x*y + y*y - y)/(x+y)/(x+y-z-1);
        cout << fixed;
        cout << setprecision(5) << ans << endl;
    }
}
