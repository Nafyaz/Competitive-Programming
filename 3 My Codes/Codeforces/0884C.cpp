#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, p[100009];
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> p[i];

    ll vis[100009] = {0};
    vector<ll> csize;

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            ll x = i, cnt = 1;
            vis[x] = 1;
            while(p[x] != i)
            {
                x = p[x];
                vis[x] = 1;
                cnt++;
            }

            csize.push_back(cnt);
        }
    }

    if(csize.size() == 1)
    {
        cout << n*n;
        return 0;
    }

    sort(csize.begin(), csize.end(), greater<ll>());
    ll ans = (csize[0] + csize[1]) * (csize[0] + csize[1]);

    for(i = 2; i < csize.size(); i++)
        ans += csize[i]*csize[i];

    cout << ans;
}
