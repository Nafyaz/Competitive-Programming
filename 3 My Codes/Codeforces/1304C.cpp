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
//    freopen("out.txt", "r", stdin);
    ll q, n, m, low, high, clow, chigh, i, t, prevt, flag;
    cin >> q;
    while(q--)
    {
        flag = 1;
        cin >> n >> m;
        low = high = m;
        prevt = 0;
        for(i = 0; i < n; i++)
        {
            cin >> t >> clow >> chigh;
            low -= t - prevt;
            high += t - prevt;
            prevt = t;

            if(low > chigh || high < clow)
            {
                flag = 0;
//                break;
            }

            low = max(low, clow);
            high = min(high, chigh);
//            cout << low << " " << high << endl;
        }

        cout << (flag? "YES" : "NO") << endl;
    }
}
