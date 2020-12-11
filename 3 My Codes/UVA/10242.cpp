#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

void func(double x1, double y1, double x2, double y2, double x3, double y3)
{
    cout << fixed;
    cout << setprecision(3) << x3 - x2 + x1 << " " << y3 - y2 + y1 << "\n";
}

int main()
{
    double x[4], y[4];
    set<pair<double, double>> p;
    while(cin >> x[0] >> y[0])
    {
        cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];

        if(x[0] == x[2] && y[0] == y[2])
            func(x[1], y[1], x[0], y[0], x[3], y[3]);
        else if(x[0] == x[3] && y[0] == y[3])
            func(x[1], y[1], x[0], y[0], x[2], y[2]);
        else if(x[1] == x[2] && y[1] == y[2])
            func(x[0], y[0], x[1], y[1], x[3], y[3]);
        else if(x[1] == x[3] && y[1] == y[3])
            func(x[0], y[0], x[1], y[1], x[2], y[2]);
    }
}
