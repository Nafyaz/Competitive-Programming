#include<bits/stdc++.h>
using namespace std;

bool is_contained(double llx, double lly, double urx, double ury, double x, double y)
{
    return (x >= llx && x <= urx && y >= lly && y <= ury);
}

int main()
{
    double a, b, c, x[2], y[2], h[2] = {0};

    cin >> a >> b >> c;

    cin >> x[0] >> y[0] >> x[1] >> y[1];

    for(int i = 0; i < 2; i++)
    {
        if(is_contained(c, 0, c+a, b, x[i], y[i]))
        {
            y[i] = (b - y[i]) + (b + c);
            h[i] = c;
        }
        else if(is_contained(c, b, c+a, b+c, x[i], y[i]))
        {
            h[i] = b+c-y[i];
            y[i] = b+c;
        }
        else if(is_contained(c, 2*b+c, c+a, 2*b+2*c, x[i], y[i]))
        {
            h[i] = y[i] - 2*b-c;
            y[i] = 2*b + c;
        }
        else if(is_contained(0, b+c, c, 2*b+c, x[i], y[i]))
        {
            h[i] = c-x[i];
            x[i] = c;
        }
        else if(is_contained(c+a, b+c, 2*c+a, 2*b+c, x[i], y[i]))
        {
            h[i] = x[i] - c - a;
            x[i] = c+a;
        }
    }

    cout << fixed;
    cout << setprecision(7) << sqrt((x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]) + (h[0]-h[1])*(h[0]-h[1]));
}
