#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

int main()
{
    double v, p, r, h;
    cin >> v >> p;
    r = p/2/pi;
    h = v*3/2/pi/r/r;
    cout << pi*r*r*h/3;
}
