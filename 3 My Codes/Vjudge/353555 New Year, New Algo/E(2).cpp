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

ll n, a[100009], sparse[100009][20], Log[100009];

int main()
{
    ll i, j, l, r, mx, x;

    for(i = 2; i < 100009; i++)
        Log[i] = Log[i>>1] + 1;

    while(1)
    {
        mx = INT_MIN;
        cin >> n;

        if(n == 0)
            break;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            sparse[i][0] = a[i];
        }

        for(j = 1; (1<<j) <= n; j++)
        {
            for(i = 0; i + (1<<j) - 1 <= n; i++)
                sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
        }

        ll p, q, mid, mn, k;
        for(i = 1; i <= n; i++)
        {
            l = i;

            p = 1, q = i-1;
            while(p <= q)
            {
                mid = (p+q)>>1;
                k = Log[i - mid];
                mn = min(sparse[mid][k], sparse[i - (1<<k)][k]);
//                cout << mn << endl;

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

                k = Log[mid - i];
                mn = min(sparse[i+1][k], sparse[mid - (1<<k) +1][k]);

                if(mn < a[i])
                    q = mid-1;
                else
                {
                    r = mid;
                    p = mid+1;
                }
            }

            x = a[i] + a[i]*(i-l) + a[i]*(r-i);
            mx = max(x, mx);
        }

        cout << mx << endl;
    }
}
