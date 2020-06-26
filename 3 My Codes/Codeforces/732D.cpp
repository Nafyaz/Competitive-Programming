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

int d[100009], a[100009], n, m;

bool check(int mid)
{
    int i;
    vector<pair<int, int> > lastdate(m+1);
    for(i = 1; i <= m; i++)
    {
        lastdate[i].ff = -1;
        lastdate[i].ss = a[i];
    }

    for(i = 0; i <= mid; i++)
    {
        if(d[i] != 0)
            lastdate[d[i]].ff = max(lastdate[d[i]].ff, i);
    }
    for(i = 1; i <= m; i++)
    {
        if(lastdate[i].ff == -1)
            return 0;
    }

    sort(lastdate.begin() + 1, lastdate.begin() + m+1);
//    for(i = 1; i <= m; i++)
//        cout << lastdate[i].ff << " " << lastdate[i].ss << endl;

    int used = 0;

    for(i = 1; i <= m; i++)
    {
        if(used + lastdate[i].ss > lastdate[i].ff)
            return 0;
        used += lastdate[i].ss + 1;
    }

    return 1;
}

int main()
{
    int i;
    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> d[i];
    for(i = 1; i <= m; i++)
        cin >> a[i];

    int low = 0, high = n-1, mid, ans = -2;

//    cout << endl << "check: " << check(4) << endl;

    while(low <= high)
    {
        mid = (low + high)>>1;
//        cout << mid << " ";
        if(check(mid))
        {
            high = mid-1;
            ans = mid;
        }
        else
            low = mid+1;
    }

    cout << ans+1;
}
