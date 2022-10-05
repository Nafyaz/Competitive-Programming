LL arr[MAXN];
LL Tree[4*MAXN];

void Build(LL node, LL bg, LL ed)
{
    if(bg == ed)
    {
        Tree[node] = arr[bg];
        return;
    }

    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

void Update(LL node, LL bg, LL ed, LL idx, LL val)
{
    if(bg == ed)
    {
        Tree[node] = val;
        arr[idx] = val;
        return;
    }

    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

LL Query(LL node, LL bg, LL ed, LL l, LL r)
{
    if(bg > r || ed < l)
        return 0;

    if(l <= bg && ed <= r)
        return Tree[node];

    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

    LL p1 = Query(leftNode, bg, mid, l, r);
    LL p2 = Query(rightNode, mid+1, ed, l, r);

    return p1 + p2;
}
