#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z, x1, y1, z1;
    int a[7], ans = 0;

    cin >> x >> y >> z;
    cin >> x1 >> y1 >> z1;
    cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];

    if(y < 0)
        ans += a[1];
    if(y > y1)
        ans += a[2];
    if(z < 0)
        ans += a[3];
    if(z > z1)
        ans += a[4];
    if(x < 0)
        ans += a[5];
    if(x > x1)
        ans += a[6];

    cout << ans;
}
