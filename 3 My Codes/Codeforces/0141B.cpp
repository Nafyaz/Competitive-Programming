#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define ll long long
#define ff first
#define ss second

int main()
{
    int a, x, y;
    cin >> a >> x >> y;
    if(y%a == 0)
    {
        cout << -1;
        return 0;
    }
    int step = y/a;

    if(step == 0 || step&1)
    {
        if(a <= 2*abs(x))
            cout << -1;
        else if(step == 0)
            cout << 1;
        else
            cout << step/2*3 + 2;
    }

    else
    {
        if(x == 0 || a <= abs(x))
            cout << -1;
        else
            cout << (x > 0 ? step/2*3+1: step/2*3);
    }
}
