vector<int> adj[MAX];
stack<int> st;
int col[MAX];

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

//Run it for all nodes
for(i = 1; i <= node; i++)
{
    if(col[i] == 0 && dfs(i) == 0)
    {
        cout << "impossible";
        return 0;
    }
}
