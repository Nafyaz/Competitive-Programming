#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int i, j, n, m, minj, maxi = 0;
    scanf("%d %d", &n, &m);
    int a;

    FORAB(i, 0, n)
    {
        minj = 1000000010;
        FORAB(j, 0, m)
        {
            scanf("%d", &a);
            if(a < minj)
                minj = a;
        }
        if(minj > maxi)
            maxi = minj;
    }
    printf("%d", maxi);
}
