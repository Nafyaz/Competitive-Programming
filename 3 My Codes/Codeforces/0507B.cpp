#include<bits/stdc++.h>
using namespace std;
int main()
{
    double r, x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf %lf", &r, &x1, &y1, &x2, &y2);

    double dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    printf("%d", (int)ceil(dis/r/2));
}
