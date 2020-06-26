#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("Gout.txt", "w", stdout);
    double pi = 2 * acos(0.0);
    int i, T;
    double l, n, c, s, r, h, high, low = 0, theta;
    scanf("%d", &T);

    for(i = 1; i <= T; i++)
    {
        scanf("%lf %lf %lf", &l, &n, &c);
        //scanf("%lf %lf", &s, &l);
        high = pi / 2, low = 0;
        s = (1 + n*c)*l;
        while(high - low > 0.00000000001)
        {
            theta = (high + low) / 2;
            if(s/l > theta/sin(theta))
                low = theta;
            else
                high = theta;
        }
        //printf("%lf", theta);
        r = s/(2 * theta);
        h = r - r*cos(theta);
        printf("Case %d: %0.8lf\n", i, h);
    }
}
