#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h, m;
    double degree = 0;

    while(scanf("%d:%d", &h, &m))
    {

        if(h + m == 0)
            break;

        h = h % 12;

        degree = 0;
        degree += 6.0 * m;
        degree -= 30 * h;
        degree -= 0.5 * m;
        if(degree >= 0 && degree <= 180)
            printf("%0.3lf\n", degree);
        else if(degree >= 180 && degree <= 360)
            printf("%0.3lf\n", 360 - degree);
        else if( degree >= -180 && degree <= 0)
            printf("%0.3lf\n", abs(degree));
        else
            printf("%0.3lf\n", 360 + degree);
    }
}
