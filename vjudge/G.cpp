#include<bits/stdc++.h>
using namespace std;

double p, q, r, s, t, u;
double equation(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    double x, low, high, mid;
    while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u, &x) == 6)
    {
        low = 0, high = 1;
        while(low < high)
        {
            mid = (low+high)/2;

        }
    }
}
