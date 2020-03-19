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

bitset<32> b[200009];

int main()
{
    int q, x, mx;
    string s;
    map<int, int> mp;
    mp[0]++;
    cin >> q;
    while(q--)
    {
        cin >> s >> x;
        if(s == "+")
            mp[x]++;
        if(s == "-")
            mp[x]--;
        if(mp[x] == 0)
            mp.erase(x);

        if(s == "?")
        {
            mx = INT_MIN;
            for(auto u : mp)
                mx = max(mx, u.ff^x);
            cout << mx << endl;
        }
    }
}
