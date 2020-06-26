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

int n, m, v[1009] = {0}, pre[1009] = {0};

bool binsearch(int csize)
{
    int st = 0, ed = 0, total, cnt = 0;
    while(st <= n)
    {
        while(ed <= n && pre[ed] - pre[st] <= csize)
        {
            ed++;
        }
        st = ed;
        cnt++;
    }

    return cnt <= csize;
}

int main()
{
    int t, caseno, i, mx, mn;
    cin >> t;
    while(t--)
    {
        mx = INT_MIN;
        mn = INT_MAX;

        cin >> n >> m;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            pre[i] = pre[i-1] + v[i];
            mx = max(mx, v[i]);
        }

        int low = mx, high = pre[n], mid;

        while(low <= high)
        {
            mid = (low + high)/2;
            if(binsearch(mid))
            {
                low = mid+1;
                mn = min(mn, mid);
            }
            else
                high = mid-1;
        }

        printf("Case %d: %d\n", ++caseno, mn);
    }
}
