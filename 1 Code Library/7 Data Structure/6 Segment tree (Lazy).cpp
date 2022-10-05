// Node e dhukar sathe sathe lazy clear kora lagbe.
// Shei node amar desired range er vitore thakuk, othoba na thakuk.
// Naile WA khabi sure.
LL arr[MAXN];
LL Tree[4*MAXN], Lazy[4*MAXN];

void Build(LL node, LL bg, LL ed)
{
    if(bg == ed)
    {
        Lazy[node] = 0;
        Tree[node] = arr[bg];
        return;
    }

    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
    Lazy[node] = 0;
}

void updateRange(LL node, LL bg, LL ed, LL l, LL r, LL val)
{
    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

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

LL queryRange(LL node, LL bg, LL ed, LL l, LL r)
{
    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

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

    LL p1 = queryRange(leftNode, bg, mid, l, r);
    LL p2 = queryRange(rightNode, mid + 1, ed, l, r);

    return (p1 + p2);
}
