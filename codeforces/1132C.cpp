#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int i, n, j, q, k, l, paint, maxpaint = 0;
    scanf("%d %d", &n, &q);

    int fence[n];


    int a[q][2];

    FORAB(i, 0, q)
        scanf("%d %d", &a[i][0], &a[i][1]);

    FORAB(i, 0, q)
    {
        FORAB(j, i + 1, q)
        {

            FORAB(k, 0, n)
                fence[k] = 0;

            paint = 0;
            FORAB(k, 0, q)
            {
                if(k == i || k == j)
                    continue;
                FORAB(l, a[k][0] - 1, a[k][1])
                    fence[l] = 1;
                /*printf("\n");
                FORAB(l, 0, n)
                    printf("%d ", fence[l]);
                printf("\n");*/
            }

            FORAB(k, 0, n)
                paint += fence[k];

            if(paint > maxpaint)
                maxpaint = paint;
        }
    }
    printf("%d", maxpaint);
}
