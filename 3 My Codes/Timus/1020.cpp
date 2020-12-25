#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)

class pt
{
public:
    double x, y;
};

double dist(pt a, pt b)
{
    return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}

int main()
{
    int n, i;
    double r, ans = 0;

    cin >> n >> r;

    pt a[n];

    for(i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
//        a[i].r = r;
    }

    for(i = 0; i < n; i++)
        ans += dist(a[i], a[(i+1)%n]);

    ans += 2*pi*r;

    cout << fixed;
    cout << setprecision(2) << ans;
}
