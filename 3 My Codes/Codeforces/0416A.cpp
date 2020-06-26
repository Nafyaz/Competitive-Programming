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
    ll n, l, r, v;
    string a, b;
    cin >> n;

    l = -2000000000, r = 2000000000;
    while(n--)
    {
        cin >> a >> v >> b;
        if(a == ">" && b == "Y" || a == "<=" && b == "N")
            l = max(l, v+1);
        if(a == ">" && b == "N" || a == "<=" && b == "Y")
            r = min(r, v);
        if(a == ">=" && b == "Y" || a == "<" && b == "N")
            l = max(l, v);
        if(a == ">=" && b == "N" || a == "<" && b == "Y")
            r = min(r, v-1);

        if(l > r)
        {
            cout << "Impossible";
            return 0;
        }
    }

    cout << (l+r)/2;
}
