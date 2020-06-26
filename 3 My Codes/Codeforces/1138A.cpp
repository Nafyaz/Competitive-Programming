// kaka, ager ta te bug chilo. tao accept hoise :v :v

#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, j, k, now = 0, sum = 0, minad, maxad = 0;
    scanf("%d", &n);
    int a[n];

    int x[n];
    FORAB(i, 0, n)
        x[i] = 0;

    FORAB(i, 0, n)
    {
        scanf("%d", &a[i]);
        sum ++;
    }
    j = 0;
    x[j] ++;
    FORAB(i, 1, n)
    {
        if(a[i] != a[i - 1])
        {
            j++;
            x[j]++;
        }
        else
            x[j]++;

    }

    for(i = 0; x[i] + now < sum; i++)
    {
        minad = min(x[i], x[i + 1]);
        if(maxad < minad)
            maxad = minad;
        now += x[i];
    }

    /*FORAB(i, 0, n)
        printf("%d ", x[i]);
    printf("\n");*/
    printf("%d", 2*maxad);

}
