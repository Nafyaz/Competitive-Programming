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

int main()
{
    int t, n, i, a[100009], low, high, mid1, mid2, mxdiff1, mxdiff2, p, q, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        low = 0;
        high = 1000000001;

        while(low <= high)
        {
            mid1 = low + (high - low)/3;
            mid2 = high - (high - low)/3;

            mxdiff1 = -1;
            mxdiff2 = -1;
            for(i = 0; i < n-1; i++)
            {
                p = a[i];
                q = a[i+1];
                if(a[i] == -1)
                    p = mid1;
                if(a[i+1] == -1)
                    q = mid1;
                mxdiff1 = max(mxdiff1, abs(p - q));

                if(a[i] == -1)
                    p = mid2;
                if(a[i+1] == -1)
                    q = mid2;
                mxdiff2 = max(mxdiff2, abs(p - q));
            }

            if(mxdiff1 < mxdiff2)
                high = mid2 - 1;
            else if(mxdiff1 > mxdiff2)
                low = mid1 + 1;
            else
            {
                low = mid1 + 1;
                high = mid2 - 1;
            }

            ans = (low + high)/2;
        }


        int mxdiff = -1;
        for(i = 0; i < n-1; i++)
        {
             p = a[i];
            q = a[i+1];
            if(a[i] == -1)
                p = ans;
            if(a[i+1] == -1)
                q = ans;
            mxdiff = max(mxdiff, abs(p - q));
        }

        cout << mxdiff << " " << ans << endl;
    }
}
