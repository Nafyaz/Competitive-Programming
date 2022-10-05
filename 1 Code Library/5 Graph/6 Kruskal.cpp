LL leader[MAXN], n, m;
vector<pair<LL, pLL>>>edges;

LL Find(LL a)
{
    if(leader[a] == a)
        return a;
    leader[a] = Find(leader[a]);
    return leader[a];
}

void Union(LL a, LL b)
{
    a = Find(a);
    b = Find(b);

    leader[max(a, b)] = min(a, b);
}

LL kruskal()
{
    LL i, ret = 0;
    for(i = 1; i <= n; i++)
        leader[i] = i;

    sort(edges.begin(), edges.end());
    LL cnt = 0;
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
