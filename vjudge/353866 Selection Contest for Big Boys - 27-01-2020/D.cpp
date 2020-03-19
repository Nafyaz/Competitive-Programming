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

ll n, t[100009];

int main()
{
    ll i, m, ans = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> t[i];
    sort(t, t+n);

    if(n == 1)
    {
        cout << t[0];
        return 0;
    }

    int flag = 1, nowmax = n-1;
    bitset<100009> left;
    left.set();
    left >>= 100009 - n;
    while(left.any())
    {
//        cout << ans << " " << left << " " << flag << endl;
        if((left >> 3).none() && left[0] && left[1] && left[2])
        {
            ans += t[0] + t[1] + t[2];
            break;
        }
        if(flag == 1)
        {
            left[0] = 0;
            left[1] = 0;
            ans += t[1];
            flag = 2;
        }
        else if(flag == 2)
        {
            left[0] = 1;
            ans += t[0];
            flag = 3;
        }
        else if(flag == 3)
        {
            while(nowmax >= 0 && left[nowmax] == 0)
            {
                nowmax--;
            }

            left[nowmax] = 0;
            ans += t[nowmax];

            if(left.none())
                break;

            while(nowmax >= 0 && left[nowmax] == 0)
            {
                nowmax--;
            }

            left[nowmax] = 0;
            flag = 4;
        }
        else
        {
            left[1] = 1;
            ans += t[1];
            flag = 1;
        }
    }

    cout << ans;
}
