#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> adj[27];
ll dis[27][27];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("A2_input.txt", "r", stdin);
    freopen("A2_output.txt", "w", stdout);

    ll t, caseno = 0, i, j, k, ans, cost;
    char a, b;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s >> k;

        for(i = 0; i < 26; i++)
        {
            adj[i].clear();
            for(j = 0; j < 26; j++)
                dis[i][j] = INT_MAX;
        }

        for(i = 0; i < 26; i++)
            dis[i][i] = 0;

        while(k--)
        {
            cin >> a >> b;

            adj[a - 'A'].push_back(b - 'A');

            dis[a - 'A'][b - 'A'] = 1;
        }

        for(k = 0; k < 26; k++)
        {
            for(i = 0; i < 26; i++)
            {
                for(j = 0; j < 26; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        ans = INT_MAX;
        bool flag;

        for(i = 0; i < 26; i++)
        {
            flag = 1;
            cost = 0;
            for(auto u : s)
            {
                if(dis[u-'A'][i] == INT_MAX)
                {
                    flag = 0;
                    break;
                }

                cost += dis[u-'A'][i];
            }

            if(flag)
                ans = min(ans, cost);
        }

        if(ans != INT_MAX)
            cout << "Case #" << ++caseno << ": " << ans << "\n";
        else
            cout << "Case #" << ++caseno << ": " << -1 << "\n";
    }
}
