ll root[MAXN];

int Find(int x) 
{
    if (x == root[x])
        return x;
    return root[x] = find_set(root[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    root[max(x, y)] = min(x, y);
}