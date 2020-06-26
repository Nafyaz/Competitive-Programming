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
    map<int, int> mp;
    mp[1] = 123;
    mp[3] = 21412;
    mp[5] = 12;
    mp[10] = 1;

//    mp.erase(3);

    ordered_set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(10);
    cout << *lower_bound(s.begin(), s.end(), 3);
}
