#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, ai, bi, now = 0, maxnow = 0;
    scanf("%d", &n);


    for(i = 0; i < n; i++)
    {
        ai = 0, bi = 0;
        scanf("%d %d", &ai, &bi);
        now += bi - ai;
        if (maxnow < now) maxnow = now;
    }
    printf("%d", maxnow);
}
