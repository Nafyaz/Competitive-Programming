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

#define pi acos(-1)

int main()
{
    long double n, s, r;
    cin >> n >> s;

    r = s/2/sin(pi/n);
    cout << fixed;
    cout << setprecision(8) << pi*r*r;
}