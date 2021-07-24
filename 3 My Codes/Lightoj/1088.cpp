#include<bits/stdc++.h>
using namespace std;
int func(int *p,int n,int a,int b)
{
    int i;
    int low=0,high=n-1,mid,x,y;
    while(low<=high)
    {
        mid=(high-low)/2+low;
        if(p[mid]>=a)
            high=mid-1;
        else
            low=mid+1;
    }
    x=high;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(high-low)/2+low;
        if(p[mid]<=b)
            low=mid+1;
        else
            high=mid-1;
    }
    y=low;
    return y-x-1;
}
int main()
{
    int t,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        int n,q,i;
        scanf("%d %d",&n,&q);
        int p[n];
        for(i=0;i<n;i++)
            scanf("%d",&p[i]);

        int a,b;
        printf("Case %d:\n",j);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",func(p,n,a,b));
        }
    }
}
