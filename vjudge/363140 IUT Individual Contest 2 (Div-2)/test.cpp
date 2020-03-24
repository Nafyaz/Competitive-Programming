#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[300005][5];
int ck[300005][5];
int t,cs;
ll a[300005];
ll b[300005];
ll inf = 1e18+7;
int n;

ll calc(int u,int o)
{
    if(u==n+1)
        return 0 ;
    if(ck[u][o]==cs)
        return dp[u][o];
    ck[u][o] = cs ;
    ll ret = inf;
    for(int i=0; i<3; i++)
    {
        if(a[u-1]+o!=a[u]+i)
            ret=min(ret,b[u]*i+calc(u+1,i));
    }
    return dp[u][o]= ret ;
}

int main()
{
    cout << log10(1LL << 60);
}
