ll root[MAXN], n, m;
vector<pair<ll, pll>>>edges;

ll Find(ll a)
{
    if(root[a] == a)
        return a;
    root[a] = Find(root[a]);
    return root[a];
}

void Union(ll a, ll b)
{
    a = Find(a);
    b = Find(b);

    root[max(a, b)] = min(a, b);
}

ll kruskal()
{
    ll i, ret = 0;
    for(i = 1; i <= n; i++)
        root[i] = i;

    sort(edges.begin(), edges.end());
    ll cnt = 0;
    for(auto [c, e] : edge)
    {
        [a, b] = e;

        if(Find(a) != Find(b))
        {
            Union(a, b);
            ret += c;
            cnt++;
            if(cnt == n-1)
                return ret;
        }
    }

    return -1;
}