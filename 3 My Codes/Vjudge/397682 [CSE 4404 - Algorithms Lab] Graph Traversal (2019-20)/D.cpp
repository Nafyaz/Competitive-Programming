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

vector<int> adj[109];
int visited[109];
stack<int> st;

void dfs(int s)
{
    visited[s] = 1;
    for(auto u : adj[s])
    {
        if(!visited[u])
            dfs(u);
    }

    st.push(s);
}

int main()
{
    int m, n, i, x, y;
    while(cin >> n >> m)
    {
        if(!n && !m)
            return 0;

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = 0;
        }

        for(i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x].pb(y);
        }

        for(i = 1; i <= n; i++)
        {
            if(!visited[i])
                dfs(i);
        }

        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        cout << "\n";
    }
}
