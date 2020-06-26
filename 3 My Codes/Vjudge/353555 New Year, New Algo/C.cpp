#include<bits/stdc++.h>
using namespace std;

int n, a[100009], diff[100009], sparse[100009][20];

int find_high(int l, int r)
{
    int k = log2(r-l+1);
    return max(sparse[l][k], sparse[r-(1<<k)+1][k]);
}

int main()
{
    int i, j, d, t, k;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i > 0)
            diff[i-1] = a[i] - a[i-1];
    }

    for(i = 0; i < n; i++)
        sparse[i][0] = diff[i];

    for(j = 1; (1 << j) <= n; j++)
    {
        for(i = 0; i + (1 << j) - 1 < n; i++)
        {
            sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
        }
    }

    int q, low, high, mid, ans;
    cin >> q;

//    while(q--)
//    {
//        cin >> d >> t;
//        cout << find_high(d, t) << endl;
//    }

    while(q--)
    {
        cin >> t >> d;
        k = lower_bound(a, a+n, t+1) - a - 1;

        if(k == 0)
        {
            cout << 1 << endl;
            continue;
        }

        k--;
        low = 0, high = k;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(find_high(mid, k) > d)
            {
                if(low == k)
                    ans = mid+1;
                low = mid+1;
            }
            else
            {
                high = mid-1;
                ans = mid;
            }
        }

        cout << ans + 1<< endl;
    }
}
