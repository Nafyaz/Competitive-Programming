int Find(int x) 
{
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    parent[max(x, y)] = min(x, y);
}