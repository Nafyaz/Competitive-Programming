#include<bits/stdc++.h>
using namespace std;

long long lazy[400010], tree[400010];

void update(long long node, long long s, long long e, long long l, long long r, long long v)
{
    if(s > r || e < l)
        return;

    if(lazy[node] != 0)
    {
        tree[node] += (e - s + 1) * lazy[node];

        if(s != e)
        {
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }

        lazy[node] = 0;
    }
    if(s >= l && e <= r)
    {
        tree[node] += (e - s + 1) * v;
        if(s != e)
        {
            lazy[2*node + 1] += v;
            lazy[2*node + 2] += v;
        }
        return;
    }

    long long mid = (s+e)/2;
    update(2*node + 1, s, mid, l, r, v);
    update(2*node + 2, mid+1, e, l, r, v);
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

long long query(long long node, long long s, long long e, long long l, long long r)
{
    if(s > r || e < l)
        return 0;

    if(lazy[node] != 0)
    {
        tree[node] += (e - s + 1) * lazy[node];

        if(s != e)
        {
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(s >= l && e <= r)
        return tree[node];

    long long mid = (s+e)/2;
    long long p1 = query(2*node + 1, s, mid, l, r);
    long long p2 = query(2*node + 2, mid+1, e, l, r);

    return p1 + p2;
}

int main()
{
    freopen("out.txt", "w", stdout);
    long long T, caseno = 0, n, q, i, p, x, y, v;
    scanf("%lld", &T);
    while(T--)
    {
        memset(lazy, 0, sizeof(lazy));
        memset(tree, 0, sizeof(tree));

        scanf("%lld %lld", &n, &q);
        printf("Case %lld:\n", ++caseno);
        while(q--)
        {
            scanf("%lld", &p);
            if(p == 0)
            {
                scanf("%lld %lld %lld", &x, &y, &v);
                update(0, 0, n-1, x, y, v);
            }
            else
            {
                scanf("%lld %lld", &x, &y);
                printf("%lld\n", query(0, 0, n-1, x, y));
            }

            long long j = 0;
            for(i = 0; i < 25; i++)
            {

                printf("%lld %lld %lld, ", i, lazy[i], tree[i]);
//                if(i == j)
//                {
//                    printf("\n");
//                    j = 2*j + 2;
//                }
            }
            printf("\n");
        }
    }
}
