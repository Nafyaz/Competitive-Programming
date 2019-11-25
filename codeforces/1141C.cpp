#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i <= b; i++)

int main()
{
    int i, n;
    scanf("%d", &n);
    int minr, minri;

    int p[n + 1], q[n], r[n + 1];


    r[1] = 0;
    FORAB(i, 1, n - 1)
    {
        scanf("%d", &q[i]);
        r[1] += q[i];
    }

    minr = r[1];
    minri = 1;
    FORAB(i, 2, n)
    {
        r[i] = r[i - 1] - q[i - 1];
        if(r[i] > minr)
        {
            minr = r[i];
            minri = i;
        }
    }


    int check[n+1] = {0};

    p[minri] = 1;
    check[1] = 1;

    FORAB(i, minri + 1, n)
    {
        p[i] = q[i - 1] + p[i - 1];
        if(p[i] >= 1 && p[i] <= n)
            check[p[i]] = 1;
    }
    for(i = minri - 1; i >= 1; i--)
    {
        p[i] = p[i + 1] - q[i];
        if(p[i] >= 1 && p[i] <= n)
            check[p[i]] = 1;
    }


    FORAB(i, 1, n)
    {
        if(check[i] != 1)
        {
            printf("-1");
            return 0;
        }
    }
    FORAB(i, 1, n)
        printf("%d ", p[i]);

}
