#include<bits/stdc++.h>
using namespace std;

int i, j, a[100010], tree[400040];

void build(int s, int e, int node)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    int left = 2*node;
    int right = 2*node + 1;
    int mid = (s+e)/2;

    build(s, mid, left);
    build(mid+1, e, right);

    tree[node] = min(tree[left], tree[right]);
}

int query(int s, int e, int node)
{
    if(s > j || e < i)
        return INT_MAX;
    if(s >= i && e <= j)
        return tree[node];

    int left = 2*node;
    int right = 2*node + 1;
    int mid = (s+e)/2;

    int p1 = query(s, mid, left);
    int p2 = query(mid+1, e, right);
    return min(p1, p2);
}

int main()
{
    int T, n, q, caseno = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &q);
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        build(1, n, 1);
        printf("Case %d:\n", ++caseno);
        while(q--)
        {
            scanf("%d %d", &i, &j);
            printf("%d\n", query(1, n, 1));
        }
    }
}
