#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

string grid[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, m, i, j;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i < n; i++)
            cin >> grid[i];

        if(grid[0][0] == '1')
        {
            cout << "-1\n";
            continue;
        }

        stack<pair<pair<ll, ll>, pair<ll, ll>>> ans;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    if(i > 0)
                        ans.push({{i-1, j}, {i, j}});
                    else
                        ans.push({{i, j-1}, {i, j}});
                }
            }
        }

        cout << ans.size() << "\n";
        while(!ans.empty())
        {
            cout << ans.top().ff.ff+1 << " " << ans.top().ff.ss+1 << " " << ans.top().ss.ff+1 << " " << ans.top().ss.ss+1 << "\n";
            ans.pop();
        }
    }
}
