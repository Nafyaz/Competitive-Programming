//Now this is something good.
//solved it using disjoint set union :D
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int pr[1000000];

int f(int x)
{
    return pr[x] == x? x : pr[x] = f(pr[x]);
}
int main()
{
    int n, m, i, a, b, u, v, x;
    scanf("%d %d", &n, &m);
    int gold[n+1];
    for(i = 1; i <= n; i++)
        scanf("%d", &gold[i]);

    for(i = 1; i <= n; i++)
        pr[i] = i;
    while(m--)
    {
        scanf("%d %d", &a, &b);
        u = f(a);
        v = f(b);
        if(gold[u] < gold[v])
            pr[v] = u;
        else
            pr[u] = v;
    }
    ll ans = 0;
    bool vis[n+1];
    for(i = 1; i <= n; i++)
        vis[i] = 0;

    for(i = 1; i <= n; i++)
    {
        x = f(i);
        if( !vis[x] )
        {
            vis[x] = 1;
            ans += gold[x];
        }
    }
    printf("%lld", ans);
}
