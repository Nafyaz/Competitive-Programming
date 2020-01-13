#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int n, a[30009], tre[120009];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tre[node] = a[s];
        return;
    }

    int mid = (s+e)>>1, left = node<<1, right = left+1;

    build(left, s, mid);
    build(right, mid+1, e);

    tre[node] = min(tre[left], tre[right]);
}

int query(int node, int s, int e, int i, int j)
{
    if(j < s || i > e)
        return INT_MAX;
    if(i <= s && e <= j)
        return tre[node];

    int mid = (s+e)>>1, left = node<<1, right = left+1;

    int p1 = query(left, s, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return min(p1, p2);
}

int main()
{
        freopen("out.txt", "w", stdout);

    int t, caseno = 0, i, x, mx, l, r;

    scanf("%d", &t);

    while(t--)
    {
        mx = 0;
        scanf("%d", &n);

        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        build(1, 1, n);

//        cout << query(1, 1, n, 3, 4);
//        for(i = 1; i <= 15; i++)
//            cout << tre[i] << " ";
        int p, q, mid, mn;
        for(i = 1; i <= n; i++)
        {
            l = i;

            p = 1, q = i-1;
            while(p <= q)
            {
                mid = (p+q)>>1;
                mn = query(1, 1, n, mid, i-1);

                if(mn < a[i])
                    p = mid+1;
                else
                {
                    l = mid;
                    q = mid - 1;
                }
            }

            r = i;

            p = i+1, q = n;
            while(p <= q)
            {

                mid = (p+q)>>1;
                mn = query(1, 1, n, i+1, mid);

//                if(i == 3)
//                    cout << p << " " << q << " " << mn << endl;
                if(mn < a[i])
                    q = mid-1;
                else
                {
                    r = mid;
                    p = mid+1;
                }
            }

            x = a[i] + a[i]*(i-l) + a[i]*(r-i);
//            if(i == 3)
//                cout << l << " " << r << " " << x << endl;
            mx = max(x, mx);
        }

        printf("Case %d: %d\n", ++caseno, mx);
    }
}

