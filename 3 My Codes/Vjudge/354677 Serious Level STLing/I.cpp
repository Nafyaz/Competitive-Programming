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
    int t, n, c, i, stall[100009];
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        for(i = 0; i < n; i++)
            cin >> stall[i];
        sort(stall, stall+n);
        int mndiff, tempc, low, high, mid, midans, diff, mndiffans;
        low = stall[0];
        high = stall[n-1];
        while(low <= high)
        {
            mid = (low+high)>>1;
//            cout << mid << endl;
            mndiff = INT_MAX;
            tempc = c-1;
            diff = 0;
            for(i = 1; i < n; i++)
            {
                diff += stall[i] - stall[i-1];
                if(diff >= mid)
                {
                    mndiff = min(mndiff, diff);
                    diff = 0;
                    tempc--;
                    if(!tempc)
                        break;
                }
            }

            if(i < n)
            {
                mndiffans = mndiff;
                midans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }

        cout << mndiffans << endl;
    }
}
