//most probably this will get TLE
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, l, r, i, j, len, candy;

    scanf("%d", &n);
    int a[n+1], b[n];
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        candy = 0;
        scanf("%d %d", &l, &r);
        len = r-l+1;

        while(len != 1)
        {
            if(len == r-l+1)
            {
                for(j = 0; j < len/2; j++)
                {
                    b[j] = a[l + 2*j] + a[l + 2*j+1];
                    if(b[j] >= 10)
                        candy++;
                    b[j] %= 10;
                    //printf("%d ", b[j]);
                }
                //printf("\n");
                len = len >> 1;
                continue;
            }
            for(j = 0; j < len/2; j++)
            {
                b[j] = b[2*j] + b[2*j+1];
                if(b[j] >= 10)
                    candy++;
                b[j] %= 10;
                //printf("%d ", b[j]);
            }
            //printf("\n");
            len = len >> 1;
        }
        printf("%d\n", candy);
    }
}
