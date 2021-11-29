#include <iostream>
#include <string.h>
using namespace std;
#define mod 1000000007
int n,k,d,dp[105][105];
int go(int s,int m)
{
    if (s>n)
        return 0;
    if (s==n)
        return (m>=d);
    if (dp[s][m]!=-1)
        return dp[s][m];
    int ans=0;
    for (int i=1; i<=k; i++)
        ans=(ans+go(s+i,max(m,i)))%mod;
    return dp[s][m]=ans;
}
int main()
{
    scanf("%d%d%d",&n,&k,&d);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",go(0,0));
}
