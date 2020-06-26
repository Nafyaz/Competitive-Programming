#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
//    freopen("out.txt", "w", stdout);
    int t, caseno = 0;
    long double l, l2, h, r, theta, n, C, low, high, x;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%Lf %Lf %Lf", &l, &n, &C);
        l2 = (1 + n*C)*l;

        low = 0;
        high = l2;

        x = 10000;
        while(x--)
        {
            h = (low + high)/2;
//            if(h <= 0.00000001)
//                break;
            theta = atan(l/2/h) - atan(h/l*2);
            r = l/2/cos(theta);

            theta = pi - 2*theta;
            if(r*theta >l2)
                high = h;
            else
                low = h;
        }

        printf("Case %d: %0.10Lf\n", ++caseno, h);
    }
}
