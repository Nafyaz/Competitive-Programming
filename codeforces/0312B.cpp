#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double x = a/b, y = c/d;
    cout << setprecision(10) << x / (1 - (1 - x)*(1 - y));
}
