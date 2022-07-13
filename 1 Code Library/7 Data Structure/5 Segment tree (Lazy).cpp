// Node e dhukar sathe sathe lazy clear kora lagbe.
// Shei node amar desired range er vitore thakuk, othoba na thakuk.
// Naile WA khabi sure.
ll arr[MAXN];
ll Tree[4*MAXN], Lazy[4*MAXN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Lazy[node] = 0;
        Tree[node] = arr[bg];
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
    Lazy[node] = 0;
}

void updateRange(ll node, ll bg, ll ed, ll l, ll r, ll val)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += (ed - bg + 1) * Lazy[node];
        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return;

    if(l <= bg && ed <= r)
    {
        Tree[node] += (ed - bg + 1) * val;
        if(bg != ed)
        {
            Lazy[leftNode] += val;
            Lazy[rightNode] += val;
        }
        return;
    }

    updateRange(leftNode, bg, mid, l, r, val);
    updateRange(rightNode, mid+1, ed, l, r, val);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

ll queryRange(ll node, ll bg, ll ed, ll l, ll r)
{    
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += (ed - bg + 1) * Lazy[node];
        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return 0;

    if(l <= bg && ed <= r)
        return Tree[node];

    ll p1 = queryRange(leftNode, bg, mid, l, r);
    ll p2 = queryRange(rightNode, mid + 1, ed, l, r);
    
    return (p1 + p2);
}