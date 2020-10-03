/*
Check and remove this section while coding
1. Get rid of toolbars except compiler and main. Enable only logs and status.
2. Use C++17 in global compiler settings.
3. Turn on Wall, Wextra, Wshadow in warnings.
4. Make tab spout 4 spaces
*/

/*
ID: nafis.f1
TASK:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second
#define pb push_back

int adj[50009];
int visited[50009], len[50009], cyclen[50009];

int dfs(int s)
{
    if(visited[s] && len[s])
        return len[s];
    else if(visited[s])
    {
        int c = 0, t = s;
        while()
    }

    visited[s] = 1;

    return 1 + dfs(adj[s]);
}

int main()
{
    int t, caseno = 0, n, i, x, y, mx, cnt, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = 0;
            len[i] = 0;
        }

        for(i = 0; i < n; i++)
        {
            cin >> x >> y;
            adj[x].pb(y);
        }

        mx = 0;
        for(i = 1; i <= n; i++)
        {
            cnt = dfs(i);
            cout << i << " " <<  cnt << endl;
            if(mx < cnt)
            {
                mx = cnt;
                ans = i;
            }

        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}

