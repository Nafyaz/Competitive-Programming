#include <bits/stdc++.h>
using namespace std;
#define mx 1000006

ll mobius[mx];
bool vis[mx];
ll n, m;

void precal()
{
    for(int i = 2; i < mx;)
    {
        for(int j = i + i; j < mx; j += i)
            mobius[j]++;
        for(++i ; ; i++)
        {
            if(mobius[i] == 0)
                break;
        }
    }

    for(int i = 2; i < mx; i++)
    {
        if(mobius[i]==1)
        {
            for(int j=i; j<mx; j+=i)
                vis[j]=1;
        }
    }

}

int main()
{
    ll t, i;
    cin >> t
    precal();
    while(t--)
    {
        cin >> n >> m;
        if(n > m)
            swap(n, m);

        ll ans = n*m;

        for(i = 2; i <= n; i++)
        {
            if(vis[i] == 1)
                continue;
            ll x = (m/i)*(n/i);
            if(mobius[i]==0)
                ans-=x;
            else if(mobius[i]%2==1)
                ans-=x;
            else
                ans+=x;
        }

        if(n) ans++;
        if(m) ans++;
        PRINT_CASE;
        printf("%lld\n",ans);

    }

    return 0;
}
