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
    ll x, y, d;
    cin >> x >> y;

    if((5*y - 3*x)%2 == 0)
    {
        d = (5*y - 3*x)/2;
        if(x > d && y > d && d >= 0)
            cout << x - d << " " << y - d;
        else
            cout << "Not possible";
    }
    else
        cout << "Not possible";
}
