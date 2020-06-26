#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i;

    scanf("%d", &n);
    int l[n], r[n], d[n], a = 0, b = 0, sum = 0;

    FORAB(i, 0, n)
    {
        scanf("%d %d", &l[i], &r[i]);
        d[i] = l[i] - r[i];
        if(d[i] > l[a] - r[a])
            a = i;
        if(d[i] < l[b] - r[b])
            b = i;

        sum = sum + l[i] - r[i];
    }
    int x = abs(sum - 2*d[a]);
    int y = abs(sum - 2*d[b]);

    if(x > y)
    {
        if(abs(sum) < x)
            printf("%d", a + 1);
        else
            printf("0");
    }
    else
    {
        if(abs(sum) < y)
            printf("%d", b + 1);
        else
            printf("0");
    }
}
