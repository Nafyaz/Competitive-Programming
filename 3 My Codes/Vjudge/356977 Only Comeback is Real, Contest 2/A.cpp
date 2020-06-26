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
    int n, t, a, b;
    string s;
    map<pair<int, int>, string> mp;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> s;
        mp[{a, b}] = s;
    }

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << mp[{a, b}] << endl;
    }
}

