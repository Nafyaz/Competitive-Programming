#include<bits/stdc++.h>
using namespace std;

int sparse[100009][21], Log[100009];

int main()
{
    int n, m, i, j, a[100009];

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];
    a[n] = INT_MAX;

    int diff[100009];
    for(i = 0; i < n; i++)
    {
        diff[i] = a[i+1] - a[i];
        sparse[i][0] = diff[i];
    }

    for(i = 2; i < 100009; i++)
        Log[i] = Log[i>>1] + 1;

    for(j = 1; j <= Log[n] + 1; j++)
    {
        for(i = 0; i+ (1<<(j-1)) < n; i++)
        {
            sparse[i][j] = max(sparse[i][j-1], sparse[i+ (1<<(j-1))][j-1]);
        }
    }

    int t, d, pos, l, r, mid, x, y, k, mx, ans;
    cin >> m;
    while(m--)
    {
        cin >> t >> d;
        pos = upper_bound(a, a+n, t) - a;
        pos--;
//        cout << "pos: " << pos << endl;
        l = 0, r = pos-1, ans = pos;
        while(l <= r)
        {
            mid = (l+r)/2;
            x = mid, y = pos-1;
            k = Log[y-x+1];
//            cout << x << " " << y << " " << k << "|||";
            mx = max(sparse[x][k], sparse[y-(1<<k)+1][k]);
//            cout << l << " " << r << " " << mid << " " << mx << endl;
            if(mx > d)
                l = mid+1;
            else
            {
                ans = mid;
                r = mid-1;
            }
        }

        cout << ans+1 << endl;
    }
}
