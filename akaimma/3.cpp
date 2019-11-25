#include<bits/stdc++.h>
using namespace std;
long long a[110][110];
long long nCr(int n, int r)
{
    if(r>n||r<0)
        return 0;
    if(r>n/2)
    {
        a[n][r]=nCr(n,n-r);
        return a[n][r];
    }
    if(r==0)
    {
        a[n][0]=1;
        return 1;
    }
    if(a[n][r]!=0)
        return a[n][r];
    a[n][r]=nCr(n,r-1)*(n-r+1)/r;
    return a[n][r];
}
int main()
{
    freopen("a.txt","w",stdout);
    int n,r;
    scanf("%d %d",&n,&r);
    while(n!=0&&r!=0)
    {
        printf("%d things taken %d at a time is %I64d exactly.\n",n,r,nCr(n,r));
        scanf("%d %d",&n,&r);
    }
}
