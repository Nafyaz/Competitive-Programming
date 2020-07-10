#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, f;
vector<ll> fr;
ll dis[109][109];

ll solve()
{
    ll i, j, k;
    cin >> n >> m >> f;

    fr.clear();
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INT_MAX;
        }
    }

    for(i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = c;
        dis[b][a] = c;
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }

    for(i = 0; i < f; i++)
    {
        ll x;
        cin >> x;
        fr.push_back(x);
    }

    sort(fr.begin(), fr.end());

    ll ans = INT_MAX, x;
    do
    {
        x = 0;
        i = 1;
        for(auto u : fr)
        {
            x += dis[i][u];
            i = u;
        }
        x += dis[i][n];

        ans = min(ans, x);

    }while(next_permutation(fr.begin(), fr.end()));

    return ans;
}

int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--)
        cout << "Case " << ++caseno << ": " << solve() << endl;
}
