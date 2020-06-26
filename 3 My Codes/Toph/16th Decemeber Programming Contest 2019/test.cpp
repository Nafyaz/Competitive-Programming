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
    vector <int> v(5);

    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    v[4] = 5;

    cout << upper_bound(v.begin(), v.end(), 3) - v.begin();

}
