#include<bits/stdc++.h>
using namespace std;

int a[1000];

int rec(int l, int h, int x)
{
    if(l > h)
        return -1;
    int m = (l + h) /2;

    if(x == a[m])
        return m;
    else if(x < a[m])
        return rec(l, m - 1, x);
    else if(x > a[m])
        return rec(m + 1, h, x);
}

int main()
{
    int i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int q, x;
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        scanf("%d", &x);
        printf("%d\n", rec(0, n-1, x));
    }
}
