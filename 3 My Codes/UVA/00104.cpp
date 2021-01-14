#include<bits/stdc++.h>
using namespace std;
#define N 25

double dp[N][N][N],p[N][N][N];
int n;

void print_path(int i,int j, int s)
{
    if(s==0)
    {
        cout << i;
        return;
    }

    print_path(i, p[i][j][s],s-1);
    cout << " " << j;

    return;
}
void DP()
{
    int s, m, i, j, k;
    for(s=2; s<=n; s++)
    {
        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if( dp[i][j][s] < dp[i][k][s-1]*dp[k][j][1])
                    {
                        dp[i][j][s]=dp[i][k][s-1]*dp[k][j][1];
                        p[i][j][s]=k;
                    }
                }
            }
        }

        for(i=1; i<=n; i++)
        {
            if(dp[i][i][s]>1.01)
            {
                m = i;
                break;
            }
            if(i<=n)
                break;
        }
    }

    if(s>n)
        printf("no arbitrage sequence exists");
    else
        print_path(m, m, s);

    printf("\n");
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    dp[i][j][1]=1;
                else
                    scanf("%lf",&dp[i][j][1]);
                p[i][j][1]=j;
            }
        DP();
    }
    return 0;
}
