#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, pos = 0, neg = 0, zr = 0;
    long long ans = 0;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &a);
        if(a <= -1)
        {
            ans += -1 - a;
            neg++;
        }

        else if(a >= 1)
        {
            ans += a - 1;
            pos++;
        }

        else if(a == 0)
            zr++;
    }

    if(zr)
        ans += zr;
    else if(neg%2)
        ans += 2;

    printf("%lld", ans);

}
