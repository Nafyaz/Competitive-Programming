ll arr[MAXN];
ll Tree[4*MAXN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node] = arr[bg];
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

void Update(ll node, ll bg, ll ed, ll idx, ll val)
{
    if(bg == ed)
    {
        Tree[node] = val;
        arr[idx] = val;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

ll Query(ll node, ll bg, ll ed, ll l, ll r)
{
    if(bg > r || ed < l)
        return 0;

    if(l <= bg && ed <= r)
        return Tree[node];

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    ll p1 = Query(leftNode, bg, mid, l, r);
    ll p2 = Query(rightNode, mid+1, ed, l, r);

    return p1 + p2;
}