#include<stdio.h>
int main()
{
    int i, j, ma, mo, mx;

    int n = 2, k = 2;
    ma = 0;
    mo = 0;
    mx = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = i+1; j <= n; j++)
        {
//            printf("%d %d %d\n", i&j, i|j, i^j);
            if((i&j) > ma && (i&j) < k)
                ma = (i&j);
            if((i|j) > mo && (i|j) < k)
                mo = (i|j);
            if((i^j) > mx && (i^j) < k)
                mx = (i^j);
        }
    }

    printf("%d\n%d\n%d", ma, mo, mx);
}
