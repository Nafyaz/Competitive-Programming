#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, T;
    double s, sq;
    int sqi;
    scanf("%d", &T);
    for(i = 1; i <= T; i++)
    {
        scanf("%lf", &s);
        printf("Case %d: ",i);
        sq = floor(sqrt(s));
        sqi = sq;
        //printf("%d %lf\n", sqi, sq);
        if(sq*sq == s)
        {
            if(sqi % 2 == 0)
                printf("%d 1\n", sqi);
            else
                printf("1 %d\n", sqi);
        }
        else if(sqi % 2 == 0)
        {
            if(s <= sq*sq + sq)
                printf("%d %d\n", (int)(sq + 1), (int)(s - sq*sq));
            else
                printf("%d %d\n", (int)(sq + 2 - (s - sq*sq - sq)),(int) (sq + 1));
        }
        else
        {
            if(s <= sq*sq + sq)
                printf("%d %d\n", (int)(s - sq*sq), (int)(sq + 1));
            else
                printf("%d %d\n",(int) (sq + 1), (int)(sq + 2 - (s - sq*sq - sq)));
        }
    }
}
