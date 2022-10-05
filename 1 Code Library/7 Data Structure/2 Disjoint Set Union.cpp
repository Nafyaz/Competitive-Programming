LL leader[MAXN];

LL Find(LL x)
{
    if (x == leader[x])
        return x;
    return leader[x] = find_set(leader[x]);
}

void Union(LL x, LL y) {
    x = Find(x);
    y = Find(y);

    leader[max(x, y)] = min(x, y);
}
