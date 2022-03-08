#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int Tree[800005];

int build(int node, int s, int e)
{
    if(s == e)
        return Tree[node] = a[s];

    int mid = (s+e)/2;
    int p = build(2*node+1, s, mid);
    int q = build(2*node+2, mid+1, e);

    return Tree[node] = max(p, q);
}

int update(int node, int s, int e, int pos, int val)
{
    if(s == e)
    {
        a[pos] = val;
        return Tree[node] = val;
    }

    int mid = (s+e)/2, p, q;

    if(pos <= mid)
    {
        p = update(2*node+1, s, mid, pos, val);
        q = Tree[2*node+2];
    }
    else
    {
        p = Tree[2*node+1];
        q = update(2*node+2, mid+1, e, pos, val);
    }

    return Tree[node] = max(p, q);
}

int query(int node, int s, int e, int l, int r)
{
    if(l > e || r < s)
        return -1;

    if(l <= s && e <= r)
        return Tree[node];

    int mid = (s+e)/2, p, q;

    p = query(2*node+1, s, mid, l, r);
    q = query(2*node+2, mid+1, e, l, r);

    return max(p, q);
}

int findClosestMaxIdx(int l, int r, int val)
{
    if(l > r)
        return -1;
    if(l == r)
    {
        if(a[l] > val)
            return l;
        else
            return -1;
    }

    int mid = (l+r)/2;
    int p = query(0, 0, n-1, l, mid);
    int q = query(0, 0, n-1, mid+1, r);

    if(p > val)
        return findClosestMaxIdx(l, mid, val);
    if(q > val)
        return findClosestMaxIdx(mid+1, r, val);
    else
        return -1;

}

int main()
{
    int i, j, val;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(0, 0, n-1);

    for(i = 0; i < n; i++)
    {
        if(a[i] == -1)
            continue;

        for(j = i; j < n && j != -1; j = findClosestMaxIdx(j+1, n-1, val))
        {
            cout << a[j] << " ";
            val = a[j];
            update(0, 0, n-1, j, -1);
        }

        cout << "\n";
    }
}
