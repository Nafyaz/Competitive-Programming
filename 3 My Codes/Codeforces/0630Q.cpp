#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double l;

    cin >> l;
    double a1 = sqrt(3)/4*l*l;
    double h1 = sqrt(2)/sqrt(3)*l;
    double v1 = 1.0/3*a1*h1;

    cin >> l;
    double a2 = l*l;
    double h2 = l/sqrt(2);
    double v2 = 1.0/3*a2*h2;

    cin >> l;
    double a3 = 5.0/2*l*l*sin(pi/180*54)*sin(pi/180*54)/sin(pi/180*72);
    double h3 = l/sin(pi/180*72)*sqrt(sin(pi/180*72)*sin(pi/180*72) - sin(pi/180*54)*sin(pi/180*54));
    double v3 = 1.0/3*a3*h3;

    cout << fixed << setprecision(10) << v1+v2+v3;
}
