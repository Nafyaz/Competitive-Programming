#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, l = 0, ml = 1, x, prevx;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        //printf("%d ", x);
        if(l == 0)
        {
            l++;
            prevx = x;
        }
        else if(x <= 2*prevx)
        {
            l++;
            if(ml < l)
                ml = l;
            prevx = x;
        }
        else
        {
            l = 1;
            prevx = x;
        }
        //printf("%d\n", l);
    }
    printf("%lld", ml);
}
