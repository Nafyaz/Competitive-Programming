#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    double x, y, d, a;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%lf : %lf", &x, &y);
        d = sqrt(x*x + y*y);
        a = 200 / (x + d*asin(y/d));
        printf("Case %d: %0.8f %0.8f\n", ++caseno, a*x, a*y);
    }
}
