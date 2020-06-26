#include<stdio.h>
#include<math.h>
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        long long n,x,y;
        scanf("%I64d",&n);
        long long sq=(long long)ceil(sqrt(n));
        if(sq%2==1)
        {
            if(n-(sq-1)*(sq-1)<=sq)
            {
                x=sq;
                y=n-(sq-1)*(sq-1);
            }
            else
            {
                x=sq*sq-n+1;
                y=sq;
            }
        }
        else
        {
            if(n-(sq-1)*(sq-1)<=sq)
            {
                x=n-(sq-1)*(sq-1);
                y=sq;
            }
            else
            {
                x=sq;
                y=sq*sq-n+1;
            }
        }
        printf("Case %d: %I64d %I64d\n",i,x,y);
    }
}
