#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

ll adjM[109][109], dp[109][109][109];
vector<pair<ll, ll>> adjL[109];

ll call(ll i, ll j, ll step)
{
    if(step == 0)
    {
        if(adjM[i][j] == -1)
            return dp[i][j][step] = INT_MAX;
        else
            return dp[i][j][step] = adjM[i][j];
    }

    if(dp[i][j][step] != -1)
        return dp[i][j][step];

    dp[i][j][step] = call(i, j, 0);
    for(auto p : adjL[i])
    {
        ll u = p.ss;
        ll cost = p.ff;
        dp[i][j][step] = min(dp[i][j][step], cost + call(u, j, step - 1));
    }

    return dp[i][j][step];
}

int main()
{
    ll t, caseno = 0, i, n, m, u, v, w, q, step, ans;
    string us, vs;
    map<string, ll> mp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        mp.clear();
        memset(adjM, -1, sizeof adjM);
        memset(dp, -1, sizeof dp);
        for(i = 0; i < n; i++)
        {
            cin >> us;
            mp[us] = i;
            adjL[i].clear();
        }

        cin >> m;
        for(i = 0; i < m; i++)
        {
            cin >> us >> vs >> w;

            u = mp[us];
            v = mp[vs];

            adjL[u].pb({w, v});

            if(adjM[u][v] == -1)
                adjM[u][v] = w;
            else
                adjM[u][v] = min(adjM[u][v], w);
        }

        if(caseno != 0)
            cout << "\n";
        cout << "Scenario #" << ++caseno << "\n";
        cin >> q;
        while(q--)
        {
            cin >> step;
            step = min(step, 108LL);
            ans = call(0, n-1, step);
            if(ans == INT_MAX)
                cout << "No satisfactory flights\n";
            else
                cout << "Total cost of flight(s) is $" << ans << "\n";
        }
    }
}
