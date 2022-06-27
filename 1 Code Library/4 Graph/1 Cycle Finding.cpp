ll n;
vector<ll> adj[MAXN];
ll color[MAXN], parent[MAXN];
ll cycle_start, cycle_end;

bool dfs(ll cur, ll p)
{
    parent[cur] = p;
    color[cur] = 1;

    for (ll nxt : adj[cur])
    {
        if (color[nxt] == 0)
        {
            if (dfs(nxt, cur))
                return true;
        }
        else if (color[nxt] == 1)
        {
            cycle_end = cur;
            cycle_start = nxt;
            return true;
        }
    }
    color[cur] = 2;
    return false;
}

void find_cycle()
{
    fill(color, color+n, 0);
    fill(parent, parent+n, -1);
    cycle_start = -1;

    ll i;

    for (i = 0; i < n; i++)
    {
        if (color[i] == 0 && dfs(i, -1))
            break;
    }

    if (cycle_start == -1)
        cout << "Acyclic" << "\n";
    else
    {
        vector<ll> cycle;
        cycle.push_back(cycle_start);
        for (ll v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (ll v : cycle)
            cout << v << " ";
        cout << "\n";
    }
}
