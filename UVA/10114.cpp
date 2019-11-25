#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, t, i, j, temp;
    double b, a, x, temp2;//mno is month no
    while(scanf("%d %lf %lf", &m, &b, &a))
    {
        scanf("%d", &t);
        //int mno[m];
        double r[m + 5];

        for(i = 0; i < t; i++)
        {
            scanf("%d %lf", &temp, &temp2);
            r[temp] = temp2;
        }

        for(i = 1; i < m+5; i++)
        {
            if(r[i] == '\0')
                r[i] = r[i - 1];
        }
        x = b + a;


        for(i = 0; i < t; i++)
        {
            x = x - x*r[i];
            a = a - b;
            if(a < x)
                break;
        }

        printf("%d\n", i - 1);
    }
}
