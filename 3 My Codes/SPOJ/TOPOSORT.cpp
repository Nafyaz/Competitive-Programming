#include<bits/stdc++.h>
using namespace std;

const int N=10005;
vector<int>adj[N];
stack<int>st;
int col[N];

bool dfs(int s)
{
    int ret = 1;
    col[s] = 1;
    for(auto u : adj[s])
    {
        if(col[u] == 0)
            ret = ret & dfs(u);
        else if(col[u] == 1)
            return 0;
    }
    col[s] = 2;
    st.push(s);
    return ret;
}

int main()
{
    int i, node, edge;
    cin >> node >> edge;
    for(i = 1; i <= edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(i = 1; i <= node; i++)
        sort(adj[i].begin(), adj[i].end(), greater<int>());

    for(i = node; i >= 1; i--)
    {
        if(col[i] == 0 && dfs(i) == 0)
        {
            cout << "Sandro fails.";
            return 0;
        }
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
