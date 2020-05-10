#include<bits/stdc++.h>
using namespace std;

int i, j, val, a[100] = {1, 2, 3, 4, 5};
int tree[4*100];

void build(int s, int e, int node)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    int left = 2*node + 1;
    int right = 2*node + 2;
    int mid = (s+e)/2;

    build(s, mid, left);
    build(mid+1, e, right);

    tree[node] = tree[left] + tree[right];
}

int query(int s, int e, int node)
{
    if(s >= i && e <= j)
        return tree[node];
    else if(s > j || e < i)
        return 0;

    int left = 2*node + 1;
    int right = 2*node + 2;
    int mid = (s+e)/2;

    int p1 = query(s, mid, left);
    int p2 = query(mid+1, e, right);

    return p1+p2;
}

void update(int s, int e, int node)
{
    if(s >= i && e <= i)
    {
        tree[node] = val;
        return;
    }

    printf("%d\n", node);

    int left = 2*node + 1;
    int right = 2*node + 2;
    int mid = (s+e)/2;

    if(i <= mid)
        update(s, mid, left);
    else
        update(mid+1, e, right);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    int x;
    build(0, 4, 0);
    while(1)
    {
        scanf("%d", &x);
        if(x == 1)
        {
            scanf("%d %d", &i, &j);
            printf("%d\n", query(0, 4, 0));
        }
        else
        {
            scanf("%d %d", &i, &val);
            update(0, 4, 0);
        }
    }
}
