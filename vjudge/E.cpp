#include<bits/stdc++.h>
using namespace std;
long long tree[400010], a[100010];
long long z, p;
long long x, y;

void build(long long s, long long e, long long node)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    long long left = 2*node + 1, right = 2*node + 2;
    build(s, (s+e)/2, left);
    build((s+e)/2+1, e, right);

    tree[node] = tree[left] + tree[right];
}

void update(long long s, long long e, long long node)
{
    if(s == y && e == y)
    {
        p = tree[node];
        tree[node] = z;
        a[y] = z;
        return;
    }

    long long left = 2*node + 1, right = 2*node + 2;
    if(y <= (s+e)/2)
        update(s, (s+e)/2, left);
    else
        update((s+e)/2+1, e, right);

    tree[node] = tree[left] + tree[right];
}

long long query(long long s, long long e, long long node)
{
    if(s >= x && e <= y)
        return tree[node];
    else if(s > y || e < x)
        return 0;

    long long left = 2*node + 1;
    long long right = 2*node + 2;
    long long mid = (s+e)/2;

    long long p1 = query(s, mid, left);
    long long p2 = query(mid+1, e, right);

    return p1+p2;
}

int main()
{
    //freopen("out.txt","w",stdout);
    long long T, i, n, caseno = 0, q;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld %lld", &n, &q);
        for(i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        build(0, n-1, 0);

        printf("Case %lld:\n", ++caseno);
        while(q--)
        {
            scanf("%lld", &x);
            if(x == 1)
            {
                scanf("%lld", &y);
                z = 0;
                update(0, n-1, 0);
                printf("%lld\n", p);
            }
            else if(x == 2)
            {
                scanf("%lld %lld", &y, &z);
                z = z + a[y];
                update(0, n-1, 0);
            }
            else
            {
                scanf("%lld %lld", &x, &y);
                printf("%lld\n", query(0, n-1, 0));
            }

//            for(i = 0; i < 4*n; i++)
//                cout << a[i] << " ";
//            cout << endl;
        }
    }
}
