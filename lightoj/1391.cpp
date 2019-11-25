#include<bits/stdc++.h>
using namespace std;
#define PI 2*acos(0)
int n;
double s[110], d2;

double func(int y, double theta)
{
    if(y == n)
        return 0;
    double time;
    d2 =  d2 + 100 / tan(theta);
    time = 100 / (s[y] * sin(theta));
    theta = acos(s[y + 1] / s[y] * cos(theta));

    return time + func(y+1, theta);
}
int main()
{
    int t, caseno = 0, i;
    double d, l, r, mid, time;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %lf", &n, &d);
        for(i = 0; i < n; i++)
            scanf("%lf", &s[i]);
        s[n] = 1;

        l = PI/2;
        r = 0;

        for(i = 0; i < 115; i++)
        {
            d2 = 0;
            mid = (l + r) / 2;
            //printf("%f\n", mid);
            time = func(0, mid);
            //printf("%f\n", d2);
            if(d2 > d)
                r = mid;
            else
                l = mid;
        }
        printf("Case %d: %f\n", ++caseno, time);
    }
}
