#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, a[200009], vis[200009], dis[200009], clen;

ll dfs(ll s, ll d)
{
    if(vis[s])
    {
        clen = d - dis[s];
        return s;
    }

    vis[s] = 1;
    dis[s] = d;
    return dfs(a[s], d+1);
}

int main()
{
    ll i, s;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> a[i];

    s = dfs(1, 0);

    if(k < dis[s])
    {
        s = 1;
        while(k--)
            s = a[s];
    }

    else
    {
        k = (k - dis[s])%clen;

        while(k--)
            s = a[s];
    }

    cout << s;
}
