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
    int i, r, x, y, ans = 0;
    cin >> r;

    cin >> x >> y;
    for(i = 1; i <= 10; i++)
    {
        if(r*i*r*i >= x*x+y*y)
        {
            ans += (10 - i + 1);
            break;
        }
    }

    cin >> x >> y;
    for(i = 1; i <= 10; i++)
    {
        if(r*i*r*i >= x*x+y*y)
        {
            ans += (10 - i + 1);
            break;
        }
    }

    cin >> x >> y;
    for(i = 1; i <= 10; i++)
    {
        if(r*i*r*i >= x*x+y*y)
        {
            ans += (10 - i + 1);
            break;
        }
    }

    cout << ans;
}
