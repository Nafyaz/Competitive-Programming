#include<bits/stdc++.h>
using namespace std;
int findDiv(int n)
{
    int i,ans=2;
    int sq=sqrt(n);
    for(i=2;i<=sq;i++)
    {
        if(n%i==0)
            ans+=2;
    }
    if(sq*sq==n)
        ans--;
    return ans;
}
int main()
{
    int i,j,q;
    scanf("%d",&q);
    while(q--)
    {
        int k;
        scanf("%d",&k);
        for(i=1,j=0;;i++)
        {
            j+=findDiv(i);
            if(j>=k)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}
